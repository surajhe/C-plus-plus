
Difference between reference and pointer ?
-----------------------------------------------------

Definition: A reference is an alias or another name given to an already existing variable, while a pointer is a variable that stores 
the memory address of another variable.

Syntax: In C++, a reference is declared using the ampersand symbol (&), while a pointer is declared using the asterisk symbol (*).

Nullability: A pointer can be null, meaning it doesn't point to any valid memory location. A reference cannot be null and must 
always refer to a valid object.

Reassignment: A pointer can be reassigned to point to a different object, while a reference cannot be reseated once it is initialized.

Indirection: When using a pointer, you need to use the dereference operator (*) to access the value pointed to by the pointer. 
In contrast, a reference can be used like a regular variable without any special operators.

Type: A pointer can be declared as a pointer to a specific type, such as an integer pointer or a character pointer. 
A reference must always refer to an object of the same type as the referenced variable.

In summary, a reference is an alias for an already existing variable, while a pointer is a variable that stores the memory address 
of another variable. Pointers are more flexible and allow for nullability and reassignment, but they require explicit dereferencing. 
References are safer and easier to use but cannot be null and cannot be reseated after initialization.

=======================================================================================================================================
Explain the difference between int x; int x(); and int x{};
---------------------------------------------------------------

int x; any garbage value
int x(); // x=1
int{};   // x =0

=======================================================================
assert(sizeof(int) != sizeof(long)); Is this statement always true?
-------------------------------------------------------------------

//assert(sizeof(int) != sizeof(long));

//    Compiler designers tend to to maximize the performance of int arithmetic, making it the natural
//    size for the underlying processor or OS, and setting up the other types accordingly.
//    But the use of long int, since int can be omitted, it's just the same as long by definition.

==============================================================================================
What will the following line of code print out and why? unsigned int x = -1; std::cout << x;

//    unsigned int x = -1;
//    cout << x <<endl;
    //the result wraps around, leaving a very large number
    // (2^32-1 with the typical 32-bit integer size).

===========================================================================================

5. Can you explain the difference between new and new[]? Is it possible to delete memory using delete[] allocated within the new operator?
6. What is the difference between new/malloc or delete/free?	

// new/malloc and delete/free
// new is keyword, malloc is function
// new calls constructor while malloc won't
// new keyword is typesafe, malloc returns *void
// on error new throws exception while malloc returns NULL.
// new is operator and can be overloaded malloc is function and can not be overloaded.

int arr[]

unique_ptr<int[]> ptr(new int[10]);

=========================================================================================================

8. What is the evaluation order of the function parameters in C++?
9. What is the construction order of global variables?

// C++ does not define the order of evaluation of function parameter.
// C++ does not define the order of construction of global variables.
// C++ does not define an order for when global variables are constructed during program startup

============================================================================================================================	

Is it possible to call a virtual function inside of a constructor/destructor?


Is it possible to call a virtual function inside of a constructor/destructor in C++
Yes, it is possible to call a virtual function inside a constructor or a destructor in C++, but there are some important considerations to 
keep in mind.

In a constructor, calling a virtual function on the object being constructed may not work as unexpected because the object is not fully 
constructed yet. This is because the constructor of the base class is called before the derived class constructor, so the object is not fully 
initialized until after the constructor of the derived class is finished. Therefore, calling a virtual function in a constructor may lead to 
unexpected behavior or even undefined behavior.

In a destructor, calling a virtual function is generally safe because the object is fully constructed and can be safely destroyed. 
However, it's important to keep in mind that when the destructor is called, the object is already in the process of being destroyed, 
so any virtual functions called in the destructor should not modify the object's state or attempt to access any resources that may have 
already been released.

In summary, calling a virtual function inside a constructor or destructor is possible, but should be used with caution and 
with a full understanding of the potential risks and limitations.

==============================================================================================================================

What is specialization? How can it help to improve efficiency? 

What is specialization? How can it help to improve efficiency in C++.
In C++, specialization is a mechanism that allows you to define a special version of a template for a specific type or set of types. 
This can be useful for improving efficiency or adding functionality for a specific data type.

Specialization is declared using the keyword "template", followed by the template specialization keyword "specialization", 
and the type or set of types that the specialization applies to. For example, a specialization for a sorting function that works specifically 
with arrays of integers might look like this:

c
Copy code
template<>
void sort<int>(int* array, int size) {
  // implementation specific to sorting integers
}
In this case, the template parameter is "int", which specifies that the specialization applies to arrays of integers. 
The function takes an array of integers and its size as arguments, and performs a sorting operation specific to integers.

Specialization can help to improve efficiency in C++ by allowing you to write optimized code for specific types. For example, 
if you have a sorting algorithm that is highly optimized for integers, you can create a specialized version of the sorting algorithm 
specifically for integers. This can be more efficient than using a generic sorting algorithm that works with any type, because the specialized 
version can take advantage of specific properties of the integer data type to perform the sort more quickly.

