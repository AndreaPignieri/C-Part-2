#include "storage.ih"

shared_mutex Storage::s_mutex;

//defining the static member outside header file
//to give it an address