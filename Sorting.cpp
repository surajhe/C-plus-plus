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
	
	// std::is_sort
	std::is_sort(Vec.begin(), Vec.end());
	std::is_sort(Vec.begin(), Vec.end(), greater<int>());
	
	// std::nth_element
	std::nth_element(Vec.begin(), Vec.begin()+3, Vec.end(), greated<int>()); //- to get 3rd largest element in vector. Vec[3]
	std::nth_element(Vec.begin(), Vec.begin()+ Vec.size()/2); // to get median of vector Vec[Vec.size()/2]
	
	//is_sorted_until - it tells uptil where array is sorted and returns position
	auto it = std::is_sorted_until(Vec.begin(), Vec.end());
	auto diff = distance(Vec.begin(), it);
	
	
	return 0;
}
