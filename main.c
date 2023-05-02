#include "header.c"
#include "display.c"
#include "function.c"

int main(){
        struct order meals[3] = {};
        struct order meal;
        struct order random;
        struct meal product[5];
        struct value price[5];
        int nOrderNumber = 1, nOrderOption, nLoopControl = 0;
        int nYChoice, nNChoice, nCancelChoice, nExit;
        char cConfirmationOption;

        srand(time(NULL));
        random.main  = (rand() % 4) + 1;
        random.side  = (rand() % 4) + 1;
        random.drink = (rand() % 4) + 1;
    
        initializePrices(price);

        displayGreeting();
        displayMenu();
        displayMSOTD(&random, product);
        displayMSOTDMessage();

	while(nExit != 2){
	        inputOrderingOption(&nOrderOption);
	        reloadMenu(&random, product);

                do{
                        if(nOrderOption == 1)
                                inputOrder(&meal, product, nOrderNumber);
                        else if (nOrderOption == 2){
                                inputMealSetOfTheDay(&random, product, nOrderNumber);
                                meal = random;
                        }
	        
	                meals[nOrderNumber-1] = meal;
			
			inputConfirmationOption(&cConfirmationOption);
			reloadMenu(&random, product);
			
			switch(cConfirmationOption)
			{
				case 'Y':
				case 'y':
					if(nOrderNumber != 3){
					        do{
                                                        printf("\n\tWould you like to:\n\t [1] Continue to Payment\n\t [2] Add another order \n\n\t Option ");
                                                        scanf("%d", &nYChoice);
                                                        fflush(stdin);
                                        
                                                        if(nYChoice != 1 && nYChoice != 2)
                                                                printf("\e[1;31m" "\t  Invalid Input. Please choose one of the options.\n" "\e[1;97m");

                                                } while (nYChoice != 1 && nYChoice != 2);
		                
						switch(nYChoice){
							case 1:
								system("cls");
								displayReceipt(meals, product, price, nOrderNumber, random);
								nLoopControl = 1;
								break;
							case 2:
								nOrderNumber++;
								reloadMenu(&random, product);
								inputOrderingOption(&nOrderOption);
								break;
						}
					}
					else{
						system("cls");
						displayReceipt(meals, product, price, nOrderNumber, random);
						nLoopControl = 1;
					}
					break;

				case 'N':
				case 'n':
					do{
                                                printf("\n\tWould you like to:\n\t [1] Modify Order\n\t [2] Cancel order \n\n\t Option ");
                                                scanf("%d", &nNChoice);
                                                fflush(stdin);
                                
                                                if(nNChoice != 1 && nNChoice != 2)
                                                        printf("\e[1;31m" "\t  Invalid Input. Please choose one of the options.\n" "\e[1;97m");
                        
					} while (nNChoice != 1 && nNChoice != 2);
                                        
					switch(nNChoice){
						case 1:
							nLoopControl = 0;
							reloadMenu(&random, product);
							break;
						case 2:
							if(nOrderNumber != 1){
								do{
									reloadMenu(&random, product);
                                                                        printf("\n\tWould you like to:\n\t [1] Cancel Current Order\n\t [2] Cancel All Orders \n\n\t Option ");
                                                                        scanf("%d", &nCancelChoice);
                                                                        fflush(stdin);
                                                
                                                                        if(nCancelChoice != 1 && nCancelChoice != 2)
                                                                                printf("\e[1;31m" "\t  Invalid Input. Please choose one of the options.\n" "\e[1;97m");

                                                                } while (nCancelChoice != 1 && nCancelChoice != 2);
		                        
                                                                switch(nCancelChoice){
                                                                        case 1:
                                                                                nOrderNumber-=1;
                                                                                system("cls");
                                                                                displayReceipt(meals, product, price, nOrderNumber, random);
                                                                                nLoopControl = 1;
                                                                                break;
                                                                        case 2:
                                                                                nOrderNumber = 1;
                                                                                nLoopControl = 0;
                                                                                reloadMenu(&random, product);
                                                                                break;
                                                                }
                                                        }
                                                        else{
                                                                nOrderNumber = 1;
                                                                nLoopControl = 1;
                                                        }	
                                                        break;
						break;
					}
			}	
	    } while((nOrderNumber > 0 && nOrderNumber < 4) && (nLoopControl != 1));
	    
	        printf("\n\nPress Enter to Continue ...");
		getchar();
		reloadMenu(&random, product);
		
		do{
		        printf("\n\nWould you like to:\n\t [1] Order\n\t [2] Exit \n\n\t Option ");
			scanf(" %d", &nExit);
			fflush(stdin);
		} while (nExit != 1 && nExit != 2);
		
		reloadMenu(&random, product);
		nOrderNumber = 1;
		nLoopControl = 0;
    }

    return 0;
}