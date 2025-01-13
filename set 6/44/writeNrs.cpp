#include "main.ih"

void writeNrs(ostream &out, vector<Student> const &students)
{
    vector<size_t> vIndex(students.size());
    //a vector of indices at the students vector

    iota(vIndex.begin(), vIndex.end(), 0);

    sort(vIndex.begin(), vIndex.end(), 
        [&](size_t const lhs, size_t const rhs)
        {
            return students[lhs].d_studentN < students[rhs].d_studentN;
            //sort Indices by student number of indexed student
        });

    for (size_t &Nrs : vIndex)
        out << students[Nrs] << '\n';
}