#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt for a positive number
    int n;
    do
    {
        n = get_int ("Positive Number: ");
    }
    while (n<=0);
    // print out rows
    for (int i = 0; i < n; i++)
    {
        // print out columns
        for (int j = 0; j < n; j++)
        {
           printf("#");
        }
        printf("\n");
    }
}