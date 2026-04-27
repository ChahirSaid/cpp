#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    cout << typeid(11f).name() << endl;
//     if (typeid(11.f) == typeid(float))
//         cout << "float\n";
}