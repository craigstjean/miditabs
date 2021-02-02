#include <iostream>
#include "processor.h"

#include <antlr4-runtime.h>

#include "TabsLexer.h"
#include "TabsParser.h"

#include "midi_visitor.h"
#include "midi_commands.h"

using namespace antlr4;

void Processor::execute()
{
    ANTLRInputStream input(stream);
    TabsLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    TabsParser parser(&tokens);

    TabsParser::TabsContext* tree = parser.tabs();

    MidiVisitor visitor;
    MidiCommands commands = visitor.visitTabs(tree);

    for (auto command : commands.commands())
    {
        std::cout << command << std::endl;
    }
}
