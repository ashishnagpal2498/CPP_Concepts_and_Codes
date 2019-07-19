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
int nodeCount_greater_X(node*root,int x)
{
    if(root==NULL)
        return 0;
    int res =0;
    if(root->data>x) res++;
    for(int i=0;i<root->noofchildren;i++)
    {
        int ans = nodeCount_greater_X(root->nChild[i],x);
        res+=ans;
    }
    return res;
}
int maxNode(node*root)
{
    //base case -
    if(root==NULL)
        return -10000000;
    int max_val = root->data;
    for(int i=0;i<root->noofchildren;i++)
    {
        int ans = maxNode(root->nChild[i]);
        max_val = max(max_val,ans);
    }
    return max_val;
}
void kthLevelPrint(node*root,int k)
{
    if(root==NULL||k<0)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->noofchildren;i++)
    {
        kthLevelPrint(root->nChild[i],k-1);
    }
}
void leverOrderInput(node* &root)
{
    int n;
    int d;
    cin>>d;
    if(d==-1)
    {
        return;
    }
    cin>>n;
    root = new node(d,n);
    queue<node*> q1;
    q1.push(root);
    while(!q1.empty())
    {
        node* f = q1.front();
        q1.pop();
        for(int i=0;i<f->noofchildren;i++)
        {
            cin>>d;
            if(d!=-1)
            {
                cin>> n;
                node * newnode = new node(d,n);
                f->nChild[i] = newnode;
                q1.push(newnode);
            }
            else
            {
                f->nChild[i] = NULL;
            }
        }
    }
}
int height(node*root)
{
    if(root==NULL) return 0;
    int h = 1;
    int ans = 0;
    for(int i=0;i<root->noofchildren;i++)
    {
        int smallans = height(root->nChild[i]);
        ans = max(smallans,ans);
    }

    return h+ans;
}
void levelOrder(node*root)
{
    if(root==NULL) return;
    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty())
    {
        //take out the element on the front - pop
        //print
        node* f = q1.front();
        q1.pop();
        if(f!=NULL)
        {   cout<<f->data<<" ";
            for(int i=0;i<f->noofchildren;i++)
            {   if(f->nChild[i]!=NULL)
            q1.push(f->nChild[i]);
            }
        }
        else
        {
            cout<<endl;
            if(!q1.empty())
            {
                q1.push(NULL);
            }
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
    // node* root =NULL;
    // root = createTree();
    // printTree(root);
    // cout<<endl;
    // postOrder(root);
    // cout<<endl;
    // levelOrder(root);
    // cout<<"levelOrder input "<<endl;
    node* root2 = NULL;
    leverOrderInput(root2);
    levelOrder(root2);
    cout<<"Maximum value Node  "<<maxNode(root2)<<endl;
    int x;
    cin>>x;
    cout<<"No of nodes Greater than X  "<<x<<" are  "<<nodeCount_greater_X(root2,x);
    int k; cin>>k;
    cout<<"Kth level Nodes "; kthLevelPrint(root2,k); cout<<endl;
    cout<<"Height of tree is  - "<<height(root2);
    return 0;
}