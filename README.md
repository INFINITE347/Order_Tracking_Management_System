# 📦 Order Tracking Management System (C Language)

A C-language based Order Tracking Management System using file handling. Supports add, update, delete, display, and search operations with permanent data storage.


A menu-driven **Order Tracking Management System** built in C.  
This project performs CRUD operations (Create, Read, Update, Delete) using **File Handling**, and stores records permanently in `trackingrecord.txt`.

---

## ✅ Features

| Operation | Function Name | Description |
|----------|----------------|-------------|
| ➕ Add Record | addrecord() | Add a new order into the text file |
| ✏️ Update Record | updaterecord() | Modify an existing order by Order ID |
| ❌ Delete Record | deleterecord() | Remove an order from file |
| 📄 Display All Records | displayall() | Show all orders stored in the file |
| 🔍 Search by Order ID | searchbyid() | Find a specific order |

All records remain saved even after the program exits.

---

## 🛠️ C Concepts Used

| Concept | Usage |
|---------|-------|
| struct | Store multiple attributes of a record |
| File Handling (fopen, fclose, fprintf, fscanf) | Save and retrieve records from file |
| strcmp() | Compare Order IDs while searching/updating/deleting |
| Arrays of Structures | Temporarily hold all records for update/delete |
| Functions | Organize code into modular operations |
| switch-case | Menu-driven program execution |
| enum (optional) | Assigns names to menu values |
| fgets() (optional enhancement) | Allows multi-word names like "Apple iPhone 15" |

---

## 📂 Data Structure Used

typedef struct {
char orderID[20];
char cname[500];
char pname[500];
char location[500];
char orderstatus[500];
} order;


---

## 🔧 How Each Operation Works

### ➕ Add Record (addrecord)
- Takes Order ID, Customer Name, Product Name, Location, Status
- Opens file in append mode ("a")
- Stores data using fprintf()

### 📄 Display All Records (displayall)
- Opens file in read mode ("r")
- Reads each record using fscanf()
- Prints them in proper format

### 🔍 Search by Order ID (searchbyid)
- Reads file line by line
- Uses strcmp() to match given Order ID
- Displays record if found

### ✏️ Update Record (updaterecord)
- Reads all records into an array
- Locates matching Order ID
- Updates only the selected record
- Opens file in write mode ("w") and rewrites updated list

### ❌ Delete Record (deleterecord)
- Reads all records into an array
- Skips the record with matching Order ID
- Writes remaining records back to file

---

## ✏️ Allow Multi-word Input (optional improvement)

Replace scanf() with:


---

## 🔮 Future Enhancements

| Enhancement | Benefit |
|-------------|---------|
| Prevent duplicate Order IDs | Data validation |
| Export to CSV / Database | Better storage |
| Loop menu continuously | Improved usability |
| Add terminal UI colors | Enhanced visuals |

---

## 📄 License

Distributed under the **MIT License**.

---

## ✨ Author

**RADHESH REDDY YARRAM**

