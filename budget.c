#include <stdio.h>
#include <string.h>
#include "budget.h"


void budgetMenu() {
    struct Department departments[20];
    int deptCount = 0;
    int option;

//Budget Menu displaying options
    do {
        printf("\n==== Budget Management ====\n");
        printf("1. Add New Department Budget\n");
        printf("2. Reports\n");
        printf("3. Exit\n\n");
        printf("Enter your selection: \n");
        scanf(" %d", &option);

        switch(option){
            case 1:
                departments[deptCount] = addDepartmentBudget();
                deptCount++;
                break;
            case 2:
                budgetReports(departments, deptCount);
                break;
            case 3:
                printf("\nReturning to Main Menu");
                break;
        }
    }while(option !=3);
}

struct Department addDepartmentBudget(void) {
    struct Department newDept;
    int ch;

    printf("Department Name: ");
    // Clear input buffer
    while ((ch = getchar()) != '\n' && ch != EOF); 
    
    fgets(newDept.name, sizeof(newDept.name), stdin);
    // Strip trailing newline from input
    newDept.name[strcspn(newDept.name, "\n")] = '\0'; 

    // Data Validation
    do {
        printf("Enter Department Budget: \n");
        scanf(" %lf", &newDept.budget);
        if (newDept.budget < 0) {
            printf("Budget cannot be negative!\n");
        }
    } while (newDept.budget < 0);

    do {
        printf("Enter Department Expenditure: \n");
        scanf(" %lf", &newDept.expenditure);
        if (newDept.expenditure < 0) {
            printf("Expenditure cannot be negative!\n");
        }
    } while (newDept.expenditure < 0);

    //calculate remaining balance
    newDept.remainingBudget = newDept.budget - newDept.expenditure;

    if (newDept.expenditure > newDept.budget) {
        strcpy(newDept.status, "Exceeded Budget");
    } else {
        strcpy(newDept.status, "Within Budget");
    }

    printf("Department has been added successfully!\n");
    
    
    return newDept; 
}

//Budget Reports function
void budgetReports(struct Department departments[], int deptCount) {
    int i;

    if (deptCount == 0) {
        printf("\nNo budget data available to report.\n");
        return;
    }

    double totalBudget = 0;
    double totalExpenditure = 0;

        printf("\n================ BUDGET REPORT ================\n");
        for (i = 0; i < deptCount; i++) {
            printf("Department: %s\n", departments[i].name);
            printf("Department Budget: N$ %.2lf\n", departments[i].budget);
            printf("Department Expenditure: N$ %.2lf\n", departments[i].expenditure);
            printf("Remaining Budget: N$ %.2lf\n", departments[i].remainingBudget);
            printf("Status: %s\n\n", departments[i].status);

            totalBudget += departments[i].budget;
            totalExpenditure += departments[i].expenditure;

            if (departments[i].expenditure > departments[i].budget) {
                printf("\nDepartments Exceeded Budget\n");
                printf("%s Department\n\n", departments[i].name);
            }
        }

    printf("-------------------------------\n");
    printf("Total Organisation Budget: N$ %.2lf\n", totalBudget);
    printf("Total Organisation Expenditure: N$ %.2lf\n", totalExpenditure);
    printf("Total Remaining Balance: N$ %.2lf\n", totalBudget - totalExpenditure);
    printf("-------------------------------\n");
}