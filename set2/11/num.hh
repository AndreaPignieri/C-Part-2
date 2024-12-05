#ifndef NUM_HH
#define NUM_HH

class Num 
{
    int d_counter;

    public:
        Num(int value);
        Num(Num const &other); 

        int get();

    private:
        void swap(Num &other);
};

inline Num::Num(int value)
:
    d_counter(value)
{}

inline int Num::get()
{
    return d_counter;
}

#endif