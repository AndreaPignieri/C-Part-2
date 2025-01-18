#include "student.ih"

bool Student::operator<(Student const &other)
{
    string lhs;
    string rhs;
    transform(d_lastName.begin(), d_lastName.end(), back_insert_iterator(lhs), ::tolower);
    transform(other.d_lastName.begin(), other.d_lastName.end(), back_insert_iterator(rhs), ::tolower);
    //make the names all small letters

    return lhs < rhs;
    //used in sort
}
    