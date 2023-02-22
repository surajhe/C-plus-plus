#include<iostream>
#include<map>
//#include<functional>

// map - unique key, sorted, implemented using Self-balanced Binary search tree(AVL/Red Black Tree)
// multimap - multiple keys, sorted, implemented using Self-balanced Binary search tree(AVL/Red Black Tree)

// unordered_map - unique key, unsorted, implemented using hash table, fastest insertion and removal
// unordered_multimap - multiple keys, unsorted, implemented using hash table, fastest insertion and removal

using namespace std;

class Person
{
public:
    int age;
    string name;

    //Person(int a, string n):age(a),name(n){};

    bool operator < (const Person &obj) const
    {
        return age < obj.age;
    }

    bool operator > (const Person &obj) const
    {
        return age > obj.age;
    }
};

int main()
{
    multimap<string, int> mm;
    mm.insert(make_pair("Suraj", 32));
    return 0;
}
