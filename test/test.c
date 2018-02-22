#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

int main(void)

{
    int octave = atoi(get_string("input octave: "));
    double base = 440 * pow(2.0, octave - 4.0);
    string note = get_string("input note: ");

    double freq;
    int result;

    if (note[0] == 'C')
    {
        freq = base / pow(2.0, 9.0/12.0);
    }
    else if (note[0] == 'D')
    {
        freq = base / pow(2.0, 7.0/12.0);
    }
    else if (note[0] == 'E')
    {
        freq = base / pow(2.0, 5.0/12.0);
    }
    else if (note[0] == 'F')
    {
        freq = base / pow(2.0, 4.0/12.0);
    }
    else if (note[0] == 'G')
    {
        freq = base / pow(2.0, 2.0/12.0);
    }
    else if (note[0] == 'B')
    {
        freq = base * pow(2.0, 2.0/12.0);
    }
    else
    //
    {
        freq = base;
    }

    if (note[1] == '#')
    {
        freq = freq * pow(2.0, 1.0/12.0);
    }
    else if (note[1] == 'b')
    {
        freq = freq / pow(2.0, 1.0/12.0);
    }

    result = round(freq);

    printf("%i\n", result);

}


