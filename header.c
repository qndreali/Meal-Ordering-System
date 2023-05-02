/******************************************************************************************************
 * * Preprocessor Directives for Header Files.
 * + stdio.h    - standard input/output functions, used printf and scanf.
 * + string.h   - string manipulation functions, used memcpy.
 * + stdlib.h   - standard library functions, used getchar, srand and rand.
 * + time.h     - time and date manipulation, used time.
******************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/******************************************************************************************************
 * * Preprocessor Directives Definitions for Extended ASCII Values used for the Menu GUI. 
 * ! The Extended ASCII Character Set is not supported by all operating systems and character encoding, 
 *   which can result in unexpected behavior when displaying text containing these characters.
******************************************************************************************************/
#define HLINE 		205
#define VLINE 		186
#define TLCORNER 	201
#define TRCORNER 	187
#define BLCORNER 	200
#define BRCORNER 	188
#define HDLINE		203
#define HULINE		202
#define VRLINE		185
#define VLLINE		204
#define VHLINE		206

#define TBRCORNER	217
#define TBLCORNER	192
#define TTRCORNER	191
#define TTLCORNER	218
#define THLINE 		196
#define TVLINE 		179

/******************************************************************************************************
 * * A struct declaration for struct 'meal'. 
 * + This is used to store the food item's names as a string.
******************************************************************************************************/
struct meal {
        char main[10];
        char side[20];
        char drink[15];
};

/******************************************************************************************************
 * * A struct declaration for struct 'value'. 
 * + This is used to store the product prices=.
******************************************************************************************************/
struct value {
        float main;
        float side;
        float drink;
};

/******************************************************************************************************
 * * A struct declaration for struct 'order'. 
 * + This is used to store the user's orders.
******************************************************************************************************/
struct order {
        int main;
        int side;
        int drink;
};

/******************************************************************************************************
 *                             * Function Prototypes for all functions used.
******************************************************************************************************/
// + Header Functions
void displayProduct(struct meal product[]);
void initializePrices(struct value *price);
void reloadMenu(struct order *random, struct meal product[]);

// + Display Functions [Purely Decorational]
void printLine(char left, char mid, char right, int length);
void displayGreeting();
void displayMenuDivider(char left, char mid, char right);
void displayMenu();
void displayMOSTDDivider(char left,	char mid, char right);
void displayMSOTD(struct order *random, struct meal product[]);
void displayMSOTDMessage();
void displayReceiptLine(char left, char mid, char right, int length);
void displayReceiptHeader();
void displayReceiptFooter();

// + Feature Functions
int inputOrderingOption(int *pOrderOption);
void inputOrder(struct order *meal, struct meal product[], int nOrderNumber);
void inputMealSetOfTheDay(struct order *random, struct meal product[], int nOrderNumber);
char inputConfirmationOption(char *pConfirmationOption);
float calculateSubtotal(struct order *meal, struct value *price, struct order *random);
float calculateTotal(struct order *meals, int nOrderNumber, struct value *price, struct order *random);
void displayReceipt(struct order *meals, struct meal product[], struct value *price, int nOrderNumber, struct order random);

/******************************************************************************************************
 * @breif: This function initializes an array of pre-defined meals to the product array parameter.
 * @param product: an array of meal structs representing the product names.
******************************************************************************************************/
void displayProduct(struct meal product[]){
        struct meal m[5] = {
                {"None", "None", "None"},
                {"Chicken", "Steamed Rice", "Mineral Water"},
                {"Pork", "Shredded Corn", "Iced Tea"},
                {"Fish", "Mashed Potato", "Soda"},
                {"Beef", "Steam Vegetables", "Fruit Juice"}
        };
        memcpy(product, m, sizeof(m));
}

/******************************************************************************************************
 * @breif: This function initializes an array of pre-defined values to the price array parameter.
 * @param price: pointer to an array of value structures.
******************************************************************************************************/
void initializePrices(struct value *price){
        struct value p[5] = {
                {0.00, 0.00, 0.00},
                {90.00, 20.00, 25.00},
                {105.00, 35.00, 35.00},
                {120.00, 50.00, 45.00},
                {135.00, 65.00, 55.00}
        };
        memcpy(price, p, sizeof(p));
}

/******************************************************************************************************
 * @breif: This function clears the screen and reloads the menu. 
 * @param random: a pointer to a struct order that contains the randomly generated meal set of the day.
 * @param product: an array of meal structs representing the product names.
******************************************************************************************************/
void reloadMenu(struct order *random, struct meal product[]){
	system("cls");
	displayGreeting();
        displayMenu();
        displayMSOTD(random, product);
        displayMSOTDMessage();
}
