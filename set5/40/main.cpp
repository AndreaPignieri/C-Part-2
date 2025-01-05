#include "Lines/lines.h"
#include "Utils/read_lines_from_stream.h"
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    std::ifstream in(argv[1]);
    if (!in)
    {
        std::cerr << "Can't open " << argv[1] << '\n';
        return 1;
    }

    // Test standalone utility function
    auto lines = readLinesFromStream(in);
    std::cout << "Lines read using utility function:\n";
    for (const auto &line : lines)
        std::cout << line << '\n';

    // Reset the stream for Lines testing
    in.clear();
    in.seekg(0, std::ios::beg);

    Lines lines1(in);

    std::cout << "\nLines1's lines:\n";
    for (const std::string &line : lines1.get())
        std::cout << line << '\n';

    {
        Lines lines2(in);
        std::cout << "\nLines2's lines:\n";
        for (const std::string &line : lines1.get(1)) // Access lines2 via lines1
            std::cout << line << '\n';
    }

    std::cout << "\nLines2 doesn't exist anymore. lines1.get(1) shows:\n";
    for (const std::string &line : lines1.get(1)) // lines2 has been destroyed
        std::cout << line << '\n';

    std::cout << "\nNon-existing 3rd Lines object's lines:\n";
    for (const std::string &line : lines1.get(3)) // Invalid index
        std::cout << line << '\n';

    return 0;
}
