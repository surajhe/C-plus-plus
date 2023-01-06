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
//	int x;
	public:
	void fun(int a)
	{
		cout << "Derived class" << endl;
	}
};

int main() {
	// your code goes here
	Base *b = new Derived();
	b->fun(3);
	
	return 0;
}
