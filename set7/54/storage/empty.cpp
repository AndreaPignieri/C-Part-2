#include "storage.ih"

bool Storage::empty()
{
    shared_lock<shared_mutex> _(s_mutex);
    return d_lines.empty();
}
//its only reading data so shared_lock is enough,
//for the same reason it is safe to modify it, a thrown exception
//won't cause a change in d_lines queue