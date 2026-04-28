#include <iostream>
using namespace std;

int main()
{
	int x = 94;
	char *str = reinterpret_cast<char*>(&x);
	cout << *str << endl;

	int *ptr = &x;
	unsigned long adr = reinterpret_cast<unsigned long>(ptr);
	cout << adr << endl;
	int *ptr2 = reinterpret_cast<int *>(adr);
	cout << *ptr2 << endl;
}