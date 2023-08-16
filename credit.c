#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // number input
    long cnum = get_long("Number: ");
    long x = cnum;

    // luhns voodoo
    int a;
    int b;
    int y;
    int z;
    while (x > 0)
    {
        a = (x % 100) / 10 * 2; // evens from back to front
        b = (x % 10);           // odds from back to front
        if (a > 9)              // in case of a double-digit even
        {
            a = a % 10 + (a / 10) % 10;
        }
        y = a + y; // sum of evens
        z = b + z; // sum of odds
        x = x / 100;
    }

    int sum = y + z;
    long biga = 10000000000000;
    long bigm = 100000000000000;
    long smolv = 1000000000000;
    long bigv = 1000000000000000;
    if (sum % 10 == 0) // checking if valid
    {
        if (cnum / biga == 34 || cnum / biga == 37) // amex
        {
            printf("AMEX\n");
        }
        else if (cnum / bigm == 51 || cnum / bigm == 52 || cnum / bigm == 53 || cnum / bigm == 54 || cnum / bigm == 55) // mastercard
        {
            printf("MASTERCARD\n");
        }
        else if (cnum / smolv == 4 || cnum / bigv == 4) // visa
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