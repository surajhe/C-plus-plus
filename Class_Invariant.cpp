
// class invariant refers to some set of conditions or assertions thta need to hold throughout 
// the life of an object of class.
// These conditions verify that an object's behavior is justified during it's lifetime and that object maintains its well defined state as intended.


 #include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Pos
{
    int x,y;
    Pos(int _x, _y)
    {
        x = _x;
        y = _y;
    }
};

class Snake
{
    int width, height;
    Pos loc;
    void invariant()
    {
        assert(loc.x >= 0 && loc.x <= width);
        assert(loc.y >= 0 && loc.y <= height);
    }
    
    public:
        Snake(int _width, int _height, Pos _p)
        {
            width = _width;
            height = _height;
            loc.x = _p.x;
            loc.y = _p.y;
            invariant();
        }
    
};
  
