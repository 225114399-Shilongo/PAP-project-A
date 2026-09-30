#include <stdio.h>
#include "employee.h"
int main(void){
    int choice;

    printf("------------------------------------------------\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("-----------------------------------------------\n");

    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");

    printf("Enter your choice:\n\n");
  
    scanf("%d", &choice);
    

    if (choice == 1)
{
    employeeMenu();
}

  return 0;  
}
