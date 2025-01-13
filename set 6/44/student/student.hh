#ifndef STUDENT_HH
#define STUDENT_HH

#include <cstddef>
#include <fstream>
#include <cstring>

struct Student 
{
    std::string d_name;
    std::string d_lastName;
    std::string d_studentN;  
    std::string d_grade;
    //static size_t maxNameChars;

    Student() = default;
    //Student(Student const &other); //copy constructor
    //Student(Student &&other); //move constructor
    //needed for the copy STL algorithm

    friend std::istream &operator>>(std::istream &in, Student &rhs);
    friend std::ostream &operator<<(std::ostream &out, Student const &rhs);
    bool operator<(Student const &other);

    private:
        void setUp(std::string const &line);

};

std::istream &operator>>(std::istream &in, Student &rhs);
std::ostream &operator<<(std::ostream &out, Student const &rhs);

/*inline Student::Student(Student const &other)
:
    d_name (other.d_name),
    d_lastName (other.d_lastName),
    d_studentN (other.d_studentN),
    d_grade (other.d_grade)
{}

inline Student::Student(Student &&other)
:
    d_name (move(other.d_name)),
    d_lastName (move(other.d_lastName)),
    d_studentN (move(other.d_studentN)),
    d_grade (move(other.d_grade))
{
    other.d_name = std::string();
    other.d_lastName = std::string();
    other.d_studentN = std::string();
    other.d_grade = std::string();
}*/

#endif