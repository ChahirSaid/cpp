#include <iostream>
#include <typeinfo>
using namespace std;

class A
{
    private:
        float i,j;
};

class B
{
    private:
        int x,y;
    public:
        B(int a, int b): x(a), y(b) {}
        int res()
        {
            return x+y;
        }
};

class C : public A
{

};

int main()
{
    // float a = 3.14f;
    // int b;
    // b = a;
    // cout << typeid(a).name() << "\t" << a << endl;
    // cout << typeid(b).name() << "\t" <<b << endl;
    A a;
    B *b;
    b = (B*) &a;
    cout << b->res();
}