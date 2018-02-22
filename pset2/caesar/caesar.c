#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//include all necesary libraries

int main(int argc, string argv[])
{
    int j, k;
    string l = argv[1];
    // if there are only 2 arguments in the command, proceed; else go to error message
    if (argc == 2)
    {
        //turn string into integer
        int i = atoi(l);
        string s = get_string("plaintext:  ");
        printf("ciphertext:  ");
        for (j = 0, k = strlen(s); j < k; j++)
        {
            //if the ith letter is upper case
            if (isupper(s[j]))
            {
                int x = (s[j] - 'A' + i) % 26;
                printf("%c", 'A' + x);
            }
            //if the letter is lower case
            else if (islower(s[j]))
            {
                int y = (s[j] - 'a' + i) % 26;
                printf("%c", 'a' + y);
            }
            else
            {
                //everything else
                printf("%c", s[j]);
            }
        }
        printf("\n");
    }
    else
    {
        //error message
        printf("Usage: ./caesar k\n");
        return 1;
    }
}