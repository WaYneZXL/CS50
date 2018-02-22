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

    for (int i = 0; i < n; i++)
    {
    printf("#\n");
    }
}