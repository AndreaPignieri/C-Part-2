#include "main.ih"

namespace
{
    char version[] = "1.00.00";

    Arg::LongOption longOptions[] =
    {
        Arg::LongOption{"required", Arg::Required},
        Arg::LongOption{"debug"},
        Arg::LongOption{"filenames", 'f'},
        Arg::LongOption{"help", 'h'},
        Arg::LongOption{"version", 'v'},
    };
    auto longEnd = longOptions + size(longOptions);
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("vha:bf:", longOptions, longEnd, argc, argv);
    cout << arg.basename() << '\n';
    arg.versionHelp(usage, version, 1);
    process(); // Call to process()
}
catch (...)
{
    cout << "done\n";
}