/********************************************************************************
Program: Zippy
Author: Ryan Bonnell
Date: May 20, 2019
Abstract: This program calculates quarterly credit card payments for purchases at
          Amazon, Canadian Tire and The Bay for ZiPPY Credit Card Company.  This 
		  is an assignment for CMPP205 'Introduction to Programming in C' at SAIT.
		  Instructor: Steve Hosier.
********************************************************************************/
#include <stdio.h>

int main(void)
{

int restart,      	//This variable used to restart program after calculations complete, see lines 179-189
    quarter,    
    temp_month1,  	//These variables used for printing accurate 'months', as determined from 'quarter' input
    temp_month2,
    temp_month3;
    
float prev_balance;  
	      	
float purchases [9];

char months[12][4] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

do
{
printf("=======================================\n");    
printf("*****ZiPPY Credit Card Calculator*****\n");
printf("=======================================\n");

do{
printf("\nPlease enter the desired annual quarter (1, 2, 3 or 4): ");
scanf("%d", &quarter);
    if ((quarter < 1 || quarter > 4)){
        printf("\nIvalid input, please try again!\n");
    }
}while ((quarter < 1 || quarter > 4));

do{
printf("\nPlease enter the previous balance between $0-$1000: ");
scanf("%f", &prev_balance);
    if ((prev_balance < 0 || prev_balance > 1000)){
        printf("\nInvalid input. Please try again!\n");
    }
}while ((prev_balance < 0 || prev_balance > 1000));

switch(quarter) {
    
    case 1:
        
        temp_month1 = 0;
        temp_month2 = 1;
        temp_month3 = 2;
        printf("\nCalculating payments for quarter #1:\n");
        break;
        
	case 2:
        
        temp_month1 = 3;
        temp_month2 = 4;
        temp_month3 = 5;
        printf("\nCalculating payments for quarter #2:\n");
        break;
        
	case 3:
        
        temp_month1 = 6;
        temp_month2 = 7;
        temp_month3 = 8;
        printf("\nCalculating payments for quarter #3:\n");
        break;
        
    case 4:
        
        temp_month1 = 9;
        temp_month2 = 10;
        temp_month3 = 11;
        printf("\nCalculating payments for quarter #4:\n");
        break;
}
        
do{
    printf("\nPlease enter %s purchases for Amazon: ", months[temp_month1]);    	//References 'temp_month' index in 'months' array
    scanf("%f", &purchases[0]);														//to accurately print month. Scans user input and 
       	if ((purchases[0] < 0 || purchases[0] > 1000)){								//stores as float in 'purchases' array.  Requests
    		printf("\nInvalid input. Please enter a value between $0-$1000.\n");	//total from each store for each month of the
    	}																			//quarter for a total of 9 values
}while ((purchases[0] < 0 || purchases[0] > 1000));

do{
    printf("\nPlease enter %s purchases for Canadian Tire: ", months[temp_month1]);
    scanf("%f", &purchases[1]);
       	if ((purchases[1] < 0 || purchases[1] > 1000)){
   				printf("\nInvalid input. Please enter a value between $0-$1000.\n");
   		}
}while ((purchases[1] < 0 || purchases[1] > 1000));

do{
    printf("\nPlease enter %s purchases for The Bay: ", months[temp_month1]);
    scanf("%f", &purchases[2]);
       	if ((purchases[2] < 0 || purchases[2] > 1000)){
			printf("\nInvalid input. Please enter a value between $0-$1000.\n");
    	}
}while ((purchases[2] < 0 || purchases[2] > 1000));

do{
    printf("\nPlease enter %s purchases for Amazon: ", months[temp_month2]);
    scanf("%f", &purchases[3]);
       	if ((purchases[3] < 0 || purchases[3] > 1000)){
			printf("\nInvalid input. Please enter a value between $0-$1000.\n");
   		}
}while ((purchases[3] < 0 || purchases[3] > 1000));
        
do{
    printf("\nPlease enter %s purchases for Canadian Tire: ", months[temp_month2]);
    scanf("%f", &purchases[4]);
       	if ((purchases[4] < 0 || purchases[4] > 1000)){
			printf("\nInvalid input. Please enter a value between $0-$1000.\n");
   		}
}while ((purchases[4] < 0 || purchases[4] > 1000));

do{
    printf("\nPlease enter %s purchases for The Bay: ", months[temp_month2]);
    scanf("%f", &purchases[5]);
       	if ((purchases[5] < 0 || purchases[5] > 1000)){
			printf("\nInvalid input. Please enter a value between $0-$1000.\n");
   		}
}while ((purchases[5] < 0 || purchases[5] > 1000));

do{
    printf("\nPlease enter %s purchases for Amazon: ", months[temp_month3]);
    scanf("%f", &purchases[6]);
       	if ((purchases[6] < 0 || purchases[6] > 1000)){
			printf("\nInvalid input. Please enter a value between $0-$1000.\n");
   		}
}while ((purchases[6] < 0 || purchases[6] > 1000));

do{
    printf("\nPlease enter %s purchases for Canadian Tire: ", months[temp_month3]);
    scanf("%f", &purchases[7]);
       	if ((purchases[7] < 0 || purchases[7] > 1000)){
			printf("\nInvalid input. Please enter a value between $0-$1000.\n");
   		}
}while ((purchases[7] < 0 || purchases[7] > 1000));

do{
    printf("\nPlease enter %s purchases for The Bay: ", months[temp_month3]);
    scanf("%f", &purchases[8]);
       	if ((purchases[8] < 0 || purchases[8] > 1000)){
			printf("\nInvalid input. Please enter a value between $0-$1000.\n");
   		}
}while ((purchases[8] < 0 || purchases[8] > 1000));


float amazon_total = (purchases[0] + purchases[3] + purchases [6]);   //Calculates total monthly purchases from each store
float cantire_total = (purchases[1] + purchases[4] + purchases [7]);
float thebay_total = (purchases[2] + purchases[5] + purchases [8]);

float sum = 0;  //This function calculates the sum of all vales in the float array "purchases" with a loop 
int loop;
for(loop = 0; loop <= 8; loop++) {
      sum = sum + purchases[loop];      
}

float balance = (prev_balance + sum);
float min_payment = (balance * 0.10);

printf("=============================================");
printf("\nMONTH\tAMAZON\tCANADIAN TIRE\tTHE BAY\n");
printf("=============================================\n");
printf("%s\t%.2f\t    %.2f\t %.2f", months[temp_month1], purchases[0], purchases[1], purchases[2]);
printf("\n%s\t%.2f\t    %.2f\t %.2f", months[temp_month2], purchases[3], purchases[4], purchases[5]);
printf("\n%s\t%.2f\t    %.2f\t %.2f", months[temp_month3], purchases[6], purchases[7], purchases[8]);
printf("\nTOTAL\t%.2f\t    %.2f\t %.2f", amazon_total, cantire_total, thebay_total);
printf("\n\n");
printf("Previous Balance:\t%.2f\n", prev_balance);
printf("Quarterly Total:\t%.2f\n", sum);
printf("Balance Owing:\t\t%.2f\n", balance);
printf("Minimum Payment:\t%.2f\n", min_payment);

do
{
printf("\nWould you like to process another quarter? (1: Yes, 2: Quit): ");
scanf("%d", &restart);
    if ((restart < 1)||(restart > 2)){
        printf("\nInvlid input. Please try again!\n");
    }
}while((restart < 1)||(restart > 2));

    
}while(restart == 1);    
    
return 0;
}
