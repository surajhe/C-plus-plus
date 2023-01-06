// Template are the way to write generic programming.
// we pass data type as parameter to function or class.

#include <iostream>
using namespace std;

template <typename T>

T getMaxInt(T x, T y)
{
	return x>y ? x : y;
}

// char getMaxChar(char x, char y)
// {
// 	return x>y ? x : y;
// }

int main() {
	// your code goes here
	cout << getMaxInt<int>(20, 30) << endl;
	cout << static_cast<char>(getMaxInt<char>('a', 'x'));
	
	return 0;
}
