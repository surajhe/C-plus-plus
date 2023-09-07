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
