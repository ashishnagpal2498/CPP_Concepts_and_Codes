//Trees - Generic Trees
#include<iostream>
#include<queue>
using namespace std;
class node{
public:
    int data;
    int noofchildren;
    node** nChild;
    node(int d,int n=0)
    {
        data = d;
        noofchildren =n;
        if(n!=0)
        {
            nChild = new node*[n];
        }
        else
        {
            nChild = NULL;
        }
    }
};
node* createTree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    int n;
    cin>>n;
    node* root = new node(d,n);
    for(int i=0;i<n;i++)
    {
        root->nChild[i] = createTree();
    }
    return root;
}
void postOrder(node*root)
{
    if(root==NULL) return;
    for(int i=0;i<root->noofchildren;i++)
    {
        postOrder(root->nChild[i]);
    }
    cout<<root->data<<" ";
}
void levelOrder(node*root)
{
    if(root==NULL) return;
    queue<node*> q1;
    q1.push(root);
    while(!q1.empty())
    {
        //take out the element on the front - pop
        //print
        node* f = q1.front();
        q1.pop();
        cout<<f->data<<" ";
        for(int i=0;i<f->noofchildren;i++)
        {   if(f->nChild[i]!=NULL)
            q1.push(f->nChild[i]);
        }
    }
}
void printTree(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->noofchildren;i++)
    {
        printTree(root->nChild[i]);
    }
}
int main()
{
    node* root =NULL;
    root = createTree();
    printTree(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrder(root);
    return 0;
}