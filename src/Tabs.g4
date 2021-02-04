grammar Tabs ;

@lexer::members {
    bool ignore = true;
}

/*
 * Parser Rules
 */
tabs       : line+ EOF ;
line       : (tuning | file | instrument | attack | measures | notes | tempo | line_chg | chords) NEWLINE ;
tuning     : TUNING NOTE* ;
file       : FILE FILENAME ;
instrument : INSTRUMENT NUMBER ;
attack     : ATTACK NUMBER ;
measures   : MEASURES NUMBER SEP NUMBER ;
notes      : NOTES NUMBER SEP NUMBER ;
tempo      : TEMPO NUMBER ;
line_chg   : LINE_CHG NUMBER ;
chords     : (EMPTY | REST | REPEAT | NUMBER_SEP | NUMBER | note_chg | WHITESPACE)* ;
note_chg   : NOTE_CHANGE NUMBER SEP NUMBER ;

/*
 * Lexer Rules
 */
TUNING     : 'Tuning' { ignore = true; } ;
FILE       : 'File' { ignore = true; } ;
INSTRUMENT : 'Instrument' { ignore = true; };
ATTACK     : 'Attack' { ignore = true; };
MEASURES   : 'Measures' { ignore = true; } ;
NOTES      : 'Notes' { ignore = true; } ;
TEMPO      : 'Tempo' { ignore = true; } ;
LINE_CHG   : 'Line' { ignore = true; } ;

NUMBER     : [0-9]+ ;
SEP        : '/' ;

EMPTY      : '.' ;
REST       : '~' ;
REPEAT     : '-' ;
NUMBER_SEP : '_' ;

NOTE       : [A-Ga-g][b#]?[1-8] ;
FILENAME   : [A-Za-z0-9_.]+ '.mid' 'i'? ;
NOTE_CHANGE : 'N' ;

NEWLINE    : ('\r'? '\n' | '\r')+ { ignore = false; } ;
WHITESPACE : (' ' | '\t') { if (ignore) skip(); } ;
MEASURE_SP : '|' -> skip ;
