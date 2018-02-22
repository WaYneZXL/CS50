#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[]) //argv = argument vector, means go get the []+1 word
{
    if (argc == 2) //argc = argument count, 2 means type 2 words
    {
        printf("Hello, %s\n", argv[1]);
    }
    else
    {
        printf("Hello, world\n");
    }
}