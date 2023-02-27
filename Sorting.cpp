#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Point
{
	public:
	int x,y;
	
	Point(int _x, int _y):x(_x),y(_y){};
	
	bool operator < (Point &P)
	{
		return x+y < P.x + P.y;
	}
	
};

int main() {
	// your code goes here
	std::vector<Point> V{Point(1,2), Point(3,1), Point(0,1)};
	std::sort(V.begin(), V.end());
	for(auto i :V)
	{
		cout << i.x << "  " << i.y <<endl;
	}
	
	cout << endl << endl;
	
	std::vector<int>Vec{4,5,6,7,3,2,1};
	sort(Vec.begin(), Vec.end(), greater<>());
	
	for(auto i : Vec)
	{
		cout << i <<endl;
	}
	return 0;
}
