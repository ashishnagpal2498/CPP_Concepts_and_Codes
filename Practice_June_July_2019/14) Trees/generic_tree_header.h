//genric Tree header
#include<iostream>
using namespace std;
class node{
    public:
        int data;
        int noofChild;
        node* *nChild;
        node(int d,int n=0)
        {
            data = d;
            noofChild = n;
            nChild = new node*[n];
        }
};

node* BuildTree()
{
    int d;
    cin>>d;
    int n;
    cin>>n;
    node* root = new node(d,n);
    for(int i=0;i<n;i++)
    {
        root->nChild[i] = BuildTree();
    }
    return root;
}
void printTree(node*root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    // printTree(root->left);
    // printTree(root->right)
    for(int i=0;i<root->noofChild;i++)
    {
        printTree(root->nChild[i]);
    }
}