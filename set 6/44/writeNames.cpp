#include "main.ih"

void writeNames(ostream &out, vector<Student> &students)
{
    copy(students.begin(), students.end(), ostream_iterator<Student>(out, "\n"));  
    //use overloaded operator<< of Student
}