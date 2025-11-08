#include<stdio.h>
#include<string.h>


// Structure of data
typedef struct{

    char orderID[20];
    char cname[500];
    char pname[500];
    char location[500];
    char orderstatus[500];

}order;


// Declaring the variables
FILE *fp;
order customer[500];
int count = 0;
int found = 0;


// Functions Declaration
void addrecord();
void deleterecord();
void updaterecord();
void displayall();
void searchbyid();


// Functions Initialization
void addrecord(){

    // Taking inputs from the user
    printf("\n\n");
    printf("Enter Order ID      : ");
    scanf("%s",customer[count].orderID);
    printf("Enter Customer Name : ");
    scanf("%s",customer[count].cname);
    printf("Enter Product Name : ");
    scanf("%s",customer[count].pname);
    printf("Enter Location      : ");
    scanf("%s",customer[count].location);
    printf("Enter Order Status  : ");
    scanf("%s",customer[count].orderstatus);

    fp = fopen("trackingrecord.txt","a");
    fprintf(fp,"%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n",customer[count].orderID,customer[count].cname,customer[count].pname,customer[count].location,customer[count].orderstatus);

    count++;

}


void displayall(){

    printf("\n\n");
    fp = fopen("trackingrecord.txt","r");
    count = 0;
    while(fscanf(fp,"%s  %s  %s  %s  %s",customer[count].orderID,customer[count].cname,customer[count].pname,customer[count].location,customer[count].orderstatus)==5){
        printf("Order ID      : %s\n",customer[count].orderID);
        printf("Customer Name : %s\n",customer[count].cname);
        printf("Product Name  : %s\n",customer[count].pname);
        printf("Location      : %s\n",customer[count].location);
        printf("Order Status  : %s\n\n",customer[count].orderstatus);
        count++;
    };
    fclose(fp);
    
}


void searchbyid(){

    char id[20];
    found = 0;

    // Taking inputs from the user
    printf("\n\n");
    printf("Enter Order ID  : ");
    scanf("%s",&id);

    fp = fopen("trackingrecord.txt","r");
    count = 0;
    while(fscanf(fp,"%s  %s  %s  %s  %s",customer[count].orderID,customer[count].cname,customer[count].pname,customer[count].location,customer[count].orderstatus)==5){
        if(strcmp(customer[count].orderID,id)==0){
            found = 1;
            printf("Order ID      : %s\n",customer[count].orderID);
            printf("Customer Name : %s\n",customer[count].cname);
            printf("Product Name  : %s\n",customer[count].pname);
            printf("Location      : %s\n",customer[count].location);
            printf("Order Status  : %s\n\n",customer[count].orderstatus);
            continue;
        }
        count++;
    }
    if(!found){
        printf("\n\nNo Record Found\n");
        printf("Please Check the ID and Enter Again..");
    }
    fclose(fp);

    // fp = fopen("trackingrecord.txt","w");
    // for(int i = 0;i<count;i++){
    //     if(customer[i].orderID == id){
    //         printf("Order ID      : %d\n",customer[i].orderID);
    //         printf("Customer Name : %s\n",customer[i].cname);
    //         printf("location      : %s\n",customer[i].location);
    //         printf("Order Status  : %s\n\n",customer[i].orderstatus);
    //         break;
    //     }
    // }
    // fclose(fp);

}


void updaterecord(){

    char id[20];
    found = 0;
    
    // Taking inputs from the user
    printf("\n\n");
    printf("Enter Order ID  : ");
    scanf("%s",&id);

    // Reading the records from the file
    fp = fopen("trackingrecord.txt","r");
    count = 0;
    while(fscanf(fp,"%s  %s  %s  %s  %s",customer[count].orderID,customer[count].cname,customer[count].pname,customer[count].location,customer[count].orderstatus)==5){
        count++;
    };
    fclose(fp);

    // Updating the required record and adding all to the file
    fp = fopen("trackingrecord.txt","w");
    for(int i = 0;i<count;i++){
        if(strcmp(customer[i].orderID,id)==0){
            found = 1;
            printf("\n\n--ENTER NEW DATA--\n\n");
            printf("Enter Order ID      : ");
            scanf("%s",customer[i].orderID);
            printf("Enter Customer Name : ");
            scanf("%s",customer[i].cname);
            printf("Enter Product Name : ");
            scanf("%s",customer[i].pname);
            printf("Enter Location      : ");
            scanf("%s",customer[i].location);
            printf("Enter Order Status  : ");
            scanf("%s",customer[i].orderstatus);
            fprintf(fp,"%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n",customer[i].orderID,customer[i].cname,customer[i].pname,customer[i].location,customer[i].orderstatus);
            continue;
        }
         fprintf(fp,"%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n",customer[i].orderID,customer[i].cname,customer[i].pname,customer[i].location,customer[i].orderstatus);
    }
    if(!found){
        printf("\n\nNo Record Found\n");
        printf("Please Check the ID and Enter Again..");
    }
    fclose(fp);

}


void deleterecord(){

    char id[20];
    found = 0;

    // Taking input from the user
    printf("\n\n");
    printf("Enter Order ID  : ");
    scanf("%s",&id);

    // Reading the records from the file
    fp = fopen("trackingrecord.txt","r");
    count = 0;
    while(fscanf(fp,"%s  %s  %s  %s  %s",&customer[count].orderID,customer[count].cname,customer[count].pname,customer[count].location,customer[count].orderstatus)==5){
        count++;
    };
    fclose(fp);

    // Deleting the unwanted record and adding all to the file
    fp = fopen("trackingrecord.txt","w");
    for(int i = 0;i<count;i++){
        if(strcmp(customer[i].orderID,id)==0){
            found = 1;
            printf("Record is Deleted Successfully");
            continue;
        }
         fprintf(fp,"%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n",customer[i].orderID,customer[i].cname,customer[i].pname,customer[i].location,customer[i].orderstatus);
    }
    if(!found){
        printf("\n\nNo Record Found\n");
        printf("Please Check the ID and Enter Again..");
    }
    fclose(fp);

}


typedef enum{add=1,update,delete,display,search,exit}track;

int main(){

   
    // To know how can i help the user
    track type;

    // User Manual
    printf("\n\n--WELCOME TO THE ORDER TRACKING MANAGEMENT SYSTEM--\n");
    printf("       \t---HOW CAN I HELP YOU---\n\n");
    printf("To Add a Record               --> 1\n");
    printf("To Update the existing Record --> 2\n");
    printf("To Delete a Record            --> 3\n");
    printf("To Display all the Record     --> 4\n");
    printf("To Search for a Record by ID  --> 5\n");
    printf("To Exit                       --> 6\n\n");

    // User Input
    printf("Enter your choice : ");
    scanf("%d",&type);

    // Locater of the operations to perform using switch statement
    switch(type){

        case 1:
        addrecord();
        break;

        case 2:
        updaterecord();
        break;

        case 3:
        deleterecord();
        break;

        case 4:
        displayall();
        break;

        case 5:
        searchbyid();
        break;

        case 6:
        printf("Thank You..\n Visit Again");
        break;

        default:
        printf("Sorry!.. For the inconvenience\n Please check the input you entered.. ");
        break;
    }

}
