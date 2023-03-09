// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
template<typename T>

class uniqueptr
{
    private:
    T* ptr;
    
    public:
       explicit uniqueptr(T* _ptr = nullptr)
       {
           ptr = _ptr;
       }
      // explicit unique_ptr(T* p):ptr(p){};
        
        uniqueptr(const uniqueptr& obj) = delete;
        uniqueptr& operator = (const uniqueptr& obj) = delete;
        
        uniqueptr(uniqueptr&& obj)
        {
            ptr = obj.ptr;
            obj.ptr = nullptr;
        }
        
        uniqueptr& operator = (uniqueptr&& obj)
        {
            if(ptr != nullptr)
            {
                delete ptr;
            }
            
            ptr = obj.ptr;
            obj.ptr = nullptr;
        }
        
        T& operator*()
        {
            return *ptr;
        }
        
        T* operator->()
        {
            return ptr;
        }
        
        ~uniqueptr()
        {
            if(ptr != nullptr)
            {
                delete ptr;
            }
        }
};

int main() {
    // Write C++ code here
    ///unique_ptr p(new int(10));
    //*p = 10;
    //unique_ptr<int> x(new int(20));
    uniqueptr<int> ptr1(new int(121));
    uniqueptr<int> ptr2;
    ptr2 = std::move(ptr1);
    
    cout << " " << *ptr2 << endl;

    return 0;
}
