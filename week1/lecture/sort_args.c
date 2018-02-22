// count the length of each argument,
// and print out the length in order

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    eprintf("argc: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        int len = strlen(argv[i]);
        eprintf("argv[%d]: %s (%d)\n", i, argv[i], len);
    }
}