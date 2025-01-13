#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <cstdlib>
#include <execution>
#include <functional>

using namespace std;

int main(int argc, char **argv)
{//argv + 1 is used to avoid sorting the name of the program

    sort (argv + 1, argv + argc, less<string>()); 

    //we use less<string> to promote the char * to strings
    //so that operator< applies to them with less we get ascending order

    copy (argv + 1, argv + argc, ostream_iterator<string>(cout, " "));
    //again the char * are promoted to strings with ostream_iterator<string>
    // " " ensures a gap between each char*
    cout << '\n';

    sort (argv + 1, argv + argc, greater<string>());
    copy (argv + 1, argv + argc, ostream_iterator<string>(cout, " "));
    // same idea as above, but greater is used for descending sorting
    cout << '\n';
}