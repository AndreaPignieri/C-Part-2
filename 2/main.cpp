#include "numbers.hh"
#include <iostream>

using namespace std;

int main()
{
    Numbers n1( 5, 4);
    Numbers n2( 5, 3);
    Numbers n3( 7, 2);

    cout << n1 << '\n' << n2 + n3 << '\n' << 2 * n3 << '\n' << n3 / 0 << '\n';

    n2 *= 2;

    cout << n2 << '\n';

    n2 -= n1;
    n1 += n2;

    cout << n2 << '\n' << n1 << '\n';

    n3 /= 2;

    cout << n3;
}