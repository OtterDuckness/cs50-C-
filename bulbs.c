#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string message = get_string("Message: ");
    int length = strlen(message);
    int binrev[BITS_IN_BYTE];
    int bin[BITS_IN_BYTE];
    int n[BITS_IN_BYTE];
    //goes through the each letter of the string
    for (int i = 0; i < length; i++)
    {
        //setting up the following loop
        binrev[0] = message[i] % 2;
        n[0] = message[i];
        //converting decimal into  reverse binary
        for (int j = 1; j < BITS_IN_BYTE; j ++)
        {
            n[j] = n[j-1] / 2;
            binrev[j] = n[j] % 2;
        }
        // changing reverse binary into proper binary
        for (int y = 0; y < BITS_IN_BYTE; y++ )
        {
            bin[y] = binrev[BITS_IN_BYTE - 1 - y];
            print_bulb(bin[y]);
        }
        printf("\n");
    }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
