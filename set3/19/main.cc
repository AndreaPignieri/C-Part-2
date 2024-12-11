//Simple Base class
class Base
{
    public:
        ~Base();
};

//Simple Derived class
class Derived : public Base
{
    public:
	~Derived();
}


int main()
{
    //initialize object
    Derived derived;
}//object destroyed here
