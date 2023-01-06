#include <iostream>
using namespace std;

template <typename T> 

class A{
	
	T x;
	
	public:
	
	void setx(T a)
	{
		x = a;
	}
	
	T getx()
	{
		return x;
	}
	
};

int main() {
	// your code goes here
	
	A <int>obj1;
	
	obj1.setx(4);
	cout << obj1.getx() << endl;   // vector<int> V;
	
	A <double>obj2;
	obj2.setx(3.44);
	cout << obj2.getx() << endl;
	
	return 0;
}
