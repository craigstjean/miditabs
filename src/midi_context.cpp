#include "midi_context.h"

void MidiContext::new_file(std::string filename)
{
    current_track = 0;
    m_track_ticks.clear();

    m_instruments.clear();
    m_midi_file = std::make_unique<MidiFileWrapper>(filename);

    smf::MidiEvent tempo_event;
    tempo_event.tick = 0;
    tempo_event.setMetaTempo(current_tempo);
    m_midi_file->get()->addEvent(tempo_event);

    if (recent_instrument != 0)
    {
        m_midi_file->get()->addTimbre(0, 0, 0, recent_instrument);
        m_track_ticks.push_back(0);
    }
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
    while (m_track_ticks.size() < track + 1)
    {
        int track = m_track_ticks.size();
        int channel = track;
        m_midi_file->get()->addTimbre(track, 0, channel, recent_instrument);
        m_track_ticks.push_back(0);
    }

    return m_track_ticks[track];
}

int MidiContext::get_track_tick(int track)
{
    return m_track_ticks[track];
}

void MidiContext::set_track_tick(int track, int tick)
{
    while (m_track_ticks.size() < track + 1)
    {
        int track = m_track_ticks.size();
        int channel = track;
        m_midi_file->get()->addTimbre(track, 0, channel, recent_instrument);
        m_track_ticks.push_back(0);
    }

    m_track_ticks[track] = tick;
}

int MidiContext::get_instrument(int track)
{
    return m_instruments[track];
}

void MidiContext::set_instrument(int track, int instrument)
{
    while (m_instruments.size() < track + 1)
    {
        int track = m_track_ticks.size();
        m_instruments.push_back(0);
    }

    m_instruments[track] = instrument;
    recent_instrument = instrument;
}
