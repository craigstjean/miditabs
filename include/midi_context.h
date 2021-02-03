#pragma once

#include <string>

#include "MidiFile.h"

class MidiFileWrapper
{
public:
    MidiFileWrapper(std::string filename)
        : m_filename(filename) { }

    ~MidiFileWrapper()
    {
        if (!m_filename.empty())
        {
            m_midi_file.sortTracks();
            m_midi_file.write(m_filename);
        }
    }
private:
    smf::MidiFile m_midi_file;
    std::string m_filename;
};

class MidiContext
{
public:
    MidiContext()
    {
        current_track = 0;
    }

    void new_file(std::string filename);

    int current_track;
private:
    std::unique_ptr<MidiFileWrapper> m_midi_file;
};
