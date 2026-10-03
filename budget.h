#ifndef BUDGET_H
#define BUDGET_H

//storing department info in a struct
struct Department {
    char name[100];
    double budget;
    double expenditure;
    double remainingBudget;
    char status[50];
};

// Funtions 
void budgetMenu(); 
struct Department addDepartmentBudget(void);
void budgetReports(struct Department departments[], int deptCount);

#endif
