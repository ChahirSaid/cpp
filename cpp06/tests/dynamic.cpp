#include <iostream>
using namespace std;

class A
{
	public:
	virtual void name(){}
};

class B : public A
{
	public:
	void name(){cout << "BBBB\n";}
};

class C : public A
{
	public:
	void name() {cout << "CCCC\n";}
};

int main()
{
	A* x = new B;
	B* y = dynamic_cast<B*>(x);
	if(y)
		y->name();
	C* z = dynamic_cast<C*>(x);
	if (!z)
		cout << "failed\n";
	B b;
	A& a = b;
	try
	{
		B& c = dynamic_cast<B&>(b);
		c.name();
		C& d = dynamic_cast<C&>(b);
		d.name();
	}
	catch(const std::bad_cast& e)
	{
		std::cerr << e.what() << " error\n";
	}
	

	B* hel = new B;
	A* lo = hel;
	A *lo2 = dynamic_cast<A*>(hel);
}