#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100
#define NAME_LEN   50

void   assetMenu(void);          /* called from main menu option 4 */
void   addAsset(void);
void   displayAssets(void);
void   searchAsset(void);
void   displayAssetReport(void); /* called by Reports (Student 5) */
int    getAssetCount(void);
double getTotalAssetValue(void);

#endif
