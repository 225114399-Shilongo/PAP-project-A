#include <stdio.h>
#include "employee.h"
#include "budget.h"
#include "supplier.h"
#include "assets.h"
#include "report.h"


void displayMenu(void);
int getMenuChoice(void);
void handleMenuChoice(int choice);


int main(void)
{
    int choice;

    do
    {
        displayMenu();

        choice = getMenuChoice();

        handleMenuChoice(choice);

    } while (choice != 6);

    printf("\nThank you for using the Municipal Financial Management System.\n");

    return 0;
}




void displayMenu(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("========================================\n");
}

int getMenuChoice(void)
{
    int choice;

    printf("Enter your choice: ");

    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 6)
    {
        printf("Invalid input. Please enter a number: ");

        while (getchar() != '\n')
        {
            /* Clear invalid input */
        }
    }
return choice;
}

void handleMenuChoice(int choice)
{
    switch (choice)
    {
        case 1:
            employeeMenu();
            break;

        case 2:
            budgetMenu();
            break;

        case 3:
            supplierMenu();
            break;

        case 4:
            assetMenu();
            break;

        case 5:
            displayReports();
            break;

        case 6:
            printf("\nExiting system...\n");
            break;

        default:
            printf("Please enter a valid option.\n");
    }
}
