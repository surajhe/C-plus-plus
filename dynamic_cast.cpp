#include <iostream>
using namespace std;

class Base{
	
	virtual void print()
	{
		cout << "Base class" <<endl ;
	}
}

class Derived1 :public Base{
	
	virtual void print()
	{
		cout << "Derived1 class" <<endl ;
	}
}

class Derived2: public Base{
	
	virtual void print()
	{
		cout << "Derived2 class" <<endl ;
	}
}

int main() {
	// your code goes here
	// dynamic cast is used to identify correct downcast at runtime
	// if D1->B =then= B->D1    != XXXX B->D2
	Derived1 d1;
	
	Base *bp = dynamic_cast<Base*>(d1);
	
	Derived1 *d2 = dynmic_cast<Derived1*>(bp); 
	
	Derived2 *d2 = dynmic_cast<Derived2*>(bp); // returns nullptr
	
	return 0;
}
