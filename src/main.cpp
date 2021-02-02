#include <iostream>

#include "processor.h"

int main(int argc, const char **argv)
{
    if (argc < 2)
    {
        std::cerr << "USAGE: " << argv[0] << " file1 [file2...]\n";
        return -1;
    }

    for (auto i = 1; i < argc; ++i)
    {
        std::cout << "Processing '" << argv[i] << "'...\n";

        try
        {
            Processor processor(argv[i]);
            processor.execute();
        }
        catch(const OpenFileError& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}
