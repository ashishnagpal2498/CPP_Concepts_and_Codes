#include<iostream>
#include<string>
using namespace std;
class node{
public:
    int data;
    node*left;
    node* right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
void createTree(node*&root,string ct)
{   if(ct=="false")
    {
        return;
    }
    int d;
    cin>>d;
    root = new node(d);
    cin>>ct;
    createTree(root->left,ct);
    cin>>ct;
    createTree(root->right,ct);
}
void printTree(node*root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right); 
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
