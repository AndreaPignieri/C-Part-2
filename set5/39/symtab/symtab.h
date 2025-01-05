#ifndef INCLUDED_SYMTAB_
#define INCLUDED_SYMTAB_

#include <iosfwd>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>

class Symtab
{
    friend std::istream &operator>>(std::istream &in, Symtab &symtab);

    struct IdxValue
    {
        size_t idx;
        int value;
    };

    using IdMap = std::unordered_map<std::string, IdxValue>;
    using IdVector = std::vector<std::string>;
    using StrUMapConstIter = std::unordered_map<std::string, Symtab::IdxValue>::const_iterator;
    using StrUMapIter = std::unordered_map<std::string, Symtab::IdxValue>::iterator;

    IdMap d_idMap;
    IdVector d_idVector;

public:
    size_t operator[](std::string const &id) const;
    std::string const &operator[](size_t idx) const;

    int &operator()(std::string const &id);
    int &operator()(size_t idx);

    size_t size() const;

private:
    std::istream &insert(std::istream &in);
};

inline size_t Symtab::size() const
{
    return d_idVector.size();
}

inline std::istream &operator>>(std::istream &in, Symtab &symtab)
{
    return symtab.insert(in);
}

#endif
