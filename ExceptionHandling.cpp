#include<iostream>
#include <exception>
#include <bits\stdc++.h>

using namespace std;

int main()
{
    cout << "Hello World ****" <<endl;

    vector<int> V{3,0,5,0,1,2,0};
    vector<int> result;

    for (int i = 0; i < V.size(); i++) {
    try {

        if (V[i] == 0) {
            throw "divide by zero error";
        }
        else
        {
            result.push_back(10 / V[i]);
            //cout << result[i] << endl;
        }
    }
        catch(const char *c)
        {
            cout << "exception is :: " << c << endl;
        }
        //cout << result[i] << endl;
    }
//
//    for(auto x : result)
//    {
//        cout << x << endl;
//    }



    return 0;
}
