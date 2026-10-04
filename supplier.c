#include <stdio.h>
#include <string.h>
 
#define MAX_SUPPLIERS 100

char supplierID[MAX_SUPPLIERS][20];
char supplierName[MAX_SUPPLIERS][50];
char supplierEmail[MAX_SUPPLIERS][50];
char supplierTelephone[MAX_SUPPLIERS][20];
char supplierTown[MAX_SUPPLIERS][30];

int supplierCount = 0;
int i;

void supplierMenu();
void addSupplier();
void displaySuppliers();
void searchSupplier();
void compareSuppliers();

void supplierMenu() {

    int choice;

    do {

        printf("\nSUPPLIER MANAGEMENT\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {

            case 1:
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                compareSuppliers();
                break;

            case 5:
                printf("Back to Main Menu.\n");
                break;

            default:
                printf("Invalid Choice.\n");
        }

    } while(choice != 5);
}

void addSupplier() {

    if(supplierCount >= MAX_SUPPLIERS) {
        printf("Supplier list is full.\n");
        return;
    }

    printf("Enter Supplier ID: ");
    fgets(supplierID[supplierCount],
          sizeof(supplierID[supplierCount]),
          stdin);

    printf("Enter Supplier Name: ");
    fgets(supplierName[supplierCount],
          sizeof(supplierName[supplierCount]),
          stdin);

    printf("Enter Supplier Email: ");
    fgets(supplierEmail[supplierCount],
          sizeof(supplierEmail[supplierCount]),
          stdin);

    printf("Enter Supplier Telephone: ");
    fgets(supplierTelephone[supplierCount],
          sizeof(supplierTelephone[supplierCount]),
          stdin);

    printf("Enter Supplier Town: ");
    fgets(supplierTown[supplierCount],
          sizeof(supplierTown[supplierCount]),
          stdin);

    supplierCount++;

    printf("Supplier added successfully.\n");
}

void displaySuppliers() {

    if(supplierCount == 0) {
        printf("No suppliers available.\n");
        return;
    }

    for(i = 0; i < supplierCount; i++) {

        printf("\nSupplier %d\n", i + 1);

        printf("Supplier ID: %s", supplierID[i]);
        printf("Name: %s", supplierName[i]);
        printf("Email: %s", supplierEmail[i]);
        printf("Telephone: %s", supplierTelephone[i]);
        printf("Town: %s", supplierTown[i]);
    }
}

void searchSupplier() {

    char searchID[20];
    int found = 0;

    printf("Enter Supplier ID: ");
    fgets(searchID, sizeof(searchID), stdin);

    for(i = 0; i < supplierCount; i++) {

        if(strcmp(searchID, supplierID[i]) == 0) {

            found = 1;

            printf("\nSupplier Found\n");

            printf("Supplier ID: %s", supplierID[i]);
            printf("Name: %s", supplierName[i]);
            printf("Email: %s", supplierEmail[i]);
            printf("Telephone: %s", supplierTelephone[i]);
            printf("Town: %s", supplierTown[i]);

            break;
        }
    }

    if(found == 0) {
        printf("Supplier not found.\n");
    }
}

void compareSuppliers() {

    char firstID[20];
    char secondID[20];

    int firstFound = 0;
    int secondFound = 0;

    printf("Enter First Supplier ID: ");
    fgets(firstID, sizeof(firstID), stdin);

    printf("Enter Second Supplier ID: ");
    fgets(secondID, sizeof(secondID), stdin);

    for(i = 0; i < supplierCount; i++) {

        if(strcmp(firstID, supplierID[i]) == 0) {

            firstFound = 1;

            printf("\nFirst Supplier\n");
            printf("Name: %s", supplierName[i]);
            printf("Town: %s", supplierTown[i]);
        }

        if(strcmp(secondID, supplierID[i]) == 0) {

            secondFound = 1;

            printf("\nSecond Supplier\n");
            printf("Name: %s", supplierName[i]);
            printf("Town: %s", supplierTown[i]);
        }
    }

    if(firstFound == 0 || secondFound == 0) {
        printf("One or both suppliers not found.\n");
    }
}

int main() {

    supplierMenu();

    return 0;
}