In addition to improving efficiency, specialization can also be used to add functionality for specific types. For example, 
you might write a template class for a container that works with any type, but provide a specialized version for a specific type that 
adds additional functionality specific to that type.

Specialization should be used with caution, however, as it can result in code duplication and increased complexity. It is generally 
recommended to start with a generic template and only specialize if necessary for performance or functionality reasons.

===========================================================================================================================================

what is RAII ?
The RAII design is often used for controlling mutex locks in multi-threaded applications
In that use, the object releases the lock when destroyed. Without RAII in this scenario the potential for deadlock would be high and the 
logic to lock 
the mutex would be far from the logic to unlock it.

RAII stands for Resource Acquisition Is Initialization, which is a design pattern used in C++ to manage resources automatically. 
In C++, resources such as memory, file handles, locks, and other system resources are typically managed manually using low-level calls to 
allocate and deallocate them. However, manual management of resources can lead to problems such as memory leaks, dangling pointers, and other bugs.

RAII provides a solution to these problems by using a simple principle: resources should be acquired in the constructor of an object and 
released in its destructor. This ensures that resources are always properly managed, even in the face of exceptions or other errors. 
The key idea is to associate the lifecycle of a resource with the lifecycle of an object, and use the object's constructor and destructor 
to acquire and release the resource.

=============================================================================================================================================

How should runtime errors be handled in C++? What general approaches do you know?

1. Using try-catch blocks
2. Using assert()
3. Using return error codes
4. Using error handling libraries
5. Using signal handling

==================================================================================================================================================

What will happen if the exception will be thrown within a constructor in C++

The object that was being constructed will be destroyed: When an exception is thrown during the construction of an object, 
the object is not fully constructed. The parts of the object that were constructed before the exception occurred will be destructed, 
and the memory allocated for the object will be freed.

The exception will propagate: If the exception is not caught within the constructor, it will propagate to the calling function or 
code that initiated the construction of the object.

The destructor will not be called: Since the object was not fully constructed, the destructor of the object will not be called. 
This means that any resources that were allocated before the exception occurred will not be cleaned up.

It's important to handle exceptions in constructors carefully to avoid resource leaks and other problems. If the constructor allocates resources, 
such as memory or file handles, it should free those resources in its destructor. If an exception is thrown during construction, the destructor 
will not be called, so you must handle the exception carefully to ensure that the resources are properly freed. Additionally, it's a good 
practice to avoid throwing exceptions from constructors as much as possible, and to catch and handle any exceptions that may be thrown.

==================================================================================================================================================

         A -> print
		/ \ 
       B   C virtual
        \ /
         D		
		 
		 D d = new D();
		 d.print(); - aumbigious function call - compiler don't know from where to call print via B or C.


=================================================================================================================

What is the difference between using std::async and std::thread in C++ ?
In C++, both std::async and std::thread can be used for creating concurrent computations, but they differ in some important ways.

std::async is a higher-level abstraction for creating asynchronous tasks. It automatically creates a std::thread and manages the 
underlying details of task scheduling, returning a std::future object that represents the result of the computation. The std::future can 
be used to retrieve the result of the computation at a later time, or to check if the computation has completed.

std::async also allows for specifying a launch policy, which controls how the task is executed. The launch policy can be set to one of the following:

std::launch::async: The task is executed asynchronously on a new thread. This is the default behavior.
std::launch::deferred: The task is executed synchronously when its result is requested, possibly on the same thread as the caller.
One advantage of std::async is that it can potentially make more efficient use of system resources. For example, if the launch policy is set 
to std::launch::async, the implementation may choose to execute the task on an existing thread pool instead of creating a new thread.

On the other hand, std::thread is a lower-level abstraction that simply creates a new thread and runs a specified function on that thread. 
It returns nothing, and the caller is responsible for managing the thread and joining it when the computation is complete.

One advantage of std::thread is that it gives the programmer more control over the details of thread creation and management. For example, 
the programmer can choose to create a specific number of threads, assign specific tasks to specific threads, or control the priority of 
individual threads.

In summary, std::async is a higher-level abstraction that provides a simpler and more flexible interface for creating asynchronous tasks, 
while std::thread is a lower-level abstraction that provides more control over the details of thread creation and management.

=================================================================================================================================================
Explain the difference between sleep_for and sleep_until functions ?
 
std::this_thread::sleep_for(std::chrono::seconds(1)); // pause for specified duration of time

auto now = std::chrono::system_clock()::now(); // pause until specified time point.
	
===================================================================================================================================	
Is it possible to find out how many threads are available for parallel work using C++ tools?
	
Yes, it is possible to determine the number of available threads for parallel work using C++ tools. One common approach is 
to use the std::thread::hardware_concurrency() function, which is part of the C++ Standard Library.

================================================================================================================================
There are two mutexes. How do you securely acquire them?

std::scoped_lock(m1,m2); - it acquire mutexes deadlock free manner

std::lock(m1,m2);
std::try_lock(m1,m2);l

