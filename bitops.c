//This is a program that either sets or clears a single bit of a number entered by the user
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FLUSH while(getchar() != '\n')

int main(int argc, char **argv)
{

	int in, choice, number;
	uint32_t bit;
	char tryAgain = 'Y';
	
	//Loop to repaeat the program
	while(tryAgain == 'y' || tryAgain == 'Y')
	{

		//Asks user for the staring value
		printf("Please enter an integer value between 1 and 1000.\n");
		scanf("%d", &in);
		printf("\n"); 

		//Checks if the starting value is between 1 and 1000
		if(in < 1 || in > 1000)
		{
		
			printf("Input value is not between 1 and 1000.\n");//Prints error if it isnt
			exit(100);
		}

		//Asks user for bit to clear or set
		printf("Enter a bit between 0 and 31 to set or clear.\n");
		scanf("%d", &bit);
		printf("\n");

		FLUSH;//Flush to keep going			

		//Chechks if the bit entered is between 0 and 31
		if (bit < 0  || bit > 31)
		{
			printf("Input value is not between 0 and 31.\n");//Prints error
 			exit(100);
		}
		
		//Else the bit is acceptable and can be cleared or swirched
		else
		{

			//Asks user whether thye want to clear or switch the bit
			printf("Do you want to 1.Set or 2.Clear? 1/2\n");
			scanf("%d", &choice);
			printf("\n");
			
			//Checks if the user chose to clear or switch
			if ( choice < 1 || choice > 2)
			{
				printf("Input value is not 1.Set or 2.Clear.\n");//Prints error
				exit(100);

			}
			//If they chose to set	
			else if(choice == 1)
			{
				
				number = (1 << bit) | in; //Logic for setting the bit
				printf("%d\n",number);//Prints the new number
				printf("\n");
			}
			//If they chose to clear
			else if(choice == 2)
			{	
                                number = in & (~(1<<bit)); //Logic for clearing the bit
				printf("%d\n",number);//Prints the new number
				printf("\n");
			}			

		}
		
		printf("Would you like to try again? Y/N\n");//Ask user if they want to repeat
		FLUSH;
		tryAgain = getchar();
	}

	exit(0);	
}
