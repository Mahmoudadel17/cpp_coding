
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
    ~Bst(){
        cout<<"sabahhhh"<<endl;
        delete []root;
    }
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
    
public:


bool isSameTree(TreeNode* root1,TreeNode* root2)
{
    if (root1 == NULL && root2 == NULL){return true;}
    if(root1==NULL || root2==NULL){return false;}

    if (root1->val == root2->val)
    {
        
        return isSameTree(root1->left,root2->left) && isSameTree(root1->right,root2->right);

    }
    return false;
    
    
}


};



int main()
{
    // test case 1
TreeNode * t1=t1->newNode(1);//[1,2,3]
t1->right=t1->newNode(3);
t1->left=t1->newNode(2);

TreeNode * t2=t2->newNode(1);//[1,2,3]
t2->right=t2->newNode(3);
t2->left=t2->newNode(2);



Solution s1;

    if (s1.isSameTree(t1,t2))
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }


// test case 2
TreeNode * t3 = t3->newNode(1);//[1,2,0]
t3->right=t3->newNode(2);

TreeNode * t4 = t4->newNode(1);//[1,0,2]
t4->left=t4->newNode(2);

Solution s2;
    if (s2.isSameTree(t3,t4))
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }


// test case 3
TreeNode * t5=t5->newNode(1);//[1,2,1]
t5->right=t5->newNode(2);
t5->left=t5->newNode(1);


TreeNode * t6=t6->newNode(1);//[1,1,2]
t6->right=t6->newNode(1);
t6->left=t6->newNode(2);



Solution s3;
    if (s3.isSameTree(t5,t6))
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