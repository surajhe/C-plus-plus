#include <iostream>
#include <bits/stdc++.h>

using namespace std;



//void delete_seq(vector<int>& v, int start, int end)
//{
//  //  v.erase(v.begin()+start, v.end()+end);
////    for(auto it=v.begin()+start; it<=v.begin()+end; it++)
//    for(int i=start; i<=end; i++)
//    {
//       v[i] = v[i+1];
//       // v.erase(it);
//    }
//}

int main()
{
//    vector<int> v{9,8,7,3,6,4,1,5};
//    Divide(v);
//
//    for(auto i:v)
//    {
//        cout << i <<endl;
//    }



//========================================================================================
   // bool binary_search(vector<int> V, int key) {

//   vector<int> V{3,4,8,7,12,14,16,21,26};
//   int key = 3;
//        sort(V.begin(), V.end());
//
//        int high = V.size();
//        int low = 0;
//
//        while (low <= high)
//        {
//            int mid = (low + high)/2;
//            if (V[mid] == key)
//            {
//                cout <<"Key present" <<endl;
//            }
//
//            if (V[mid] < key)
//            {
//                low = mid + 1;
//            } else
//            {
//                high = mid - 1;
//            }
//        }

       // cout << "Key not present" <<endl;
    //}
    // ===============================================================================================
//
//    vector<int> v{1,4,6,1,2,7,8,9,4};
//    char arr[] = {'a','b','c','a','d','e','c','f','d'};
//
//    int size = sizeof(arr)/sizeof(arr[0]);
//
//    map<int,int> mp;
//
//    for(int i=0; i<size; i++)
//    {
//        mp[arr[i]]++;
//    }
//
//    for(auto i:mp)
//    {
//        //cout << i.first << "  " << i.second <<endl;
//        if(i.second > 1)
//        {
//            cout << static_cast<char>(i.first) <<endl;
//        }
//    }
//
//    int middle(Node* head)
//    {
//        Node* slow = head;
//        Node* fast = head;
//
//        while(fast != NULL && fast->next != NULL)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//
//        return slow->data;
//    }
//
//    Node* reverse(Node* head)
//    {
//        Node* h1,t
//        h1= t = head;
//        Node* h2 = NULL;
//
//        while(h1 != NULL)
//        {
//            h1 = h1->next;
//            t->next = h2;
//            h2 = t;
//            t = h1;
//        }
//
//        return h2;
//    }
//
//    bool detect_loop(Node* head)
//    {
//        Node* h1 = head;
//        Node* slow = head;
//        Node* fast = head;
//
//        while(fast->next != NULL && fast->next->next != NULL)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//
//            if(slow == fast)
//            {
//                while(slow != h1)
//                {
//                    slow = slow->next;
//                    h1 = h1->next;
//                }
//                return true;
//            }
//        }
//
//        return false;
//    }

    class TreeNode
    {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val):data(val), left(nullptr), right(nullptr){};
    };

    void insert(Node* root, int val)
    {
        if(root->data > val)
        {
            if(root->left == nullptr)
            {
                root->left = new TreeNode(val);
            }
            else
            {
                insert(root->left, val);
            }
        }
        else
        {
            if(root->right == nullptr)
            {
                root->right = new TreeNode*(val);
            }
            else
            {
                insert(root->right, val);
            }
        }
    }

    void inorder_traversal(TreeNode* root)
    {
        if(root == null)
            return;

        inorder_traversal(root->laft);
        cout << root->val <<endl;
        inorder_traversal(root->right);
    }

    TreeNode* SortedBT(vector<int> v)
    {
        TreeNode* root = new TreeNode(v[0]);

        for(auto i: v)
        {
            insert(root, i);
        }

        return root;
    }


    void(TreeNode* root, int val)
    {
        if (root->data > val) {
            if (root->left == nullptr) {
                root->left = new TreeNode(val);
            } else {
                insert(root->left, val);
            }
        }
    }
}


#include <iostream>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

