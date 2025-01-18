#include "student/student.hh"
#include "main.ih"

int main(int argc, char **argv)
try
{
    vector<Student> students;
    if (argc == 1)
        throw;
    read(*(argv + 1), students);
    writeNames(cout, students);
    cout << "\n\n";
    writeNrs(cout, students);
    
}
catch(...)
{
    return 1;
}