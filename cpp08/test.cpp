#include <iostream>

template <typename T>
class Base {
protected:
    int x = 42;
};

template <typename T>
class Derived : public Base<T> {
public:
    void printX() {
        // std::cout << x << std::endl;  //wrong
        std::cout << this->x << std::endl; //right 
        // std::cout << Base<T>::x << std::endl; // right 
    }
};

int main() {
    Derived<int> d;
    d.printX();
    return 0;
}
