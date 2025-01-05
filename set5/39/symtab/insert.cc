#include "symtab.ih"

// Reads ID-value pairs from the input stream, inserts them into the symbol table, 
// and reports duplicate IDs.
std::istream &Symtab::insert(std::istream &in)
{
    std::string line;
    size_t lineNumber = 0;

    while (std::getline(in, line)) // Read each line from the input stream.
    {
        ++lineNumber;
        std::istringstream stream(line);
        std::string id;
        int value;

        // Skip lines that do not contain a valid ID-value pair.
        if (!(stream >> id >> value))
            continue;

        // Check for duplicate IDs and ignore them if already defined.
        if (d_idMap.find(id) != d_idMap.end())
        {
            std::cerr << "line " << lineNumber << ": ignoring " << id << ", already defined\n";
            continue;
        }

        // Insert the new ID-value pair into the symbol table.
        size_t idx = d_idVector.size();
        d_idVector.push_back(id);
        d_idMap[id] = IdxValue{ idx, value };
    }

    return in;
}