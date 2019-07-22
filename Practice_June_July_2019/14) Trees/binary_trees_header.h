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