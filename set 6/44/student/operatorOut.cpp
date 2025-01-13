 #include "student.ih"

std::ostream &operator<<(std::ostream &out, Student const &rhs)
{
    return out << rhs.d_name << '\t'<< rhs.d_studentN<< '\t' << rhs.d_grade;
}