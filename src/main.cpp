#include <iostream>

#include <antlr4-runtime.h>

#include <MidiFile.h>
#include <Options.h>

#include "TabsLexer.h"
#include "TabsParser.h"
#include "TabsBaseVisitor.h"

using namespace antlr4;

int main(int argc, const char **argv)
{
    smf::Options options;
    
    std::ifstream stream;
    stream.open(argv[1]);
    
    ANTLRInputStream input(stream);
    TabsLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    TabsParser parser(&tokens);    
    TabsParser::FileContext* tree = parser.file();
    TabsBaseVisitor visitor;
    antlrcpp::Any tabs = visitor.visitFile(tree);
    
    return 0;
}
