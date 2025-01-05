#ifndef ADDRESS_HH
#define ADDRESS_HH

#include <unordered_map>
#include <utility>
#include <cstring>
#include <fstream>
#include <vector>
#include <set>

struct hashPair
{
    size_t operator()(std::pair<std::string, std::string> const &info) const;
};

class Address 
{
    std::unordered_map <std::pair<std::string, std::string>, 
                    std::vector<std::string>,
                    hashPair> d_data;

    public:
        Address() = default;

        ~Address() = default;

        friend std::ostream &operator<<(std::ostream &dest, const Address &rhs);
        friend std::istream &operator>>(std::istream &source, Address &rhs);

        size_t remove(std::string const &postalCode);

    private:
        std::ostream &insertInto(std::ostream &out) const;
        std::istream &insertFrom(std::istream &in);

        void addAddress(std::string &input, 
                        std::pair<std::string, std::string> &info);
        bool personExist(std::string &input, 
                        std::pair<std::string, std::string> &info);

        void fillSet(std::set<std::pair<std::string, std::string>> &postCodeSet);
        std::string stopCode(std::string const postalCode);
        bool eligible( std::set<std::pair<std::string,std::string>>::iterator const &idx, 
                        std::set<std::pair<std::string,std::string>>::iterator const &stop,
                        std::set<std::pair<std::string, std::string>> const &KeySet );

};

std::ostream &operator<<(std::ostream &dest, const Address &rhs);
std::istream &operator>>(std::istream &source, Address &rhs);

inline std::ostream &operator<<(std::ostream &dest, const Address &rhs)
{
    return rhs.insertInto(dest);
}

inline std::istream &operator>>(std::istream &source, Address &rhs)
{
    return rhs.insertFrom(source);
}

#endif
