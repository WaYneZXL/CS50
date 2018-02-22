// Capitalizes a string

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("before: ");
    printf("after:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            int x = s[i] - 'a' + 28;
            int y = x % 26;
            printf("%c %i %i %i %i\n", 'a' + y, (int) s[i], (int) 'a', x, y);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
