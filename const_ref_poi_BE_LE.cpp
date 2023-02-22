#include<iostream>
#include <bits\stdc++.h>

using namespace std;

std::uint32_t big_to_little(std::uint32_t big_endian) {
    std::uint32_t little_endian = 0;
    little_endian |= (big_endian & 0xff) << 24;
    little_endian |= (big_endian & 0xff00) << 8;
    little_endian |= (big_endian & 0xff0000) >> 8;
    little_endian |= (big_endian & 0xff000000) >> 24;
    return little_endian;
}
template<typename T>

string itos(T i)
{
    stringstream s;
    s << i;
    string abc;
    s >> abc;
    cout << abc <<endl;
    return s.str();

}

//void opr(int x, int y, int &add, int &sub)
//{
//    add = x+y;
//    sub = x-y;
//}

int main()
{
//    string s1 = "Suraj";
//    string s2 = "Hengne";
//
//    char s3[] = "Me";
//    char s4[] = "Tu";
//    char *p = strcat(s3, s4);

    //const char *s = s1.c_str();

//    cout << p << endl;

const int z = 10;
    int * i;
    int const *h;
    const int *j;

//    h = &z;
//
//    cout << *h <<endl;

//
//    int *const m = &z;
//
//    const int const *n = &z;
 //   const int *const o = &z;
//
   int const *const q = &z;
//
//    const char *w = ss.c_str();
//
//
//    int add, sub;
//
//    opr(10,4, add, sub);
//
//    cout << add << "  " << sub << endl;
//    char hex[20];
//    sprintf(hex, "%X",  big_to_little(0x12345678));
//    cout << hex <<endl;
//
//    int i = 10;
//    int *p = &i;
//
//    int &r = i;
//    int var = 60;
//    p = &var;
//
//    r = var;


    // reference variable can not be reassigned
    // reference variable definition/creation and initialization must happen on same line
    // you can not do mathematical operations on reference like p++, (&r)++;
    // use reference in function parameter and return type

    // pass big objects as reference
    // object slicing is avoided by reference
    // multiple return from function
    // to achieve run type polymorphism
    // to modify local variables of caller function

//    cout << "p = " << *p << "  r is " << r << endl;

//      string str = itos(189.876);
//      const char *me = str.c_str();
//      cout << str << "     " << me << endl;

    return 0;
}
