/* ----------------------------------------------------------------------------------------------------
    File: prime.c
    Author: Karan Randhawa
    Purpose Check if the number entered by user is either a prime or an Armstrong number, user-choice.
    --------------------------------------------------------------------------------------------------- */
#include <stdio.h>

int prime(int n);
int armstrong(int n);

int main(void)
{
    char c, trash;
    int n, temp=0;
    printf("Eneter a positive integer: ");
    scanf("%d", &n);
    scanf("%c", &trash);
    printf("Enter P to check prime and  A to check Armstrong number ==> ");
    scanf("%c", &c);
    if (c == 'p' || c == 'P')
    {
        temp = prime(n);
        if(temp == 1)
            printf("\n%d is a prime number.\n", n);
        else
            printf("\n%d is not a prime number.\n", n);
    }
    if (c == 'a' || c == 'A')
    {
        temp = armstrong(n);
        if(temp == 1)
            printf("\n%d is an Armstrong number.\n", n);
        else
            printf("\n%d is not an Armstrong number.\n",n);
    }
    return 0;
}

int prime(int n)
{
    int i, flag = 1;
    for(i = 2; i <= n / 2; ++i)
    {
       if(n % i == 0)
       { flag = 0; break; }
    }
    return flag;
}

int armstrong(int n)
{
    int num = 0, temp, flag = 0;
    temp = n;
    while(n != 0)
    {
	    num += (n % 10) * (n % 10) * (n % 10);
	    n /= 10;
    }
    if (num == temp) flag = 1;
    return flag;
}