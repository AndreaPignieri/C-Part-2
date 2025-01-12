#include "main.ih"
//initialize static variable
std::mt19937 Random::s_engine(std::time(0));

int main(int argc, char *argv[])
{
    try
    { 
        //ensure correct number of args
        if (argc != 4)
            throw string("Wrong No. of args");
        
        //convert arguments to size_t
        size_t amount = stoul(argv[1]);
        size_t lRange = stoul(argv[2]);
        size_t rRange = stoul(argv[3]);
        
        //ensure range is appropriate
        if (lRange >= rRange)
            throw string("Min value > Max value");
  
        if (rRange - lRange + 1 < 2 * amount)
            throw string("Range too small");
            
        //initialize vector and objects
        vector<size_t> values;
        Random randG(lRange, rRange);
        FillUnique fU(randG);
        //fill vector
        fU.fill(values, amount);
        
        //copy values to ostream
        copy(values.begin(), values.end(), ostream_iterator<size_t>(cout, " "));
        cout << endl;
    }
    catch (const string &err)
    {
        cerr << "Error: " << err << endl;
        return 1;
    }
}
