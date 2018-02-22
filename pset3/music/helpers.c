// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int durat;
    int denu = fraction[0];
    int nu = fraction[2];

    if (strlen(fraction) == 3)
    {
        if (nu == 8)
        {
            durat = denu * nu;
        }
        else if (nu == 4)
        {
            durat = denu * nu * 2;
        }
        else
        // when nu ==2
        {
            durat = denu * nu * 4;
        }
    }
    else
    //when strlen == 1
    {
        durat = denu * 8;
    }
    return durat;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // get the number of octave
    int octave = note[strlen(note)];

    // get the A (base) of each octave

    double base = 440.0 * pow(2.0, octave - 4.0);
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

    return result;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
