#ifndef DURATIONCAST_HH
#define DURATIONCAST_HH

template <typename To, typename From>
double durationCast(From from)
{
    return static_cast<double>(from.count()) * 
                        To::period::den * From::period::num /
                        (To::period::num * From::period::den);
}

#endif