#ifndef INCLUDED_NUMBERS_H_
#define INCLUDED_NUMBERS_H_

#include <iosfwd>
#include <initializer_list>

class Numbers
{
    size_t d_size = 0;
    int *d_nums = nullptr;

public:
    explicit Numbers(size_t size);
    Numbers(size_t size, int value);
    Numbers(size_t size, int *values);
    Numbers(std::initializer_list<int> iniList);
    Numbers(Numbers const &other);
    Numbers(Numbers &&tmp) noexcept;
    ~Numbers();

    void swap(Numbers &other);
    Numbers &operator=(Numbers const &other);
    Numbers &operator=(Numbers &&tmp) noexcept;

    // Accessors
    size_t size() const { return d_size; }

    // Index operators
    int &operator[](size_t idx);
    int const &operator[](size_t idx) const;

    // Arithmetic compound assignment operators
    Numbers &operator+=(Numbers const &rhs);
    Numbers &operator-=(Numbers const &rhs);
    Numbers &operator*=(int rhs);
    Numbers &operator/=(int rhs);

    // Arithmetic plain binary operators
    friend Numbers operator+(Numbers const &lhs, Numbers const &rhs);
    friend Numbers operator-(Numbers const &lhs, Numbers const &rhs);
    friend Numbers operator*(Numbers const &lhs, int rhs);
    friend Numbers operator*(int lhs, Numbers const &rhs);
    friend Numbers operator/(Numbers const &lhs, int rhs);

    // Insertion operator
    friend std::ostream &operator<<(std::ostream &out, Numbers const &numbers);

    // Comparison operators
    bool operator==(Numbers const &other) const;
    bool operator!=(Numbers const &other) const;

private:
    void allocateAndCopy(size_t size, int const *values);
};

#endif
