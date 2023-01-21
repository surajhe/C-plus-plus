#include<iostream>
#include <bits\stdc++.h>

using namespace std;

class String {

private:
    char* m_Data;
    int m_Size;

public:

    String(){};
    String(char* string)
    {
        cout << "Constructor" << endl;
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    String(const String& obj)
    {
        cout << "Copy Constructor" <<endl;
        m_Size = obj.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, obj.m_Data, m_Size);
    }

    String& operator = (String& obj)
    {
        cout << "Copy Assignment Operator" <<endl;
        delete[] m_Data;
        m_Size = obj.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, obj.m_Data, m_Size);
    }

    String(String&& obj)
    {
        cout << "Move Constructor" <<endl;
        m_Size = obj.m_Size;
        m_Data = obj.m_Data;
        obj.m_Size = 0;
        obj.m_Data = nullptr;
    }

    String& operator = (String&& obj)
    {
        cout << "Move Assignment operator" << endl;
        delete[] m_Data;
        m_Size = obj.m_Size;
        m_Data = obj.m_Data;
        obj.m_Size = 0;
        obj.m_Data = nullptr;
    }

    void Print()
    {
        for(int i=0; i<m_Size; i++)
        {
            cout << m_Data[i];
        }
        cout << endl;
    }
};


int main()
{
    String str1("suraj");
    String str2;
    str2 = std::move(str1);
    str1.Print();
    str2.Print();
//    str1.Print();
//    String str2(str1);
//    str2.Print();
//    str1.Print();
//    String str3(std::move(str1));
//    str3.Print();
//
//    str1.Print();


    return 0;
}
