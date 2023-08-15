#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("What's the height? ");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        for (int x = height; x > i; x--)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}