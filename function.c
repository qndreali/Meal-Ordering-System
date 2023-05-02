int inputOrderingOption(int *pOrderOption){
    do
    {
        printf( "\nPlease choose one of the following options: \n"
                "  [1] Custom Order \n  [2] Meal Set of the Day\n\n  Option ");
        scanf("%d", pOrderOption);
        fflush(stdin);

        if(*pOrderOption < 1 || *pOrderOption > 2)
            printf("\e[1;31m" "    Invalid Input.\n" "\e[1;97m");

    } while (*pOrderOption < 1 || *pOrderOption > 2); 

    return *pOrderOption;
}

void inputOrder(struct order *meal, struct meal product[], int nOrderNumber){
    displayProduct(product);
    
    printf("\n  Please choose one of the following ID options in the menu:" "\n  Input 0 if you'd like to avail none."
		   "\n\n     Order %d:\n", nOrderNumber);
		   
    do
    {
        printf("\t Main:\t");
        scanf("%d", &meal->main);
        fflush(stdin);

        if(meal->main > 4 || meal->main < 0)
            printf("\e[1;31m" "\t\tInvalid Input. Please choose one of the options in the Menu.\n" "\e[1;97m"); 
    } while (meal->main > 4 || meal->main < 0); 
    printf("\t\t%s\n", product[meal->main].main);

    do
    {
        printf("\t Side:\t");
        scanf("%d", &meal->side);
        fflush(stdin);

        if(meal->side > 4 || meal->side < 0)
            printf("\e[1;31m" "\t\tInvalid Input. Please choose one of the options [0-41in the Menu.\n" "\e[1;97m"); 
    } while (meal->side > 4 || meal->side < 0); 
    printf("\t\t%s\n", product[meal->side].side);

    do
    {
        printf("\t Drink:\t");
        scanf("%d", &meal->drink);
        fflush(stdin);

        if(meal->drink > 4 || meal->drink < 0)
            printf("\e[1;31m" "\t\tInvalid Input. Please choose one of the options in the Menu.\n" "\e[1;97m"); 
    } while (meal->drink > 4 || meal->drink < 0); 
    printf("\t\t%s\n", product[meal->drink].drink);
}

void inputMealSetOfTheDay(struct order *random, struct meal product[], int nOrderNumber){
    displayProduct(product);
    printf("\n  You chose the Meal Set of the Day!\n\n     Order %d:\n", nOrderNumber);
    printf("\t Main:\t %d\n\t\t %s\n", random->main, product[random->main].main);
    printf("\t Side:\t %d\n\t\t %s\n", random->side, product[random->side].side);
    printf("\t Drink:\t %d\n\t\t %s\n", random->drink, product[random->drink].drink);
}

char inputConfirmationOption(char *pConfirmationOption){
    do
	{
		printf("\n\n\tConfirm Order: [Y/N] ");
		scanf(" %c", pConfirmationOption);
		fflush(stdin);
		
		if(*pConfirmationOption != 'Y' && *pConfirmationOption != 'y' && *pConfirmationOption != 'N' && *pConfirmationOption != 'n')
			printf("\e[1;31m" "\t  Invalid Input. Please choose one of the options.\n" "\e[1;97m");

	} while (*pConfirmationOption != 'Y' && *pConfirmationOption != 'y' && *pConfirmationOption != 'N' && *pConfirmationOption != 'n'); 

    return *pConfirmationOption;
}

float calculateSubtotal(struct order *meal, struct value *price, struct order *random){
    if(random->main == meal->main && random->side == meal->side && random->drink == meal->drink)
        return (price[meal->main].main + price[meal->side].side + price[meal->drink].drink) * 0.85;
    else 
        return price[meal->main].main + price[meal->side].side + price[meal->drink].drink;

}

float calculateTotal(struct order *meals, int nOrderNumber, struct value *price, struct order *random){
    float total = 0.0;
    for(int i = 0; i < nOrderNumber; i++)
        total += calculateSubtotal(&meals[i], price, random);
    return total;
}

void displayReceipt(struct order *meals, struct meal product[], struct value *price, int nOrderNumber, struct order random){
	displayReceiptHeader();
    for(int i = 0; i < nOrderNumber; i++) {
        displayProduct(product);
        printf("\n%c  Order %d: %39c\n", VLINE, nOrderNumber, VLINE);
        printf("%c    %-11s %-23s %6.2f %3c\n", VLINE, "Main:",  product[meals[i].main].main,   price[meals[i].main].main,   VLINE);
        printf("%c    %-11s %-23s %6.2f %3c\n", VLINE, "Side:",  product[meals[i].side].side,   price[meals[i].side].side,   VLINE);
        printf("%c    %-11s %-23s %6.2f %3c\n", VLINE, "Drink:", product[meals[i].drink].drink, price[meals[i].drink].drink, VLINE);

        if (random.main == meals[i].main && random.side == meals[i].side && random.drink == meals[i].drink)
        	printf("%c    Mealset Discount: 15%% %24c\n" "%c  Subtotal: %34.2f %3c\n", VLINE, VLINE, VLINE,  calculateSubtotal(&meals[i], price, &random) , VLINE);
        else
        	printf("%c  Subtotal: %34.2f %3c\n", VLINE, calculateSubtotal(&meals[i], price, &random), VLINE);
        printLine(VLINE, 32, VLINE, 49);
    }
    
    printf("\n");
	printLine(VLINE, 32, VLINE, 49);
    printf("\n%c  Total Amount Due: %26.2f %3c\n", VLINE, calculateTotal(meals, nOrderNumber, price,  &random), VLINE);
    printLine(VLINE, 32, VLINE, 49);
    printf("\n");
    displayReceiptFooter();
}

