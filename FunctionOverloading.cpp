#include <iostream>
using namespace std;

class A{
	
	public:
	void fun(int a)
	{
		cout << "integer function" << endl;
	}
	
	int fun(double x)
	{
		cout << "double function" << endl;
		return 0;
	}
};

int main() {
	// your code goes here
	A a;
	a.fun(10);
	a.fun(20.4);
	
	return 0;
}
