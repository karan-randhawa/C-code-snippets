/* ---------------------------------------------------------------------------------
	File: sin.c
	Purpose: SIN (Social Insurance Number) Validor [ C ]
	Author: Karan Randhawa
	Date: March 27, 2015
   --------------------------------------------------------------------------------- */
#include<stdio.h>
int main(void)
{
	int sin, 
		checkdigit, nexthighest, value, 
		digit1, digit2, 
		digit21, digit22, 
		digit3, 
		digit4, digit41, digit42, 
		digit5, digit6, digit61, digit62, 
		digit7, digit8, digit81, digit82, 
		evensum, oddsum, Tsum;
	printf("~~~SIN VALIDATOR~~~\n\n");
	printf("Enter SIN ==> ");
	scanf("%d", &sin);
	checkdigit = sin % 10;
	printf("Check digit : %d\n", checkdigit);
	
	sin = sin / 10;
	digit8 = sin % 10;
	sin = sin / 10;
	digit7 = sin % 10;
	sin = sin / 10;
	digit6 = sin % 10;
	sin = sin / 10;
	digit5 = sin % 10;
	sin = sin / 10;
	digit4 = sin % 10;
	sin = sin / 10;
	digit3 = sin % 10;
	sin = sin / 10;
	digit2 = sin % 10;
	sin = sin / 10;
	digit1 = sin;

	//calculate sum of even placed and odd placed digits
	digit2 = digit2 * 2;
	digit21 = digit2 % 10;
	digit22 = digit2 / 10;
	digit4 = digit4 * 2;
	digit41 = digit4 % 10;
	digit42 = digit4 / 10;
	digit6 = digit6 * 2;
	digit61 = digit6 % 10;
	digit62 = digit6 / 10;
	digit8 = digit8 * 2;
	digit81 = digit8 % 10;
	digit82 = digit8 / 10;

	evensum = digit21 + digit22 + digit41 + digit42 + digit61 + digit62 + digit81 + digit82;
	oddsum = digit1 + digit3 + digit5 + digit7;
	Tsum = evensum + oddsum;

	//calculate next highest multiple of 10
	nexthighest = Tsum + (10 - Tsum % 10);
	value = nexthighest - Tsum;

	//print calculated value
	printf("Calculated value : %d\n", value);
       
	//compare value with check digit and print result
	if(value == checkdigit) printf("SIN is valid\n");
	else printf("SIN is not valid\n");
	return 0;
}

