#include <stdio.h>
#include <string.h>
#include "employee.h"
#define MAX_EMP 100 

char employeeId[MAX_EMP][20];
char employeeName[MAX_EMP][100];
char department[MAX_EMP][300];
double basicSalary[MAX_EMP];
double housingAllowance[MAX_EMP];
double transportAllowance[MAX_EMP];
char employeeEmail[MAX_EMP][30];
char employeePhoneNumber[MAX_EMP][30];
int empCount = 0;
int i= 0;
int choice;
char searchEmployeeId[20];
double totalSalary =0;

void employeeMenu(){
int choice;

do{
printf(" Employee Management:\n");

printf("1.Add employee\n");
printf("2.Display Employees\n");
printf("3.Search for Employee\n");
printf("4.Calculate Salary\n");
printf("5.Exit\n");
printf("\n---------------------------------------------------\n");

printf("Enter Choice:\n");
scanf("%d", &choice);

switch(choice){
    case 1:
    addEmployee();
    break;

   case 2: 
    displayEmployee();
    break;

    case 3:
    searchEmployee();
    break;

    case 4: 
    calculateSalary();
    break;

    case 5:
    printf("Back to Menu.\n");
    break;

    default:
     printf("Invalid choice. Choose a number between 1 - 4.\n");
}
}
while (choice != 5);
}

void addEmployee(){

    if (empCount >= MAX_EMP){
       printf("The list is full.\n");
       return;
    }
    getchar();

    printf("Enter Employee Name:\n");
    fgets(employeeName[empCount], sizeof(employeeName[empCount]), stdin );

    printf("Enter Employee ID:\n");
    fgets(employeeId[empCount], sizeof(employeeId[empCount]), stdin);

    printf("Enter Employee's Department:\n");
    fgets(department[empCount], sizeof(department[empCount]), stdin);

    printf("Enter Employee's Basic Salary:\n");
    scanf("%lf", &basicSalary[empCount]);

    printf("Enter Employee's Housing Allowance\n");
    scanf("%lf", &housingAllowance[empCount]);

    printf("Enter Employee's transport allowance:\n");
   scanf("%lf", &transportAllowance[empCount]);

   getchar();

    printf("Enter Employee's email:\n");
    fgets(employeeEmail[empCount], sizeof(employeeEmail[empCount]), stdin);



    printf("Enter Employee's Phone number:\n");
    fgets(employeePhoneNumber[empCount], sizeof(employeePhoneNumber[empCount]), stdin);

    empCount++;
   
}

void displayEmployee(void){
    if (empCount == 0){
        printf("No Employees have been added.\n");
        return;
    }

    for (i=0; i<empCount; i++){
        printf("\n-------------------------------\n");
        printf("Employee %d\n", i + 1);
        printf("-------------------------------\n");

        printf("Name: %s", employeeName[i]);
        printf("Employee ID: %s", employeeId[i]);
        printf("Department: %s", department[i]);

        printf("Basic Salary: %.2f\n", basicSalary[i]);
        printf("Housing Allowance: %.2f\n", housingAllowance[i]);
        printf("Transport Allowance: %.2f\n", transportAllowance[i]);

        printf("Email: %s", employeeEmail[i]);
        printf("Phone Number: %s", employeePhoneNumber[i]);
       
    }

void searchEmployee(void);{
    int found= 0;

     printf("Enter Employee ID:\n");
     fgets(searchEmployeeId, sizeof(searchEmployeeId), stdin);

     for(i=0; i<empCount; i++){


     if(strcmp(searchEmployeeId, employeeId[i]) == 0){
        found = 1;
       printf("Name: %s", employeeName[i]);
        printf("Employee ID: %s", employeeId[i]);
        printf("Department: %s", department[i]);

        printf("Basic Salary: %.2f\n", basicSalary[i]);
        printf("Housing Allowance: %.2f\n", housingAllowance[i]);
        printf("Transport Allowance: %.2f\n", transportAllowance[i]);

        printf("Email: %s", employeeEmail[i]);
        printf("Phone Number: %s", employeePhoneNumber[i]);
        break;
     }
     if (found == 0)
    {
        printf("Employee not found.\n");
    }
    

}

double calculateSalary(void);{
     printf("Enter Employee ID:\n");
     fgets(searchEmployeeId, sizeof(searchEmployeeId), stdin);

     for(i=0; i<empCount; i++){
         if(strcmp(searchEmployeeId, employeeId[i]) == 0){
        found = 1;

       totalSalary = basicSalary[i]
                        + housingAllowance[i]
                        + transportAllowance[i];

                        printf("\n-------------------------------\n");
            printf("Salary Details\n");
            printf("-------------------------------\n");

            printf("Employee Name: %s", employeeName[i]);
            printf("Employee ID: %s", employeeId[i]);

            printf("Basic Salary: %.2f\n", basicSalary[i]);
            printf("Housing Allowance: %.2f\n", housingAllowance[i]);
            printf("Transport Allowance: %.2f\n", transportAllowance[i]);
            printf("Total Salary: %.2f\n", totalSalary);

            break;
        }
    }

    if (found == 0)
    {
        printf("Employee not found.\n");
    }
}

}

}

