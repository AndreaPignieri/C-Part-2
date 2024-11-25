#include "numbers.ih"

Numbers operator*(int lhs, Numbers const &rhs)
{//friend function calling the operator* with the correct order
    return (rhs * lhs);
}
