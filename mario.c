#include <cs50.h>
#include <stdio.h>

void row_length(int spaces, int bricks);

int main(void)
{
    int size;
    do
    {
        size = get_int("How big is the pyramid? ");
    }
    while (size < 1 || size > 8);
    for (int i = 1; i <= size; i++)
    {
        row_length(size - i, i);
    }
}

void row_length(int spaces, int bricks)
{
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
    for (int h = 0; h < bricks; h++)
    {
        printf("#");
    }
    printf("  ");
    for (int h = 0; h < bricks; h++)
    {
        printf("#");
    }
    // for (int j = 0; j < spaces; j++)
    // {
    //     printf(" ");
    // }
    printf("\n");
}
