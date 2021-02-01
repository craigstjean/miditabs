grammar Tabs ;

/*
 * Parser Rules
 */
tabs       : line+ EOF ;
line       : (tuning | file | measures | notes | tempo | chords) NEWLINE ;
tuning     : TUNING NOTE* ;
file       : FILE FILENAME ;
measures   : MEASURES NUMBER SEP NUMBER ;
notes      : NOTES NUMBER SEP NUMBER ;
tempo      : TEMPO NUMBER ;
chords     : (EMPTY | MUTE | NUMBER NUMBER_SEP?)* ;

/*
 * Lexer Rules
 */
TUNING     : 'Tuning' ;
FILE       : 'File' ;
MEASURES   : 'Measures' ;
NOTES      : 'Notes' ;
TEMPO      : 'Tempo' ;

NUMBER     : [0-9]+ ;
SEP        : '/' ;

EMPTY      : '.' ;
MUTE       : 'x' ;
NUMBER_SEP : '_' ;

NOTE       : [A-Ga-g][b#]?[1-8] ;
FILENAME   : [A-Za-z0-9_.]+ '.mid' 'i'? ;

NEWLINE    : ('\r'? '\n' | '\r')+ ;
WHITESPACE : (' ' | '\t') -> skip ;
MEASURE_SP : '|' -> skip ;

