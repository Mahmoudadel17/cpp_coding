#include <iostream>

using namespace std;


struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}

TreeNode* newNode(int data)
{
    TreeNode* temp = new TreeNode;
    temp->val = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

 

};


class Bst
{
public: 
TreeNode* root = nullptr;
    Bst(){}
    ~Bst(){}
    void Add(int value)
{

    TreeNode* newNode = new TreeNode(value);
    TreeNode* temp =  root;
    TreeNode *prev = nullptr;
    if (root == NULL)
    {
        root = newNode;
        return;
    }

    while (temp!=nullptr)
    {
        prev = temp;
        if (value <= temp->val)
        {
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    if (value <= prev->val)
    {
        prev->left = newNode;
    }
    else{
        prev->right = newNode;
    }
}


};


class Solution
{
private:
    /* data */
public:


bool Symmetric(TreeNode* root1,TreeNode* root2)
{
    if (root1 == NULL && root2 == NULL){return true;}
    if(root1==NULL || root2==NULL){return false;}
    
    if (root1->val == root2->val)
    {
        return Symmetric(root1->left,root2->right) && Symmetric(root1->right,root2->left);

    }
    return false;
    
    
}

bool isSymmetric(TreeNode* root) {
    Symmetric(root,root);

}

};

int main()
{
    // test case 1
    //[1,2,2,3,4,4,3]
TreeNode * t1=t1->newNode(1);
t1->right=t1->newNode(2);
t1->left=t1->newNode(2);
t1->right->right=t1->newNode(3);
t1->right->left=t1->newNode(4);
t1->left->right=t1->newNode(4);
t1->left->left=t1->newNode(3);
Solution s1;


    if (s1.isSymmetric(t1))
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

// // test case 2
//[1,2,2,null,3,null,3]
TreeNode * t2=t2->newNode(1);
t2->right=t2->newNode(2);
t2->left=t2->newNode(2);
t2->right->right=t2->newNode(3);
t2->left->right=t2->newNode(3);


Solution s2;


    if (s2.isSymmetric(t2))
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }




    return 0;
}

/*

    int m;cout<<"enter number of test case: ";cin>>m;
    for (int i = 0; i < m; i++)
    {
        int n;
    cout<<"Enter number of element : ";cin>>n;
    cout<<"Enter element of first binary tree: ";
    int x;
    TreeNode* root1;TreeNode* root2;
    Bst b1,b2;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        b1.Add(x);
    }
    root1 = b1.root;
     cout<<"Enter element of second binary tree: ";
     int y;
      
    for (int i = 0; i < n; i++)
    {
        cin>>y;
        b2.Add(y);
    }
    root2 = b2.root;
    
    
    Solution s;
   
    if (s.isSameTree(root1,root2))
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }


    }
*/