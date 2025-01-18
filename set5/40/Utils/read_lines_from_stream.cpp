#include "read_lines_from_stream.h"

std::vector<std::string> readLinesFromStream(std::istream &in)
{
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(in, line) && !line.empty())
    {
        lines.push_back(line);
    }

    return lines;
}
