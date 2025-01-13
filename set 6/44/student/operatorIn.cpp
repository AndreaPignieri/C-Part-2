#include "student.ih"

std::istream &operator>>(std::istream &in, Student &rhs)
{
    string line; //all the info of a student
    getline(in, line);

    rhs.setUp(line); //setUp to construct the object properly

    return in;
}