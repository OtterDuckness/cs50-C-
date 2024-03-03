#include <cs50.h>
#include <stdio.h>

int change(int a);

int main(void)
{
    int change_owed;
    do
    {
        change_owed = get_int("Change owed: ");
    }
    while (change_owed < 0);
    change(change_owed);
    printf("%i\n", change(change_owed));

}
int change(int a)
{
    if (a % 25 > 0)
    {
        int x = a - a / 25 * 25;
        if (x % 10 > 0)
        {
            int y = x - x / 10 * 10;
            if ( y % 5 > 0)
            {
                int z = y - y / 5 * 5;
                return (a / 25 + x / 10 + y / 5 + z);
            }
            else
            {
                return(a / 25 + x / 10 + y / 5);
            }
        }
        else
        {
            return ( a / 25 + x / 10);
        }
    }
    else
    {
        return (a / 25);
    }
}
