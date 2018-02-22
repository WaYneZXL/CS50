#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // prompt a integer n first
    int n;
    // get a positive integer that is smaller than 23
    do
    {
        n = get_int ("Height: ");
    }
    while (n < 0 || n > 23);
    // start to print bricks
    for (int i = 0; i < n; i++)
    {
        //print space first, number of space = height - number of bricks of each row + 1, which is n - (i + 1)
        for (int j = 0; j < n - 1 - i; j++)
        {
            printf(" ");
        }
        //print bricks, number of bricks = number of row + 1, which is i + 1
        for (int k = 0; k <= i + 1; k++)
        {
            printf("#");
        }
        //go to next row
        printf("\n");
    }
}