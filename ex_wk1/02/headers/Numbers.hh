#ifndef INCLUDED_NUMBERS_H_
#define INCLUDED_NUMBERS_H_

#include <iosfwd>
#include <initializer_list>

class Numbers
{
    friend std::ostream &operator<<(std::ostream &out, Numbers &numbers);

    friend Numbers operator+(Numbers const &lhs, Numbers const &rhs);
    friend Numbers operator-(Numbers const &lhs, Numbers const &rhs);

    friend Numbers operator*(Numbers const &lhs, int const rhs);
    friend Numbers operator*(int const lhs, Numbers const &rhs);
    friend Numbers operator/(Numbers const &lhs, int const rhs);



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

        int &operator[](size_t idx);                       //Source code found in opIdx.cc
        int const &operator[](size_t idx) const;           //Source code found in csOpIdx.cc

        bool operator==(Numbers const &other) const;
        bool operator!=(Numbers const &other) const;

        Numbers &operator+=(Numbers const &rhs);
        Numbers &operator-=(Numbers const &rhs);
        
        Numbers &operator*=(int const rhs);
        Numbers &operator/=(int const rhs);

    private:
        void boundary(size_t idx) const;
	    int &operatorIndex(size_t idx) const;

        void add(Numbers const &rhs);
        void minus(Numbers const &rhs);
        void times(int const rhs);
        void division(int const rhs);
};

#endif