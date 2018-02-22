#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//include all necesary libraries

int main(int argc, string argv[])
{
    int m, i, x, y, z;

    if (argc !=2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    else
    {
        string l = argv[1];
        int keylen = strlen(l);

        for (m = 0; m < keylen; m++)
        {
            if (isalpha(l[m]))
            {
                continue;
            }
            else
            {
                printf("Usage: ./vigenere k\n");
                return 1;
            }
            break;
        }

        string s = get_string("plaintext:  ");
        printf("ciphertext:  ");

        int inputlen = strlen(s);
        //count the letters of "plaintext"

        int alphanb = -1;

        for (i = 0; i < inputlen; i++)
        {
            //assign an integer x, so that x is the remainder of i (integer in the loop) devided by the lenghth of the key
            //for example, when keylen = 3, x can only be 0, 1, 2


            //make sure non-alphabetic characters don't take any space in the loop

            if (isalpha(s[i]))
            {
                alphanb = alphanb + 1;
                x = alphanb % keylen;
            }


            //depending on each letter in key is upper or lower case, we use x to get the numerical key y for each letter
            if (isupper(l[x]))
            {
                y = l[x] - 'A';
            }
            else if (islower(l[x]))
            {
                y = l[x] - 'a';
            }

            //After getting the key, we're moving to the plaintext input
            //still, we need to figure out whether the text input is upper or lower case (or space / digit / etc.)

            if (isupper(s[i]))
            {
                z = (s[i] - 'A' + y) % 26;
                printf("%c", 'A' + z);
            }
            else if (islower(s[i]))
            {
                z = (s[i] - 'a' + y) % 26;
                printf("%c", 'a' + z);
            }
            else
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
        return 0;
    }
}




