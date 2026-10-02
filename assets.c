#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assets.h"


static int    assetId[MAX_ASSETS];
static char   assetName[MAX_ASSETS][NAME_LEN];
static char   assetType[MAX_ASSETS][NAME_LEN];
static double assetValue[MAX_ASSETS];
static char   assetDept[MAX_ASSETS][NAME_LEN];
static char   assetCondition[MAX_ASSETS][NAME_LEN];
static int    assetCount = 0;

static const char *TYPES[] = {"Vehicle", "Computer", "Building", "Equipment", "Furniture"};
static const char *CONDITIONS[] = {"Good", "Fair", "Poor", "Needs Repair"};


static void readLine(const char *prompt, char *buf, int size)
{
    printf("%s", prompt);
    if (fgets(buf, size, stdin) == NULL) { buf[0] = '\0'; return; }
    buf[strcspn(buf, "\n")] = '\0';
}

static void readNonEmpty(const char *prompt, char *buf, int size)
{
    do {
        readLine(prompt, buf, size);
        if (strlen(buf) == 0)
            printf("  Error: this field cannot be empty.\n");
    } while (strlen(buf) == 0);
}

static int readIntRange(const char *prompt, int min, int max)
{
    char line[64], *end;
    long v;
    while (1) {
        readLine(prompt, line, sizeof line);
        v = strtol(line, &end, 10);
        if (end != line && *end == '\0' && v >= min && v <= max)
            return (int)v;
        printf("  Error: enter a whole number from %d to %d.\n", min, max);
    }
}

static double readPositiveDouble(const char *prompt)
{
    char line[64], *end;
    double v;
    while (1) {
        readLine(prompt, line, sizeof line);
        v = strtod(line, &end);
        if (end != line && *end == '\0' && v > 0)
            return v;
        printf("  Error: enter a number greater than 0.\n");
    }
}

static int findAssetById(int id)
{
    for (int i = 0; i < assetCount; i++)
        if (assetId[i] == id) return i;
    return -1;
}

static void printAssetRow(int i)
{
    printf("%-6d %-20s %-10s N$%-12.2f %-12s %-12s\n",
           assetId[i], assetName[i], assetType[i],
           assetValue[i], assetDept[i], assetCondition[i]);
}

static void printHeader(void)
{
    printf("%-6s %-20s %-10s %-15s %-12s %-12s\n",
           "ID", "Name", "Type", "Value", "Department", "Condition");
    printf("--------------------------------------------------------------------------------\n");
}

/* ---------- main features ---------- */
void addAsset(void)
{
    if (assetCount >= MAX_ASSETS) {
        printf("Asset register is full.\n");
        return;
    }
    int id = readIntRange("Asset ID (1-99999): ", 1, 99999);
    if (findAssetById(id) != -1) {
        printf("Error: Asset ID %d already exists.\n", id);
        return;
    }
    int n = assetCount;
    assetId[n] = id;
    readNonEmpty("Asset name: ", assetName[n], NAME_LEN);

    printf("Types: 1.Vehicle 2.Computer 3.Building 4.Equipment 5.Furniture\n");
    strcpy(assetType[n], TYPES[readIntRange("Choose type (1-5): ", 1, 5) - 1]);

    assetValue[n] = readPositiveDouble("Purchase value (N$): ");
    readNonEmpty("Department: ", assetDept[n], NAME_LEN);

    printf("Condition: 1.Good 2.Fair 3.Poor 4.Needs Repair\n");
    strcpy(assetCondition[n], CONDITIONS[readIntRange("Choose condition (1-4): ", 1, 4) - 1]);

    assetCount++;
    printf("Asset added successfully.\n");
}

void displayAssets(void)
{
    if (assetCount == 0) { printf("No assets registered.\n"); return; }
    printHeader();
    for (int i = 0; i < assetCount; i++) printAssetRow(i);
}

void searchAsset(void)
{
    int found = 0;
    int choice = readIntRange("Search by: 1.ID  2.Name  3.Department : ", 1, 3);

    if (choice == 1) {
        int i = findAssetById(readIntRange("Enter Asset ID: ", 1, 99999));
        if (i != -1) { printHeader(); printAssetRow(i); found = 1; }
    } else {
        char key[NAME_LEN];
        readNonEmpty("Enter search text: ", key, NAME_LEN);
        for (int i = 0; i < assetCount; i++) {
            const char *field = (choice == 2) ? assetName[i] : assetDept[i];
            if (strstr(field, key) != NULL) {
                if (!found) printHeader();
                printAssetRow(i);
                found = 1;
            }
        }
    }
    if (!found) printf("No matching asset found.\n");
}

int getAssetCount(void) { return assetCount; }

double getTotalAssetValue(void)
{
    double total = 0;
    for (int i = 0; i < assetCount; i++) total += assetValue[i];
    return total;
}

void displayAssetReport(void)
{
    printf("\n===== ASSET REPORT =====\n");
    printf("Total assets: %d\n", assetCount);
    printf("Total value : N$%.2f\n\n", getTotalAssetValue());
    displayAssets();
}

void assetMenu(void)
{
    int choice;
    do {
        printf("\n--- ASSET MANAGEMENT ---\n");
        printf("1. Add asset\n2. Display assets\n3. Search asset\n4. Back\n");
        choice = readIntRange("Enter your choice: ", 1, 4);
        switch (choice) {
            case 1: addAsset();      break;
            case 2: displayAssets(); break;
            case 3: searchAsset();   break;
            case 4: break;
        }
    } while (choice != 4);
}
