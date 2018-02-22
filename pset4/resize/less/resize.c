// resizes a bmp file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // ensure n is an integer between 1 and 100
    int n = atoi(argv[1]);
    if (n < 1 || n > 100)
    {
        fprintf(stderr, "n must be an integer between 1 and 100\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 1;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 1;
    }

    // calculate padding for input file
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // calculate new biWidth and new biHeight
    bi.biWidth = n * bi.biWidth;
    bi.biHeight = n * bi.biHeight;

    // calculate padding for output file
    int paddingnew = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Calculate new biSizeImage and bfSize (using paddingnew)
    bi.biSizeImage = abs(bi.biHeight) * (bi.biWidth * sizeof(RGBTRIPLE) + paddingnew);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // scale back biWidth and biHeight in the original picture, as we will refer them from the input file below
    bi.biWidth = bi.biWidth / n;
    bi.biHeight = bi.biHeight / n;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // this loop helps to write n times verticaly
        for (int k = 0; k < n; k++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile n times
                fwrite(&triple, sizeof(RGBTRIPLE), n, outptr);

                // add paddings for output file
                for (int m = 0; m < paddingnew; m++)
                {
                    fputc(0x00, outptr);
                }

                // skip the paddings that we just printed, now cursor should be at the start of the next row
                fseek(outptr, paddingnew, SEEK_CUR);
            }
            if (k < n - 1)
            {
                //move cursor back to the start of the line and start over until k = n - 1
                int linelen = abs(bi.biWidth) * -1;
                fseek(inptr, linelen, SEEK_CUR);
            }
            else
            {
                // now we've printed n rows vertically and we can skill the padding and go to next row
                fseek(inptr, padding, SEEK_CUR);
            }
        }

    }
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
