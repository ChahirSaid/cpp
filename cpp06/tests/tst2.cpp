#include <iostream>

class A{
    public:
    virtual ~A(){};
};
class B : public A{
    public:
        int a = 12;
};

int main(){
    A pt;
    try{

        B &p = dynamic_cast<B &>(pt);
    }
    catch(...){}

}

// ptr -> ptr ;
// int >= 8 -> ptr;
//[01000000010010001111010111000011]
//00000011