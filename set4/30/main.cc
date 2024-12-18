#include <fstream>
#include "BiStream/BiStream.ih"

using namespace std;

int main()
{
    ofstream one("one");
    ofstream two("two");

    BiStream ms(one, two);

    ms << "Hello world" << endl;
}