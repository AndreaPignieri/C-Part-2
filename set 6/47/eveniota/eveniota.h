#ifndef INCLUDED_EVENIOTA_
#define INCLUDED_EVENIOTA_

//class to use iota with even ints
class EvenIota
{
    unsigned value;

    public:
        //constructor that ensures value is even
        EvenIota(unsigned val) : value(val & ~1){};

        //overload operators for iota functionality
        EvenIota &operator++();
        operator unsigned() const;
    private:
};
        
//ensure iterator goes up in 2s
EvenIota &EvenIota::operator++()
{
    value += 2;
    return *this;
}

//ensure object calls work
EvenIota::operator unsigned() const
{
    return value;
}
#endif
