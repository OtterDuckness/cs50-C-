#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int size = 0;
    do
    {
        size = get_int("Start size: ");
    }
    while (size < 9);
    // TODO: Prompt for end size
    int ends = 0;
    do
    {
        ends = get_int("End size: ");
    }
    while (ends < size);
    // TODO: Calculate number of years until we reach threshold
    int n = 0;
    int b = 0;
    int d = 0;
    if (ends > size)
    {
        do
        {
            b = size / 3;
            d = size / 4;
            size = size + b - d;
            n++;
        }
        while (size < ends);
        // printf("Years: %i\n", n);
    }
    else
    {
        // TODO: Print number of years
        // printf("Years: %i\n", n);
    }
    printf("Years: %i\n", n);
}
