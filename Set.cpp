#include<iostream>
#include<set>
#include<functional>

// insertion, removal, search have logirathmic complexity
// Set - Set stores unique elements following specific order -
// stores elements in sorted order - uses BST for implementation
// Unoredred_set - stores elements in unsorted order - uses Hash Table for implementation
// search, insertion and removal have average constant-time complexity.
// Multiset - it stores duplicate elements in sorted order - implemented using Red Black Tree (Self balanced BST)

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
    set<Person, greater<>> S = {{55,"xxxx"}, {34, "Naman"}};
    for(const auto &i : S)
    {
        cout << "AGE " << i.age << "    NAME   " << i.name <<endl;
    }
    return 0;
}
