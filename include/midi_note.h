#pragma once

struct MidiNote
{
    enum Note
    {
        a = 'A',
        b = 'B',
        c = 'C',
        d = 'D',
        e = 'E',
        f = 'F',
        g = 'G'
    } note;

    enum Type
    {
        normal, sharp, flat
    } type;

    int octave;
};
