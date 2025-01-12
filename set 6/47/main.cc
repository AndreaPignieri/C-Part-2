#include "main.ih"

int main()
{
    //initialize unsigned vector
    vector<unsigned> vec(10);
    
    //use iota with EvenIota to iterate in 2s
    iota(vec.begin(), vec.end(), EvenIota(0));
    
    //copy values to ostream to check correctness
    copy(vec.begin(), vec.end(), ostream_iterator<unsigned>(cout, " "));
    cout << endl;
}
