#include "strings.ih"
//deep copy for COW
void Strings::deepCopy(size_t idx)
{
    if (!d_str[idx].unique()) //check for >1 owners
        //make deep copy
        d_str[idx] = make_shared<string>(*d_str[idx]);
}
