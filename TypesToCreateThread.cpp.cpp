// There are 5 ways to create thread in C++
// 1. Function pointer
// 2. lambda expression
// 3. Functor
// 4. member function
// 5. static member function


#include <iostream>
#include <thread>

using namespace std;

//void fun(int x)
//{
//    while(x > 0)
//    {
//        cout << x << endl;
//        x--;
//    }
//}
//int main()
//{
//    // Function pointer
//    std::thread t1(fun, 10);
//    t1.join();
//    return 0;
//}

//int main()
//{
//    auto fun = [](int x){
//        while(x > 0)
//        {
//            cout << x << endl;
//            x--;
//        }
//    };

    // Function pointer
//    std::thread t1([](int x){
//        while(x > 0)
//        {
//            cout << x << endl;
//            x--;
//        }
//        }, 10);
//    t1.join();
//    return 0;
//}

//class Base{
//public:
//    void operator ()(int x)
//    {
//        while(x > 0)
//        {
//            cout << x << endl;
//            x--;
//        }
//    }
//};
//
//int main()
//{
//    std::thread t(Base(), 10);
//    t.join();
//    return 0;
//}

//class Base{
//public:
//    void run(int x)
//    {
//        while(x > 0)
//        {
//            cout << x << endl;
//            x--;
//        }
//    }
//};
//
//int main()
//{
//    Base b;
//    std::thread t(&Base::run,&b, 10);
//    t.join();
//    return 0;
//}

class Base{
public:
    static void run(int x)
    {
        while(x > 0)
        {
            cout << x << endl;
            x--;
        }
    }
};

int main()
{
    Base b;
    std::thread t(&Base::run, 10);
    t.join();
    return 0;
}
