#pragma once

#include <iostream>
#include <string>

#include "MidiFile.h"
#include "midi_note.h"

class MidiFileWrapper
{
public:
    MidiFileWrapper(std::string filename)
        : m_filename(filename)
    {
        m_midi_file = std::make_shared<smf::MidiFile>();
    }

    ~MidiFileWrapper()
    {
        if (!m_filename.empty())
        {
            m_midi_file->sortTracks();
            m_midi_file->write(m_filename);

            std::cout << "Wrote " << m_filename << std::endl;
        }
    }

    std::shared_ptr<smf::MidiFile> get();
private:
    std::shared_ptr<smf::MidiFile> m_midi_file;
    std::string m_filename;
};

class MidiContext
{
public:
    MidiContext()
    {
        current_track = 0;
        tick_speed = 0.25;
        current_tempo = 120;
        velocity = 25;
        instrument = 0;
    }

    void new_file(std::string filename);
    std::shared_ptr<smf::MidiFile> midifile();

    int current_track;
    int track_count();
    int track_tick(int track);
    void set_track_tick(int track, int tick);

    double tick_speed;
    int current_tempo;
    int velocity;
    int instrument;
    
    std::vector<MidiNote> tuning;
private:
    std::unique_ptr<MidiFileWrapper> m_midi_file;
    std::vector<int> m_track_ticks;
};
