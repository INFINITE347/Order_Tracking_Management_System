# 📦 Order Tracking Management System (C Language)

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)
![Status](https://img.shields.io/badge/Project-Active-brightgreen.svg)

A C-language based **Order Tracking Management System** using file handling.  
Supports Add, Update, Delete, Display, and Search operations with permanent data storage in `trackingrecord.txt`.

This is a menu-driven project performing CRUD operations (Create, Read, Update, Delete) using **File Handling**, arrays of structures, and modular functions.

---

## ✅ Features

| Operation | Function Name | Description |
|----------|----------------|-------------|
| ➕ Add Record | addrecord() | Add a new order into the text file |
| ✏️ Update Record | updaterecord() | Modify an existing order by Order ID |
| ❌ Delete Record | deleterecord() | Remove an order from the file |
| 📄 Display All Records | displayall() | Show all orders stored in the file |
| 🔍 Search by Order ID | searchbyid() | Find a specific order |

All records remain **saved permanently** even after exiting the program.

---

## 🛠️ C Concepts Used

| Concept | Usage |
|---------|-------|
| struct | Store multiple attributes of a record |
| File Handling (`fopen`, `fclose`, `fprintf`, `fscanf`) | Save and retrieve records from file |
| strcmp() | Compare Order IDs while searching/updating/deleting |
| Arrays of Structures | Temporarily hold all records during update/delete |
| switch-case | Menu-based program execution |
| Functions | Modularize code for readability and reusability |
| enum | Assign names to menu options |
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

### ➕ addrecord()
- Takes Order ID, Customer Name, Product Name, Location, Order Status.
- Opens `trackingrecord.txt` in append mode (`"a"`).
- Adds the record into the file using `fprintf()`.

### 📄 displayall()
- Opens the text file in read mode.
- Reads every record using `fscanf()`.
- Prints each record on console.

### 🔍 searchbyid()
- User enters Order ID.
- Program compares each stored ID using `strcmp()`.
- Prints matching record.

### ✏️ updaterecord()
- Reads all data into an array.
- Finds required record using matching ID.
- Allows modifying all values of that record.
- Rewrites all records back into the text file.

### ❌ deleterecord()
- Reads all data into an array.
- Skips the matched record (deletes it).
- Rewrites remaining records back into file.

---


## 🚀 How to Run
Using GCC (Terminal)

gcc main.c -o ordertracking
./ordertracking

## 📊 Program Flowchart

               ┌──────────────────────────┐
               │       Start Program       │
               └───────────────┬──────────┘
                               │
                               ▼
                   ┌─────────────────────┐
                   │    Display Menu      │
                   └───────────┬─────────┘
                               │
                               ▼
                 ┌─────────────┼─────────────┐
                 ▼             ▼             ▼
              Add Record     Update Record   Delete Record
              (addrecord)    (updaterecord) (deleterecord)
                 │             │             │
                 ▼             ▼             ▼
             Display All      Search by ID    Exit
             (displayall)    (searchbyid)

🔮 Future Enhancements

| Enhancement                 | Benefit                                                 |
| --------------------------- | ------------------------------------------------------- |
| Prevent duplicate Order IDs | Data validation and uniqueness                          |
| Export to CSV / Database    | Improved storage and analytics                          |
| Loop menu continuously      | User can perform multiple operations without restarting |
| Terminal UI colors          | Improved visuals and user experience                    |


📄 License

Distributed under the MIT License.
You are free to use, modify, and distribute with proper credit.


