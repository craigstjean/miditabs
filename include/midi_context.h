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
            m_midi_file.write(m_filename);
    }
private:
    smf::MidiFile m_midi_file;
    std::string m_filename;
};

class MidiContext
{
public:
    void new_file(std::string filename);
private:
    std::unique_ptr<MidiFileWrapper> m_midi_file;
};
