#include <stdio.h>
#include <cs50.h>

// explain how "strlen" works without using string.h library
int main(void)
{
    string s = get_string("Name: ");
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    printf("%i\n",i);
}