# miditabs

Takes a custom tab format and produces MIDI files

## Getting Started

These instructions will get you a copy of the project up and running on your local machine.

### Prerequisites

What things you need to install the software and how to install them

* C++ Compiler
* [cmake](https://cmake.org)
* [ninja](https://ninja-build.org) (optional)
* Java (to generate ANTLR4 files, not for runtime)
* VSCode (optional)

### Installing

Clone the repository

```
git clone --recurse-submodules https://github.com/craigstjean/miditabs.git
```

Generate ANTLR4 files and build

```
cd miditabs
./build.sh
```

build.sh will download the ANTLR4 generator and build the solution. You will end up with the executable in build/miditabs

## Running it

```
./miditabs input1.txt input2.txt ...
```

## Language

Each line of your input can be either a command, or tab notes.

Commands:

* Tuning
    * "Tuning " followed by the notes (b for flat, # for sharp) and octaves of each string. Not limited to 6 strings.
    * Example: Tuning E2 A2 D3 G3 B3 E4
    * Example: Tuning Eb2 G2 D3 A3 Bb3 C4
* File
    * "File " followed by the filename you wish to write to. The file will be written when the file is done processing, or when miditabs sees the next File command. Must end in .mid
    * Example: File demo.mid
* Instrument
    * "Instrument " followed by the MIDI instrument index (see https://en.wikipedia.org/wiki/General\_MIDI)
    * Example (Clean Electric Guitar): Instrument 28
* Attack
    * "Attach " followed by 0-100 for how hard each note should attack. Default is 25
* Measures
    * "Measures " followed by a time signature. Currently does not impact the end result.
    * Example: Measures 3/4
* Notes
    * "Notes " followed by the speed of any following note (1/4 for quater notes, 1 for whole notes, etc.)
    * Example: Notes 1/4
* Tempo
    * "Tempo " followed by the desired tempo, e.g. 120

Tab Syntax:

* Each strum is indicated by a series of numbers, followed by a space or end of line
* Numbers represent the fret on the string, and are in the order of the strings defined in the tuning
* Use '.' to skip a string
* Use 'x' to play a muted note (not implemented)
* Use '~' to rest
* Use '-' to repeat the previous chord
* Measures can be seperated with '|'. This makes it easier to read but has no impact on the final result, and measures are not verified to be valid
* Use _ to identify frets 10 and above
* Use N followed by a note length to change in the middle of a series of notes
* Examples:
    * 202 - Play the 6th string fret 2, the 5th string open, and the 4th string fret 2 all together
    * .2 - Play only the 5th string fret 2
    * 222222 - Play all strings fret 2 at the same time
    * 2.2.2 - Play the 6th string, 4th string, and 2nd string fret 2 at the same time
    * 2\_10\_2 - Play the 6th string fret 2, the 5th string fret 10, and the 4th string fret 2 at the same time
    * 2 2 2 - Play the 6th string fret 2, 3 times in a row
    * N1/2 2 N1/4 2 2 - Paly the 6th string fret 2 for a half note, then the 6th string fret 2 twice with quarter notes

### Sample

```
Tuning E2 A2 D3 G3 B3 E4

File std1.mid
Measures 4/4
Notes 1/8
Tempo 80
Attack 30
Instrument 28
2 .2 ..0 .2 2 .2 ..0 .2 | 2 .0 ..0 .0 2 .0 ..0 .0 | 0 .2 ..2 .2 0 .2 ..2 .2 | 2 .0 ..4 .0 2 .0 ..2 .0
```

## Authors

* **Craig St. Jean** - https://github.com/craigstjean

## License

This project is licensed under the BSD License - see the [LICENSE](LICENSE) file for details

## Acknowledgments

* [ANTLR4](https://www.antlr.org)
* [midifile](https://github.com/craigsapp/midifile)

