#include <iostream>
using namespace std;

class Complex{
	private:
	int real, img;
	
	public:
	
	Complex(){}
	Complex(int x, int y) : real(x), img(y){}
	
	 Complex operator+ (Complex const &obj)
	{
	    Complex res;	
		res.real = real + obj.real;
		res.img = img + obj.img;
		return res;
	}
	
	void show()
	{
		cout << real << " + " << img << "i" << endl;
		//cout << img  << endl; 
	}
};

int main() {
	// your code goes here
	Complex c1(2,3), c2(7,8);
	
	Complex c3 = c1 + c2;
	
	c3.show();
	
	
	return 0;
}
