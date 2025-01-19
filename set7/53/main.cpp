#include "multiout/multiout.hh"
    
int main(int argc, char **argv)
{
    MultiOut multi{ "3" };  // fixed for the exercise, use, e.g., argv[1]
                                // to specify the #threads as program argument
    multi.run();
}
        