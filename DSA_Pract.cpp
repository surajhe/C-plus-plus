
   vector<int> v = {6,5, 3,9,7,6,5,4,3, 10};

    int start = 3;
    int end = 7;

    vector<int>:: iterator it1 = v.begin() + start;
    vector<int>:: iterator it2 = v.begin() + end;

    v.erase(it1, it2);  // TC - (n)
	
    for(auto i:v)
    {
        cout << i <<endl;
    }
	
======================================================================	
	
   vector<int> v{4,1,3,5,9,7,8,2,0};
    //std::map<int ,int> mp;
//    for(int i=0; i<=9; i++)
//    {
//        if(v[i] != i)
//        {
//            cout << i;
//            break;
//        }
//    }

    map<int,int> mp;

    for(int i=0; i<=9; i++)
    {
        mp[v[i]]++;
    }

    int num = 0;

    map<int,int>::iterator it;
    for(it=mp.begin(); it !=mp.end(); it++)
    {
       // cout << it->first << "   " <<it->second <<endl;
        if(it->first != num)
        {
            cout <<num << endl;
            break;
        }
        num++;
    }	
	
===============================================================================================

    char arr[] = {'a','b','c','a','d','e','c','f','d'};

    int size = sizeof(arr)/sizeof(arr[0]);

    map<int,int> mp;

    for(int i=0; i<size; i++)
    {
        mp[arr[i]]++;
    }

    for(auto i:mp)
    {
        //cout << i.first << "  " << i.second <<endl;
        if(i.second > 1)
        {
            cout << static_cast<char>(i.first) <<endl;
        }
    }

=================================================================================================	

    int middle(Node* head)
    {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

====================================================

    Node* reverse(Node* head)
    {
        Node* h1,t
        h1= t = head;
        Node* h2 = NULL;

        while(h1 != NULL)
        {
            h1 = h1->next;
            t->next = h2;
            h2 = t;
            t = h1;
        }

        return h2;
    }
	
=======================================================================

    bool detect_loop(Node* head)
    {
        Node* h1 = head;
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
            {
                while(slow != h1)
                {
                    slow = slow->next;
                    h1 = h1->next;
                }
                return true;
            }
        }
        
        return false;
    }

============================================================================================	

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
==========================================================================================================

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
// ==========================================================================
      
      
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
===================================================================================================

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

========================================================================================	
