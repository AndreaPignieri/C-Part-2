#include "student.ih"

void Student::setUp(string const &line)
{
    auto first = find_if(line.begin(), line.end(), 
        [&](char letter)
        {
            return letter != '/t';
        }); //store the name without the extra space
    
    auto second = find(first, line.end(), '/t'); //search for the next tab after name
    auto third = find(second + 1, line.end(), '/t');//search for the next tab

    //use bac_insert_iterator bcs the strings are empty
    copy(first, second, back_insert_iterator(d_name));  //search between iterators set beforehand
    copy(second + 1, third, back_insert_iterator(d_studentN));
    copy(third + 1, line.end(), back_insert_iterator(d_grade));
    reverse_copy(d_name.rbegin(), find(d_name.rbegin(), d_name.rend(), ' '), back_insert_iterator(d_lastName));
    //we check in reverse to find the first space from the end, indicating the last name
    //because of the reverse iterators the name is reversed, so we fix using the reverse copy
}