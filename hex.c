/*-------------------------------------------------------------------------
  File    : hex.c
  Purpose : Convert hexadecimal number to decimal number
  Author  : Karan Randhawa
  Date    : February 18, 2015
  -------------------------------------------------------------------------*/
#include<stdio.h>

int main(void)
{       
	char hexNumber; 
	int decimalNumber, exceedLimit = 0; // To store decimal number and initializing digit-counter to zero
	double  totalValue=0; // To store the final decimal value of the hexadecimal number        
	printf("+-------------------------+\n|  HEXADECIMAL CONVERTER  |\n+-------------------------+\n\n");
	printf("Enter a hex number ==> ");
	scanf("%c", &hexNumber);
	if(hexNumber == '\n' || hexNumber == ' ') // Check against null input
	{ printf("ERROR: Nothing entered\n\n"); return 0; }
	while(hexNumber != '\n')
	{       
		if(hexNumber >= 'a' && hexNumber <= 'f') decimalNumber = hexNumber - 87; 
		else if(hexNumber >= 'A' && hexNumber <= 'F') decimalNumber = hexNumber - 55;
		else if(hexNumber >= '0' && hexNumber <= '9') decimalNumber = hexNumber - '0';
		else if(hexNumber == ' ') //else-if statement to check for blank spaces and ignore them
		{ 
			exceedLimit--;
			decimalNumber = 0;
			scanf("%c", &hexNumber);
			if(hexNumber >= 'a' && hexNumber <= 'f') decimalNumber = hexNumber - 87;
			else if(hexNumber >= 'A' && hexNumber <= 'F') decimalNumber = hexNumber - 55;
			else if(hexNumber >= '0' && hexNumber <= '9') decimalNumber = hexNumber - '0';
			else
			{ printf("ERROR: This is not a valid hexadecimal number\n\n"); return 0; }
		}
		else 
		{ printf("ERROR: This is not a valid hexadecimal number\n\n"); return 0; }
		totalValue = totalValue * 16 + decimalNumber;
		scanf("%c", &hexNumber); // Take next character from the input-buffer
		exceedLimit++; // Increment number of digits
	}               
	
	if(exceedLimit > 6)
	{ printf("ERROR: You entered more than 6 hexadecimal digits\n\n"); return 0; }
	printf("Decimal number is %.0lf.\n\n", totalValue); // Print final decimal value of the entered hexadecimal number
	return 0;
}