==================================================================================
What is std::promises used for ?

std::promise is a C++ class template that provides a way to communicate a value or an exception between two threads. 
It is part of the C++11 standard library and is typically used in conjunction with std::future, which is used to retrieve the value or 
exception from the std::promise object.

============================================================================================================
What is std::future used for ?

std::future is a C++ class template that represents a value that may not yet be available. 
It is part of the C++11 standard library and is typically used in conjunction with std::promise, 
which is used to set the value of the future.

====================================================================================================
packaged_task - 

std::packaged_task allows you to associate a function with a future object.
typically used to run a function asynchronously in a separate thread and then retrieve its result as a future object.


int sum(int val)
    {
        int sum;
        while(val-- > 1)
        {
            sum += val;
        }
        return sum;
    }

    std::packaged_task<int> tsk(sum);
    std::future<int> fut = tsk.get_value();

    std::thread t1(std::move(tsk), 10);

    cout << fut.get() <<endl;
    t1.join();
	
=========================================================================================================================================

Is it possible to return an exception from a thread? If yes, please explain.

using future promise and using std::exception_ptr

std::exception_ptr ex;

void fun(exception_ptr& excpt)
    {
       try
       {
           throw std::runtime_error("Some string");
       }
       catch(...)
       {
           ex = tsd::curent_exception();
       }
    }
    std::exception_ptr ex;

    std::thread t1(fun, std::ref(ex));
    t1.join();

    if(ex)
    {
        try {
            std::rethrow_exception(ex);
        }
        catch(...)
        {
            cout <<"caught exception in main thread" <<endl;
        }
    }

=========================================================================================================================

What are coroutines in C++

Coroutines in C++ are a way of implementing cooperative multitasking. They allow a function to be paused in the middle of its execution, 
and then resumed later from where it left off. 
This is achieved by creating a special type of function called a coroutine, which can be suspended and resumed at specific points in its execution.

Coroutines were introduced in C++20 as part of the standard library. They provide a powerful tool for writing asynchronous code, such as networking or GUI applications. 
Coroutines can be used to write non-blocking code that can perform I/O operations without blocking the execution of other code.

Coroutines in C++ are implemented using a new keyword called co_await, which is used to suspend the execution of a coroutine and wait for a particular operation to complete. 
The co_yield keyword is used to return a value from a coroutine and suspend its execution until it is resumed.

Here's a simple example of a coroutine in C++:

#include <iostream>
#include <coroutine>

using namespace std;

generator<int> generate_numbers(int start, int end) {
    for (int i = start; i <= end; i++) {
        co_yield i;
    }
}

int main() {
    auto numbers = generate_numbers(1, 10);
    for (auto n : numbers) {
        cout << n << endl;
    }
    return 0;
}
In this example, the generate_numbers function is a coroutine that generates a sequence of numbers from start to end. The co_yield keyword is used 
to suspend the execution of the coroutine and return the current value. 
The generator<int> type is used to represent the sequence of values produced by the coroutine.

The main function creates a sequence of numbers using the generate_numbers coroutine and prints them to the console. The for loop iterates over 
the sequence, resuming the execution of the coroutine each time a new value is required.

Overall, coroutines in C++ provide a powerful and flexible way of writing asynchronous and non-blocking code, and are a valuable addition to the 
C++ language.

===================================================================================================================================================

What is std::jthread? Can you explain the difference between std::jthread and std::thread in C++

std::jthread is a C++20 standard library class that represents a joinable thread. It provides a convenient way to create and manage threads 
in C++ by wrapping the std::thread class with additional functionality that makes it easier to use and safer to work with.

The main difference between std::jthread and std::thread is that std::jthread automatically joins the thread when the object is destroyed, 
whereas with std::thread, the programmer is responsible for calling join() or detach() to properly handle the thread's lifetime. This means 
that std::jthread provides a safer and more convenient way to work with threads, as the programmer doesn't have to worry about manually managing 
the thread's lifetime.

Additionally, std::jthread provides a few other benefits over std::thread, such as the ability to cancel the thread, wait for the thread to finish,
and the ability to set a thread name, which can be useful for debugging and profiling.

Here's an example of how to use std::jthread:

c
Copy code
#include <iostream>
#include <chrono>
#include <thread>

void some_function()
{
    std::cout << "Starting some_function..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Finished some_function." << std::endl;
}

int main()
{
    std::jthread my_thread(some_function);
    std::cout << "Main thread waiting..." << std::endl;
    my_thread.join();
    std::cout << "Main thread exiting." << std::endl;
    return 0;
}
In this example, some_function() is executed in a separate thread using std::jthread. The my_thread object is automatically joined 
when it goes out of scope at the end of main(). This ensures that the thread has finished executing before the program exits.


========================================================================================================================================================================================================

In computing, POSIX Threads, commonly known as pthreads, is an execution model that exists independently from a programming language, as well as a parallel execution model. 
It allows a program to control multiple different flows of work that overlap in time.
