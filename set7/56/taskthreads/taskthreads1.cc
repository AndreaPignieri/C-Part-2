#include "taskthreads.ih"
//is... functions defined here to work as static
//since they werent playing nice when called directly 
//by constructor
bool isVowel(char c) {
    return isalpha(c) && strchr("aAeEiIoOuU", c);
}

bool isDigit(char c) {
    return isdigit(c);
}

bool isXdigit(char c) {
    return isxdigit(c);
}

bool isPunct(char c) {
    return ispunct(c);
}


//constructor takes filename and threading mode, creates
//array of task objects
TaskThreads::TaskThreads(const string &file, bool sequential)
    : d_fileName(file),
    d_tasks({
        Task(isVowel, "vowels"),
        Task(isDigit, "digits"),
        Task(isXdigit, "hexadecimals"),
        Task(isPunct, "punctuation")
    }),
    d_sequential(sequential)
{
}
