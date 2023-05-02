/******************************************************************************************************
 * @breif: This function prints a three-part line of Extended ASCII characters. 
 * @param left: the leftmost character.
 * @param mid: the middle character.
 * @param right: the rightmost character.
 * @param length: the length of the middle character.
******************************************************************************************************/
void printLine(char left, char mid, char right, int length){
	printf("%c", left);
	for(int i = 1; i <= length; i++)
		printf("%c", mid);
	printf("%c", right);	
}

/******************************************************************************************************
 * @breif: This function displays a Greeting Card.
******************************************************************************************************/
void displayGreeting(){
    printf("\e[1;97m");
	printLine(TLCORNER, HLINE, TRCORNER, 117);
	printf("\n%-45c" "\e[0;96m" "Welcome to Andrea's Kitchen !" "\e[1;97m" "%45c\n", VLINE, VLINE);
	printLine(BLCORNER, HLINE, BRCORNER, 117);
}

/******************************************************************************************************
 * @breif:This function displays a Menu Divider to be used in the displayMenu Function.
 * @param left: the leftmost character.
 * @param mid: the middle character.
 * @param right: the rightmost character.
******************************************************************************************************/
void displayMenuDivider(char left, char mid, char right){
	printf("\n");
	for(int i = 1; i <= 3; i++){
		printLine(left, HLINE, mid, 4);
		for(int j = 1; j <= 19; j++)
			printf("%c", HLINE);
		printLine(mid, HLINE, right, 12);
		printf(" ");
	}
}

/******************************************************************************************************
 * @breif: This function displays a tabular menu that indicates an Item's ID, Type and Price.
******************************************************************************************************/
void displayMenu(){
	int  i;
	
	char sMain  [4][10] = { "Chicken", "Pork", "Fish", "Beef" };
	char sSide  [4][20] = { "Steamed Rice", "Shredded Corn", "Mashed Potato", "Steam Vegetables" };
	char sDrink [4][15] = { "Mineral Water", "Iced Tea", "Soda", "Fruit Juice" };
	
	float fMain  [4]    = {90.00, 105.00, 120.00, 135.00};
	float fSide  [4]    = {20.00, 35.00,  50.00,  65.00};
	float fDrink [4]    = {25.00, 35.00, 45.00, 55.00};

	printf("\n");
	
        for(i = 1; i <= 3; i++){
                printLine(TLCORNER, HLINE, TRCORNER, 37);
                printf(" ");
	}
    
        printf( "\n" "%-16c MAINS %16c " "%-16c SIDES %16c " "%-16c DRINKS %15c" , VLINE, VLINE, VLINE, VLINE, VLINE, VLINE);
			
	displayMenuDivider(VLLINE, HDLINE, VRLINE);
 	
        printf("\n");
	
	for(i = 1; i <= 3; i++)
		printf("%c ID %c\t      TYPE\t %c    PRICE   %c ", VLINE, VLINE, VLINE, VLINE);

        displayMenuDivider(VLLINE, VHLINE, VRLINE);
	printf("\n");
	
	for(i = 0; i < 4; i++){
		printf("%c %d  %c  %-16s %c %-6.2f %5c ", VLINE, i + 1, VLINE, sMain[i], VLINE, fMain[i], VLINE);
		printf("%c %d  %c  %-16s %c %-6.2f %5c ", VLINE, i + 1, VLINE, sSide[i], VLINE, fSide[i], VLINE);
		printf("%c %d  %c  %-16s %c %-6.2f %5c", VLINE, i + 1, VLINE, sDrink[i], VLINE, fDrink[i], VLINE);
		
		if(i != 3)
			displayMenuDivider(VLLINE, VHLINE, VRLINE);
		else
			displayMenuDivider(BLCORNER, HULINE, BRCORNER);
		printf("\n");
	}
}

/******************************************************************************************************
 * @breif: This function prints a three-part divider of Extended ASCII characters for the MOSTD banner. 
 * @param left: the leftmost character.
 * @param mid: the middle character.
 * @param right: the rightmost character.
******************************************************************************************************/
void displayMOSTDDivider(char left,	char mid, char right){
	printf("\n");
	printLine(left, HLINE, mid, 38);
	for(int i = 1; i <= 39; i++)
		printf("%c", HLINE);
	printLine(mid, HLINE, right, 38);
}

/******************************************************************************************************
 * @breif: This function displays the random Meal Set of the Day.
 * @param random: a pointer to a struct order that contains the randomly generated meal set of the day.
 * @param product: an array of meal structs representing the product names.
******************************************************************************************************/
void displayMSOTD(struct order *random, struct meal product[]){	
	displayProduct(product);
        printLine(TLCORNER, HLINE, TRCORNER, 117);
        printf("\n%-45c Today's Meal Set of the Day %45c", VLINE, VLINE);
        displayMOSTDDivider(VLLINE, HDLINE, VRLINE);
	printf("\n%c %20s %17c %20s %18c %20s %17c", VLINE, "MAIN", VLINE, "SIDE", VLINE, "DRINK", VLINE);
	displayMOSTDDivider(VLLINE, VHLINE, VRLINE);
	printf("\n%c", VLINE);
	printf("  %d. %-32s %c", random->main, product[random->main].main, VLINE);
	printf("  %d. %-33s %c", random->side, product[random->side].side, VLINE);
	printf("  %d. %-32s %c",  random->drink, product[random->drink].drink, VLINE);
	displayMOSTDDivider(BLCORNER, HULINE, BRCORNER);
}

/******************************************************************************************************
 * @breif: This function prints the discount banner for the Mealset of the Day.
******************************************************************************************************/
void displayMSOTDMessage(){
        printf("\e[1;93m\n");
	printLine(TTLCORNER, THLINE, TTRCORNER, 117);
	printf("\n%-36c Avail the Meal Set of the Day to get 15%% off! %36c\n", TVLINE, TVLINE);
	printLine(TBLCORNER, THLINE, TBRCORNER, 117);
	printf("\033[0m"); 
}

/******************************************************************************************************
 * @breif: This function displays a divider to be used in receipt-related functions.
 * @param left: the leftmost character.
 * @param mid: the middle character.
 * @param right: the rightmost character.
 * @param length: the length of the middle character.
******************************************************************************************************/
void displayReceiptLine(char left, char mid, char right, int length){
	printf("%c ", left);
	for(int i = 1; i <= length; i++)
		printf("%c", mid);
	printf(" %c\n", right);	
}

/******************************************************************************************************
 * @breif: This function displays the header of the receipt.
******************************************************************************************************/
void displayReceiptHeader(){
        printf("\n");
	printLine(TLCORNER, HLINE, TRCORNER, 49);
        printf("\n%c " "\t\t Andrea's Kitchen!\t\t " " %c\n", VLINE, VLINE);
        printf("%c " "\t\t  CCPROG1 | S11A\t\t " " %c\n", VLINE, VLINE);
        printf("%c " "\t\t     Receipt:\t\t\t " " %c\n", VLINE, VLINE);
        displayReceiptLine(VLINE, '-', VLINE, 47);
	printLine(VLINE, 32, VLINE, 49);
}

/******************************************************************************************************
 * @breif: This function displays the footer of the receipt.
******************************************************************************************************/
void displayReceiptFooter(){
	displayReceiptLine(VLINE, '-', VLINE, 47);
	printLine(VLINE, 32, VLINE, 49);
	printf("\n%c " "\t      Thank You for Ordering!\t\t " " %c\n", VLINE, VLINE);
	printLine(VLINE, 32, VLINE, 49);
	printf("\n");
	printLine(BLCORNER, HLINE, BRCORNER, 49);
}
