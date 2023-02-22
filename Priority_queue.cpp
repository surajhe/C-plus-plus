#include<iostream>
#include<queue>
#include<vector>


// stack internally implemented using deque
// priority_queue internally uses vector

// A max heap is a data structure in which each child node is less than or equal to its parent node.
// A min heap is a similar type of data structure where each child node is greater
// than or equal to its parent node.

using namespace std;

class Point
{
public:
    int x, y;

    Point(int a, int b):x(a),y(b){};

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
};

class myComparator
{
public:
    int operator() (Point &P1, Point &P2)
    {
        return P1.getX() > P2.getX();   // min heap
        //return P1.getX() < P2.getX();   // max heap
    }
};

int main()
{
    priority_queue<Point, vector<Point>, myComparator> pq;

    pq.push(Point(10,2));
    pq.push(Point(2,1));
    pq.push(Point(15,5));

    while(!pq.empty())
    {
        Point p = pq.top();
        cout << "X is:  " << p.getX() << "   Y is:"<< p.getY() << endl;
        pq.pop();
    }



    return 0;
}
