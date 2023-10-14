#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

bool only_digits(string s);
char rotate(char c, int n);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (only_digits(argv[1]) != 1)
    {
        printf("Usage: ./caesar key\n");
    }
    int key = atoi(argv[1]);
    string plain = get_string("plaintext: ");
    char cipher[strlen(plain)];
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain); i++)
    {
        cipher[i] = rotate(plain[i], key);
        printf("%c", cipher[i]);
    }
    printf("\n");


}


bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]))
        {

        }
        else
        {
            return 0;
            break;
        }
    }
    return 1;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
           return (((c - 'A') + n)%26 + 'A');
        }
        else
        {
            return (((c - 'a') + n)%26 + 'a');
        }
    }
    else
    {
        return c;
    }
}