// GNU = GCC (GNU compiler collection)
int main()
{
//    int z;    // any garbage value
//    int x();  // x = 1;
//    int y{};  // y = 0
//
//    cout << x <<endl;
//    cout << y <<endl;
//    cout << z <<endl;

//    cout << sizeof(int) <<endl;
//    cout << sizeof(long) <<endl;
//
//    long x = 9898676768765655444;

    //assert(sizeof(int) != sizeof(long));

//    Compiler designers tend to to maximize the performance of int arithmetic, making it the natural
//    size for the underlying processor or OS, and setting up the other types accordingly.
//    But the use of long int, since int can be omitted, it's just the same as long by definition.


//    unsigned int x = -1;
//    cout << x <<endl;
    //the result wraps around, leaving a very large number
    // (2^32-1 with the typical 32-bit integer size).

// new/malloc and delete/free
// new is keyword, malloc is function
// new calls constructor while malloc won't
// new keyword is typesafe, malloc returns *void
// on error new throws exception while malloc returns NULL.
// new is operator and can be overloaded malloc is function and can not be overloaded.

// C++ does not define the order of evaluation of function parameter.
// C++ does not define the order of construction of global variables.
// C++ does not define an order for when global variables are constructed during program startup

    std::multimap<int ,char> mp;

    mp.insert(make_pair(5,'a'));
    mp.insert(make_pair(3,'c'));
    mp.insert(make_pair(3,'b'));
    mp.insert(make_pair(300,'d'));
    mp.insert(make_pair(200,'e'));

    for(auto i:mp)
    {
        cout << i.first << "  " <<i.second <<endl;
    }

    class Node
    {
    public:
        int data;
        Node* next;

        Node(int val)
        {
            data = val;
            next = nullptr;
        }
    };

    Node* head = new Node(1);
    Node* second = new Node(2);
    head->next = second;


    TreeNode* inorder_traversal(TreeNode* root)
    {
        TreeNode* curr = root;
        if(curr == NULL)
        {
            return;
        }

        inorder_traversal(curr->left);
        cout << curr->data <<endl;
        inorder_traversal(curr->right);

        return root;
    }

    TreeNode* preorder_traversal(TreeNode* root)
    {
        TreeNode* curr = root;
        if(curr == NULL)
        {
            return;
        }

        cout << curr->data <<endl;
        preorder_traversal(curr->left);
        preorder_traversal(curr->right);

        return root;
    }

    TreeNode* postorder_traversal(TreeNode* root)
    {
        TreeNode* curr = root;
        if(curr == NULL)
        {
            return;
        }

        postorder_traversal(curr->left);
        postorder_traversal(curr->right);
        cout << curr->data <<endl;

        return root;
    }

    vector<int> inorder_Traversal(TreeNode* root)
    {
        vector<int> V;

        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while(curr != NULL && !stk.empty())
        {
            while(curr != NULL)
            {
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top();
            stk.pop();
            V.push_back(curr->val);

            curr = curr->right;
        }

        int main()
        {

        }

        bool binary_search(vector<int> V, int key)
        {
            sort(V.begin(), V.end());

            int high = V.size();
            int low = 0;

            while(low <= high)
            {
                int mid = (low+high)/2;
                if(mid == key)
                {
                    return true;
                }

                if(mid < key)
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }

            return false;
        }

    }








//    std::string str = "Hello World";
//
//    std::string &lvalue_ref = str;
//    std::string &&rvalue_ref = lvalue_ref.c_str();
//
//    rvalue_ref[0] = 'l';
//
//    cout << rvalue_ref << endl;
//    cout << lvalue_ref << endl;
//    //cout << "Hell6" << endl;

struct Vector
{
public:
    int* data;
    int size;

    Vector(const Vector& obj)
    {
        size = obj.size;
        data = new int(size);
        memcpy(data, obj.data,size);
    }

    Vector& operator = (Vector& obj)
    {
        delete[] data;
        size = obj.size;
        data = new int(size);
        memcpy(data, obj.data,size);
    }

    ~Vector()
    {
        delete data;
        data = nullptr;
    }
};

#include <mutex>

    class Value
    {
    private:
        int m_value{};
        //std::atomic<int> m_value=0;

    public:
        mutex mt;
        Value (){}
        //std::atomic<int>
        int getValue() const
        {
            return m_value;
        }
        void updateValue(int value)
        {
            std::lock_guard<mutex> lock(mt);
            m_value = value;
           // mt.unlock();
        }
    }

    void sum(std::promise<int>&& promise, int num)
    {
        int sum;
        while(num-- > 1)
        {
            sum += sum;
        }
        promise.set_value(sum);
    }

    int main()
    {
        std::promise<int> _promise;

        std::future<int> future = _promise.get_future();
        int val = 10;

        std::thread t1(sum, std::move(_promise), val);

        cout << future.get() <<endl;

        t1.join();

        return 0;
    }

    void fun1
    {
        // implementation
        result  = 1;
    }
    void fun2
    {
        while(result != 1)
        {
            std::this_thread::yield();
        }

        // implementation

        result = 2;
    }
    void fun3
    {
        while(result != 2)
        {
            std::this_thread::yield();
        }

        // implementation

        result = 3;
    }
    void fun4
    {
            while(result != 3)
            {
                std::this_thread::yield();
            }

            // implementation

            result = 4;

    }
    void fun5
    {
            while(result != 4)
            {
                std::this_thread::yield();
            }

            // implementation

            //result = 3;

    }



    int main()
    {
        int result = 0;

        std::thread t1(fun1);
        std::thread t1(fun2);
        std::thread t1(fun3);
        std::thread t1(fun4);
        std::thread t1(fun5);

        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();

        return 0;
    }

    std::future<int> future = std::async(std::launch::async, fun);

#include<coroutine>
    Generator numbers(int num)
    {
        for(int i=0; i<=num; i++)
        {
            co_yield i;
        }
    }

    int main()
    {
        auto gen = numbers(5);
        for(int i=0 ;i<= 5; i++)
        {
            cout << gen() <<endl;
        }

    }

    std::this_thread::sleep_for(std::chrono::seconds(1)); // pause for specified duration of time

    auto now = std::chrono::system_clock()::now(); // pause until specified time point.

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

    std::packaged_task<std::string> tsk([](std::string str){
        return "Me" + str;
    });

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

    return 0;
}
