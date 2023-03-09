// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
template<typename T>

class Counter
{
    int count = 0;
    public:
    
    Counter():count(0){};
    
    Counter(const Counter& obj) = delete;
    Counter& operator = (const Counter& obj) = delete;
    
    int get_count()
    {
        return count;
    }
    
    void operator++()
    {
        count++;
    }
    
    void operator--()
    {
        count--;
    }
    
    ~Counter(){};
};

class sharedptr
{
    private:
    T* ptr;
    Counter* count;
    
    public:
       explicit sharedptr(T* _ptr = nullptr)
       {
           ptr = _ptr;
           count = new Counter();
       }
       
       sharedptr(const sharedptr& obj)
       {
           ptr = obj.ptr;
           (*count)++;
       }
       
       sharedptr& operator = (const sharedptr& obj)
       {
           ptr = obj.ptr;
           (*count)++;
       }

        
        T& operator*()
        {
            return *ptr;
        }
        
        T* operator->()
        {
            return ptr;
        }
        
        ~sharedptr()
        {
            (*count)--;
            if(*count == 0)
            {
                delete ptr;
                delete count;
            }
            
        }
};

int main() {
    // Write C++ code here
    ///unique_ptr p(new int(10));
    //*p = 10;
    //unique_ptr<int> x(new int(20));
    sharedptr<int> ptr1(new int(121));
    sharedptr<int> ptr2;
    ptr2 = ptr1;
    
    cout << *ptr1 << " " << *ptr2 << endl;

    return 0;
}
