# Questions

## What's `stdint.h`?

It is a library that helps us to define integer types that are specific to .bmp files / windows programming, such as BYTE, DWORD, LONG, and WORD.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Because different specifier has different range (between its maximum number and minimum number) and the difference between 'int' and 'unit' is
that 'int' is signed and 'uint' is unsigned (can't take negative value).
For example, 'int8_t' can take value between -128 and 127.
Source: https://en.wikibooks.org/wiki/C_Programming/stdint.h

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE: 1 bytes
DWORD: 4 bytes
LONG: 4 bytes
WORD: 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

424d

## What's the difference between `bfSize` and `biSize`?

bfSize is the total size of the file, including pixels, padding, and header.
biSize is the size of BITMAPINFOHEADER, which is 40 in our case.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB (device-independent bitmap) with the origin at the upper left corner.
Source: https://msdn.microsoft.com/en-us/library/windows/desktop/dd318229(v=vs.85).aspx

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Maybe the input or output file is not a file type that C supporrs, therefore, it will return NULL.

## Why is the third argument to `fread` always `1` in our code?

The third argument means the number of time a object to be read in the array of objects, specified by the first argument.
'1' means that we read the object once.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

padding = (4 - (3 * 3) % 4) % 4 = 3

## What does `fseek` do?

fseek moves the "cursor" to a new location, which in our case means that we skipp the padding.

## What is `SEEK_CUR`?

It means that we skip 'padding' number of bytes starting from our current location.
