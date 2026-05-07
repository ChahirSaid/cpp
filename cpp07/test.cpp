#include <iostream>
using namespace std;

class A
{
    private:
        int *a;
    public:
        A():a(NULL){}
        A(int x):a(new int(x)){}
        A(A& other)
        {
            if (other.a)
                a = new int(*other.a);
            else
                a = NULL;
        }
        A& operator=(A&other)
        {
            if (this != &other)
            {
                 if (other.a)
                {
                    if (!a)
                        a = new int;
                    *a = *other.a;
                }
                else
                {
                    delete a;
                    a = NULL;
                }
            }
           return *this;
        }
        ~A(){delete a;}
        void print()
        {
            if (a)
                cout << *a << endl;
            else
                cout << "NULL" << endl;
        }
};
template <typename T, typename U>

void ptest(T a, U b)
{
    cout << a << "\t";
    cout << b << endl;
}


int main()
{
    A x(4);
    A y;
    y = x;
    x.print();
    y.print();
    ptest(2,3.14);
    ptest<int>(2,3.14);
    ptest<int, int>(2,3.14);
    ptest<double>(2,3.14);
}
