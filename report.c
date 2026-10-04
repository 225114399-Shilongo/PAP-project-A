#include <stdio.h>
#include <string.h>
#include "report.h"
#include "budget.h"
#include "assets.h"

/* ============================================================
 * REPORTS MODULE
 * PAP521S Project A - Municipal Financial Management System
 * ============================================================ */

/* ---------- Employee data (global in employee.c) ---------- */
#define MAX_EMP 100

extern char   employeeName[MAX_EMP][100];
extern char   employeeId[MAX_EMP][20];
extern char   department[MAX_EMP][300];
extern double basicSalary[MAX_EMP];
extern double housingAllowance[MAX_EMP];
extern double transportAllowance[MAX_EMP];
extern char   employeeEmail[MAX_EMP][30];
extern char   employeePhoneNumber[MAX_EMP][30];
extern int    empCount;

/* ---------- Supplier placeholder (until supplier.c exists) ---------- */
#define SAMPLE_SUPPLIER_COUNT   3
static int  supplierIDs[SAMPLE_SUPPLIER_COUNT]        = { 101, 102, 103 };
static char supplierNames[SAMPLE_SUPPLIER_COUNT][50]  = { "Namib Supplies", "Windhoek Traders", "Katutura Hardware" };
static char supplierEmails[SAMPLE_SUPPLIER_COUNT][50] = { "info@namibsupplies.na", "sales@windhoektraders.na", "info@katuturahardware.na" };
static char supplierPhones[SAMPLE_SUPPLIER_COUNT][20] = { "0811234567", "0812345678", "0813456789" };
static char supplierTowns[SAMPLE_SUPPLIER_COUNT][50]  = { "Windhoek", "Windhoek", "Katutura" };

/* ---------- Budget placeholder (until budget data is global) ---------- */
#define SAMPLE_BUDGET_COUNT     3

static void reportEmployee(void)
{
    printf("\n========================================\n");
    printf("         EMPLOYEE REPORT\n");
    printf("========================================\n");

    if (empCount == 0)
    {
        printf("No employees registered in the system.\n");
        printf("========================================\n");
        return;
    }

    double total   = 0.0;
    double highest = basicSalary[0];
    double lowest  = basicSalary[0];

    for (int j = 0; j < empCount; j++)
    {
        total += basicSalary[j];
        if (basicSalary[j] > highest) highest = basicSalary[j];
        if (basicSalary[j] < lowest)  lowest  = basicSalary[j];
    }

    printf("Total Employees : %d\n", empCount);
    printf("Average Salary  : N$%.2f\n", total / empCount);
    printf("Highest Salary  : N$%.2f\n", highest);
    printf("Lowest Salary   : N$%.2f\n", lowest);
    printf("========================================\n");
}

static void reportBudget(void)
{
    struct Department sample[3] = {
        { "Finance",      500000.0, 420000.0, 80000.0,  "WITHIN BUDGET" },
        { "Public Works", 300000.0, 350000.0, -50000.0, "OVER BUDGET"   },
        { "Health",       450000.0, 400000.0, 50000.0,  "WITHIN BUDGET" }
    };

    double totalAllocated   = 0.0;
    double totalExpenditure = 0.0;

    printf("\n========================================\n");
    printf("          BUDGET REPORT\n");
    printf("========================================\n");

    for (int j = 0; j < SAMPLE_BUDGET_COUNT; j++)
    {
        totalAllocated   += sample[j].budget;
        totalExpenditure += sample[j].expenditure;
    }

    printf("Total Allocated   : N$%.2f\n", totalAllocated);
    printf("Total Expenditure : N$%.2f\n", totalExpenditure);
    printf("Remaining Budget  : N$%.2f\n", totalAllocated - totalExpenditure);
    printf("----------------------------------------\n");
    printf("Departments Exceeding Budget:\n");

    int over = 0;
    for (int j = 0; j < SAMPLE_BUDGET_COUNT; j++)
    {
        if (sample[j].expenditure > sample[j].budget)
        {
            printf("  - %s (over by N$%.2f)\n",
                   sample[j].name,
                   sample[j].expenditure - sample[j].budget);
            over++;
        }
    }
    if (over == 0)
        printf("  (None - all departments within budget)\n");

    printf("========================================\n");
}

static void reportSupplier(void)
{
    printf("\n========================================\n");
    printf("          SUPPLIER REPORT\n");
    printf("========================================\n");

    printf("%-6s %-20s %-25s %-15s %-15s\n",
           "ID", "Name", "Email", "Phone", "Town");
    printf("--------------------------------------------------------------------------------\n");

    for (int j = 0; j < SAMPLE_SUPPLIER_COUNT; j++)
    {
        printf("%-6d %-20s %-25s %-15s %-15s\n",
               supplierIDs[j], supplierNames[j], supplierEmails[j],
               supplierPhones[j], supplierTowns[j]);
    }

    printf("--------------------------------------------------------------------------------\n");
    printf("Total Suppliers: %d\n", SAMPLE_SUPPLIER_COUNT);
    printf("========================================\n");
}

static void reportAsset(void)
{
    displayAssetReport();
}

void displayReports(void)
{
    int subChoice;

    do
    {
        printf("\n");
        printf("========================================\n");
        printf("           REPORTS MENU\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. All Reports\n");
        printf("6. Back to Main Menu\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &subChoice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (subChoice)
        {
            case 1: reportEmployee(); break;
            case 2: reportBudget();   break;
            case 3: reportSupplier(); break;
            case 4: reportAsset();    break;
            case 5:
                reportEmployee();
                reportBudget();
                reportSupplier();
                reportAsset();
                break;
            case 6:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please select 1-6.\n");
        }

    } while (subChoice != 6);
}
