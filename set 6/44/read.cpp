#include "main.ih"

void read(string const fileName, vector<Student> &students)
{
    ifstream in(fileName);

    Student temp; 
    while (in >> temp)
    {
        students.push_back(temp);
        temp = Student();
        //throw out the info of a student beforereading for the next one
    }

    sort(students.begin(), students.end());
    //sorting based on Last name
}