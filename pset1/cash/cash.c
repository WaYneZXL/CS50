#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // prompt two integers n and i, which represents the amount to be entered (in cents) and the number of coins
    int n;
    int i = 0;
    do
    {
        //round up n
        n = round(get_float ("Change owed: ") * 100);
    }
    while (n <= 0);
    //if n >= 25c, use 25c first, then dedecut 25c from n, and add 1 to i
    while (n >= 25)
    {
        n = n - 25;
        i++;
    }
    //if n >= 10c, use 10c first, then dedecut 10c from n, and add 1 to i
    while (n >= 10)
    {
        n = n - 10;
        i++;
    }
    //if n >= 5c, use 5c first, then dedecut 5c from n, and add 1 to i
    while (n >= 5)
    {
        n = n - 5;
        i++;
    }
    //if n >= 1c, use 1c, then dedecut 1c from n, and add 1 to i
    while (n >= 1)
    {
        n = n - 1;
        i++;
    }
    printf("%i\n", i);
}