#include "numbers.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

// Constructor: size_t -> Zero-initialized
Numbers::Numbers(size_t size)
    : d_size(size), d_nums(new int[size]())
{}

// Constructor: size_t, int -> Initialized with value
Numbers::Numbers(size_t size, int value)
    : d_size(size), d_nums(new int[size])
{
    std::fill(d_nums, d_nums + size, value);
}

// Constructor: size_t, int * -> Initialized with array values
Numbers::Numbers(size_t size, int *values)
    : d_size(size), d_nums(new int[size])
{
    std::copy(values, values + size, d_nums);
}

// Constructor: initializer list -> Initialized with initializer list values
Numbers::Numbers(std::initializer_list<int> iniList)
    : d_size(iniList.size()), d_nums(new int[iniList.size()])
{
    std::copy(iniList.begin(), iniList.end(), d_nums);
}

// Copy constructor
Numbers::Numbers(Numbers const &other)
    : d_size(other.d_size), d_nums(new int[other.d_size])
{
    std::copy(other.d_nums, other.d_nums + other.d_size, d_nums);
}

// Move constructor
Numbers::Numbers(Numbers &&tmp) noexcept
    : d_size(tmp.d_size), d_nums(tmp.d_nums)
{
    tmp.d_size = 0;
    tmp.d_nums = nullptr;
}

// Destructor
Numbers::~Numbers()
{
    delete[] d_nums;
}

// Swap function
void Numbers::swap(Numbers &other)
{
    std::swap(d_size, other.d_size);
    std::swap(d_nums, other.d_nums);
}

// Copy assignment
Numbers &Numbers::operator=(Numbers const &other)
{
    if (this != &other)
    {
        Numbers temp(other);
        swap(temp);
    }
    return *this;
}

// Move assignment
Numbers &Numbers::operator=(Numbers &&tmp) noexcept
{
    if (this != &tmp)
    {
        delete[] d_nums;
        d_size = tmp.d_size;
        d_nums = tmp.d_nums;
        tmp.d_size = 0;
        tmp.d_nums = nullptr;
    }
    return *this;
}

// Index operators
int &Numbers::operator[](size_t idx)
{
    if (idx >= d_size)
        throw std::out_of_range("Index out of range");
    return d_nums[idx];
}

int const &Numbers::operator[](size_t idx) const
{
    if (idx >= d_size)
        throw std::out_of_range("Index out of range");
    return d_nums[idx];
}

// Insertion operator
std::ostream &operator<<(std::ostream &out, Numbers const &numbers)
{
    for (size_t i = 0; i < numbers.d_size; ++i)
    {
        if (i > 0)
            out << ' ';
        out << numbers.d_nums[i];
    }
    return out;
}

// Comparison operators
bool Numbers::operator==(Numbers const &other) const
{
    if (d_size != other.d_size)
        return false;
    return std::equal(d_nums, d_nums + d_size, other.d_nums);
}

bool Numbers::operator!=(Numbers const &other) const
{
    return !(*this == other);
}

// Arithmetic compound assignment operators
Numbers &Numbers::operator+=(Numbers const &rhs)
{
    if (d_size != rhs.d_size)
    {
        std::cerr << "Sizes are unequal, += operation ignored\n";
        return *this;
    }
    for (size_t i = 0; i < d_size; ++i)
        d_nums[i] += rhs.d_nums[i];
    return *this;
}

Numbers &Numbers::operator-=(Numbers const &rhs)
{
    if (d_size != rhs.d_size)
    {
        std::cerr << "Sizes are unequal, -= operation ignored\n";
        return *this;
    }
    for (size_t i = 0; i < d_size; ++i)
        d_nums[i] -= rhs.d_nums[i];
    return *this;
}

Numbers &Numbers::operator*=(int rhs)
{
    for (size_t i = 0; i < d_size; ++i)
        d_nums[i] *= rhs;
    return *this;
}

Numbers &Numbers::operator/=(int rhs)
{
    if (rhs == 0)
    {
        std::cerr << "Division by zero is undefined, /= operation ignored\n";
        return *this;
    }
    for (size_t i = 0; i < d_size; ++i)
        d_nums[i] /= rhs;
    return *this;
}

// Plain binary operators
Numbers operator+(Numbers const &lhs, Numbers const &rhs)
{
    if (lhs.d_size != rhs.d_size)
    {
        std::cerr << "Sizes are unequal, + operation ignored\n";
        return lhs; // Return the left-hand side unchanged
    }
    Numbers result(lhs);
    result += rhs;
    return result;
}

Numbers operator-(Numbers const &lhs, Numbers const &rhs)
{
    if (lhs.d_size != rhs.d_size)
    {
        std::cerr << "Sizes are unequal, - operation ignored\n";
        return lhs; // Return the left-hand side unchanged
    }
    Numbers result(lhs);
    result -= rhs;
    return result;
}

Numbers operator*(Numbers const &lhs, int rhs)
{
    Numbers result(lhs);
    result *= rhs;
    return result;
}

Numbers operator*(int lhs, Numbers const &rhs)
{
    return rhs * lhs; // Reuse existing operator
}

Numbers operator/(Numbers const &lhs, int rhs)
{
    if (rhs == 0)
    {
        std::cerr << "Division by zero is undefined, / operation ignored\n";
        return lhs; // Return the left-hand side unchanged
    }
    Numbers result(lhs);
    result /= rhs;
    return result;
}
