#include <iostream>
using namespace std;

class Base{
	
	public:
	virtual void fun(int b)
	{
		cout << "Base class" << endl;
	}
};

class Derived : public Base
{
	public:
	void fun(int a) override
	{
		cout << "Derived class" << endl;
	}
};

int main() {
	Derived d;
	Base &b = d;
	b.fun(3);
	
	return 0;
}
