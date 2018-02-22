// recover jpeg files from card

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // there is only 1 command line argument
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // declare a buffer that euqals to the size of a block on memory card
    // the array type is integer so that buffer[] can be compared below
    char buffer[512];
    // number of jpeg is 0 at the start
    int jpgcount = 0;
    // name of the output files "xxx.jpg"
    char filename[8];

    FILE *outptr;
    // fread function should return to 1 if we have not reached the EOF
    while (fread(buffer, 512, 1 , inptr) == 1)
    {
        // if we're not at EOF, check if the file is jpg
        if ((int)buffer[0] == 0xff && (int)buffer[1] == 0xd8 && (int)buffer[2] == 0xff && ((int)buffer[3] & 0xf0) == 0xe0)
        {
            // if this is our first file
            if (jpgcount == 0)
            {
                // name the file
                sprintf(filename, "00%i.jpg", jpgcount);

                // open the output file
                outptr = fopen(filename, "w");

                // count + 1
                jpgcount ++;
            }
            // if this is NOT the first time we recover a file
            else
            {
                // close existing file first
                fclose(outptr);

                // name the file
                sprintf(filename, "00%i.jpg", jpgcount);

                // reopen the output file
                outptr = fopen(filename, "w");

                // count + 1
                jpgcount ++;
            }

        // write the buffer to output file
        fwrite(&buffer, 512, 1, outptr);
        }

    }

    fclose(inptr);


    // not sure why it says segmentation fault each time I include the following code
    //fclose(outptr);

    // success
    return 0;
}

