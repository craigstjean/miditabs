grammar Tabs ;

/*
 * Parser Rules
 */
tabs       : line+ EOF ;
line       : (tuning | file | measures | notes | tempo | line_chg | chords) NEWLINE ;
tuning     : TUNING NOTE* ;
file       : FILE FILENAME ;
measures   : MEASURES NUMBER SEP NUMBER ;
notes      : NOTES NUMBER SEP NUMBER ;
tempo      : TEMPO NUMBER ;
line_chg   : LINE NUMBER ;
chords     : (EMPTY | MUTE | NUMBER NUMBER_SEP? | note_chg)* ;
note_chg   : NOTE_CHANGE NUMBER SEP NUMBER ;

/*
 * Lexer Rules
 */
TUNING     : 'Tuning' ;
FILE       : 'File' ;
MEASURES   : 'Measures' ;
NOTES      : 'Notes' ;
TEMPO      : 'Tempo' ;
LINE       : 'Line' ;

NUMBER     : [0-9]+ ;
SEP        : '/' ;

EMPTY      : '.' ;
MUTE       : 'x' ;
NUMBER_SEP : '_' ;

NOTE       : [A-Ga-g][b#]?[1-8] ;
FILENAME   : [A-Za-z0-9_.]+ '.mid' 'i'? ;
NOTE_CHANGE : 'N' ;

NEWLINE    : ('\r'? '\n' | '\r')+ ;
WHITESPACE : (' ' | '\t') -> skip ;
MEASURE_SP : '|' -> skip ;

