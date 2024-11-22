#include "../headers/Numbers.ih"

void Numbers::boundary(size_t index) const
{
    if (index < d_size)
        return;
    std::ostringstream out;
    out  << "Numbers: boundary overflow, index = " <<
            index << ", should be < " << d_size << '\n';
    throw out.str();
}