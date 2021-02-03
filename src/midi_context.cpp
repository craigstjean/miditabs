#include "midi_context.h"

void MidiContext::new_file(std::string filename)
{
    current_track = 0;
    m_track_ticks.clear();
    m_midi_file = std::make_unique<MidiFileWrapper>(filename);

    smf::MidiEvent tempo_event;
    tempo_event.tick = 0;
    tempo_event.setMetaTempo(current_tempo);
    m_midi_file->get()->addEvent(tempo_event);
}

std::shared_ptr<smf::MidiFile> MidiFileWrapper::get()
{
    return m_midi_file;
}

std::shared_ptr<smf::MidiFile> MidiContext::midifile()
{
    return m_midi_file->get();
}

int MidiContext::track_count()
{
    int size = m_track_ticks.size();
    if (size == 0)
        size = 1;
    return size;
}

int MidiContext::track_tick(int track)
{
    // Piano = 0
    // Acoustic = 26
    // Electric = 28
    // Overdriven = 30
    // Distortion = 31
    while (m_track_ticks.size() < track + 1)
    {
        int track = m_track_ticks.size();
        int channel = 0;
        m_midi_file->get()->addTimbre(track, 0, channel, instrument);
        m_track_ticks.push_back(0);
    }
    
    return m_track_ticks[track];
}

void MidiContext::set_track_tick(int track, int tick)
{
    while (m_track_ticks.size() < track + 1)
    {
        int track = m_track_ticks.size();
        int channel = 0;
        m_midi_file->get()->addTimbre(track, 0, channel, instrument);
        m_track_ticks.push_back(0);
    }

    m_track_ticks[track] = tick;
}
