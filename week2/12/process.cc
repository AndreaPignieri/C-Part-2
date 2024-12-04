#include "main.ih"

void process()
{
    Arg &arg = Arg::instance();

    if (arg.option(0, "help") || arg.option('h'))
    {
        usage();
        return;
    }

    size_t nArgs = arg.nArgs();
    for (size_t idx = 1; idx <= nArgs; ++idx) // Skip program name (idx=0)
    {
        string value = arg.arg(idx - 1);
        try
        {
            stoi(value); // Check if value can be converted to an integer
            cout << "Argument " << idx << ": " << value << endl;
        }
        catch (invalid_argument const &)
        {
            cerr << "Error: argument " << idx << " is not an integral number." << endl;
            throw static_cast<int>(idx); // Throw index of the invalid argument
        }
    }
}
