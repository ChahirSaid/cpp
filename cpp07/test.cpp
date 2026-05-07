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

int main()
{
    A x(4);
    A y;
    y = x;
    x.print();
    y.print();
}
