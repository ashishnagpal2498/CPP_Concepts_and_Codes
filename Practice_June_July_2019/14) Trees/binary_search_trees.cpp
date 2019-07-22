//BST 
#include<iostream>
#include <cmath>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
node* insertNode(node*root,int d)
{
    if(root==NULL)
    {
        // Create the node and return
        root = new node(d);
        return root;
    }
    if(root->data<d)
    {
       root->right = insertNode(root->right,d);
    }
    else
    {
       root->left = insertNode(root->left,d);
    }
    return root;
}
void BuildTree(node*&root)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        root = insertNode(root,d);
        cin>>d;
    }
}
void printTree(node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}
bool search(node*root,int key)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==key)
    {
        return true;
    }
    else if(root->data>key)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
}

//Height Balanced Tree -
class myPair{
public:
    bool isBalanced;
    int height;
    myPair()
    {
        isBalanced = true;
        height = 0;
    }
};

myPair balanceTree(node*root)
{
    myPair p;
    if(root==NULL)
    {
        return p;
    }

    myPair leftTree = balanceTree(root->left);
    myPair rightTree = balanceTree(root->right);

    p.height = 1+ max(leftTree.height,rightTree.height);
    if(abs(leftTree.height-rightTree.height)<=1&&leftTree.isBalanced&&rightTree.isBalanced)
    {
        p.isBalanced = true;
    }
    else
    {
        p.isBalanced = false;
    }
    return p;
}

//Catalan's Number ------

int countBst(int n)
{
    if(n<=0)
        return 0;
    int ans =0;
    for(int i=0;i<n;i++)
    {
        int ans1 = countBst(i-1);
        int ans2 = countBst(n-i-1); 
        ans += ans1*ans2;
    }
    return ans;
}

node* findNode(node*root)
{
    if(root->right==NULL)
    {
        return root;
    }
   return findNode(root->right);
}

node* deleteBst(node*root,int k)
{
    if(root==NULL) return NULL;

    if(root->data==k)
    {
        //deletion takes place here
        if(root->left==NULL&&root->right==NULL)
        {
            //leaf node -
            node* waste = root;
            delete waste;
            return NULL;
        }
        else if(root->left!=NULL&&root->right==NULL)
        {
            node* rleft = root->left;
            delete root;
            return rleft;
        }
        else if(root->left==NULL&&root->right!=NULL)
        {
            node* rright = root->right;
            delete root;
            return rright;

        }
        else
        {
            //2 Nodes exist -
            node* replacement = findNode(root->left);
            root->data = replacement->data;
            //
            root->left = deleteBst(root->left,replacement->data);
        }
    }
    else if(root->data>k)
    {
        root->left = deleteBst(root->left,k);
        
    }
    else
    {
        root->right = deleteBst(root->right,k);
    }
    return root;
}

node* balancedBst(int*arr,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid = (s+e)/2;
    node*root = new node(arr[mid]);
    root->left = balancedBst(arr,s,mid-1);
    root->right = balancedBst(arr,mid+1,e);
    return root;
}

bool isBst(node*root,int upperBound=1000000,int lowerBound=-1000000)
{
    if(root==NULL) return true;

    if(root->data<upperBound&&root->data>lowerBound&&isBst(root->right,upperBound,root->data)&&isBst(root->left,root->data,lowerBound))
    {
        return true;
    }
    return false;
}


int main(int argc, char const *argv[])
{
    node* root = NULL;
    BuildTree(root);
    printTree(root);
    int key;
    cin>>key;
    search(root,key) ? cout<<"Key Found"<<endl : cout<<"Key Not Found"<<endl;
    cout<<balanceTree(root).isBalanced<<endl;
   // cout<<countBst(3)<<endl;
    cout<<"Enter element to be deleted "; cin>>key;
    root = deleteBst(root,key);
    cout<<endl;
    printTree(root);
    cout<<endl<<"Creating BST OUT OF ARRAY  "<<endl;
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    node*root2 = balancedBst(arr,0,n-1);
    printTree(root2);
    cout<<endl;
    isBst(root2) ? cout<<"YES IT IS BST "<<endl : cout<<"IT IS NOT A BST "<<endl;
    return 0;
}