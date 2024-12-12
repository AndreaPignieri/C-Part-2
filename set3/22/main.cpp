#include <iostream>
using namespace std;

// Base class definition
class Base {
public:
    virtual void hello() const {  // Use virtual for polymorphism
        cout << "Hello from Base!" << "\n";
    }
};

// Derived class definition
class Derived : public Base {
public:
    void hello() const override {  // Override the base class method
        cout << "Hello from Derived!" << "\n";
    }
};

// Function taking a Base reference
void caller(Base &obj) {
    obj.hello();  // Calls Base::hello or Derived::hello depending on dynamic type
}

int main() {
    Derived d;
    caller(d);  // Pass Derived as Base reference
}
