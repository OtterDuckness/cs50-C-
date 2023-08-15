#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //number input
    long cnum = get_long ("Card number without spaces or slashes: ");

    long x = cnum;

    //luhns voodoo
    int a;
    int b;
    int y;
    int z;
    while (x > 0)  //
    {
        a = (x % 100) / 10 * 2;  //evens from the back to front
        b = (x % 10);  //odds from the back to front
        if (a > 9)  //in case of a double-digit even
        {
            a = a % 10 + (a / 10) % 10;
        }
        y = a + y;  //sum of evens
        z = b + z;  //sum of odds
        x = x / 100;
    }
    // printf("%i\n", y);
    // printf("%i\n", z);
    int sum = y + z;
    if (sum % 10 == 0)  //checking if valid
    {
        if (cnum / 10000000000000 == 34 || cnum / 10000000000000 == 37)        // amex
        {
            printf("AMEX\n");
        }
        else if (cnum / 100000000000000 == 51 || cnum / 100000000000000 == 52 || cnum / 100000000000000 == 53 || cnum / 100000000000000 == 54 || cnum / 100000000000000 == 55) // mastercard
        {
            printf("MASTERCARD\n");
        }
        else if (cnum / 1000000000000 == 4 || cnum / 1000000000000000 == 4)  // visa
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}