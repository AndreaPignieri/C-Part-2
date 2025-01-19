#include "storage.ih"

condition_variable Storage::topop;
shared_mutex Storage::shMutex;
queue<string> Storage::s_lines;
atomic<bool> Storage::s_finished {false};
atomic<size_t> Storage::s_waiting { 0 };

//defining the static member outside header file
//to give it an address