#include <ostream>
#include <string>
#include <vector>

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

class MidiCommand
{
public:
    enum Type
    {
        Tuning,
        File,
        Measures,
        Notes,
        Tempo,
        LineChange,
        Chords,
        NoteChange,
        SubCommands
    } type;

    struct tuning
    {
        std::vector<MidiNote> notes;
    } tuning;

    struct file
    {
        std::string name;
    } file;

    struct measures
    {
        int notes;
        double length;
    } measures;

    struct notes
    {
        double length;
    } notes;

    struct tempo
    {
        int tempo;
    } tempo;

    struct line_change
    {
        int line;
    } line_change;

    struct chords
    {
        enum Type
        {
            Play, Rest, Repeat
        } type;

        std::vector<int> values;
    } chords;

    struct note_change
    {
        double length;
    } note_change;

    MidiCommand() {};
    MidiCommand(MidiCommand::Type wantedType)
        : type{wantedType}
    {
        
    }

    void add_subcommand(std::shared_ptr<MidiCommand> command);
    const std::vector<MidiCommand> subcommands();

    friend std::ostream& operator<<(std::ostream &out, const MidiCommand& data);
private:
    std::vector<MidiCommand> m_subcommands;
};

class MidiCommands
{
public:
    MidiCommands(std::vector<MidiCommand> commands)
        : m_commands{commands}
    {
    }

    const std::vector<MidiCommand> commands();
private:
    std::vector<MidiCommand> m_commands;
};
