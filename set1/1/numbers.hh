#ifndef INCLUDED_NUMBERS_H_
#define INCLUDED_NUMBERS_H_

#include <iosfwd>
#include <compare>
#include <fstream>

class Numbers
{
    friend std::ostream &operator<<(std::ostream &out, Numbers const &numbers);
    friend bool operator==(Numbers const &lhs, Numbers const &rhs);
    friend std::strong_ordering operator<=>(Numbers const &rhs, Numbers const &lhs);
    size_t d_size = 0;
    int *d_nums = 0;

    public:
        explicit Numbers(size_t size);
    
        Numbers(size_t size, int value);
        Numbers(size_t size, int *values);
        Numbers(std::initializer_list<int> iniList);
        Numbers(Numbers const &other);
        Numbers(Numbers &&tmp);
        ~Numbers();

        void swap(Numbers &other);
        Numbers &operator=(Numbers const &other);
        Numbers &operator=(Numbers &&tmp);
        int &operator[](size_t index);
        int const &operator[](size_t index) const;

        // members of the public interface, like accessors
    
    private:
        size_t compare(Numbers const &rhs) const;
        int &indicator(size_t index) const;
        // support members for this class, if any
};

inline Numbers::Numbers(size_t size)
:
    d_size(size),
    d_nums(new int[size](0))
{}

inline Numbers::~Numbers()
{
    delete[] d_nums;
}

inline int &Numbers::indicator(size_t index) const
{
    return d_nums[index];
}

inline int const &Numbers::operator[](size_t index) const
{
    return indicator(index);
}
inline int &Numbers::operator[](size_t index)
{
    return indicator(index);
}

#endif
