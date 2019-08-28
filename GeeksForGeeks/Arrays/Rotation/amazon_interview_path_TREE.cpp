//amazon - interview -visit path -
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;
    node(int d)
    {
        data =d;
        left = right = NULL;
    }
};
void LevelOrderbuildTree(node*&root)
{
    int d;
    cin>>d;
    queue<node*> q1;
    if(d!=-1)
    {
        root = new node(d);
        q1.push(root);
        
    }
    int c1,c2;
    while(!q1.empty())
    {
        node* f = q1.front();
        q1.pop();
        cin>>c1;
        if(c1!=-1)
        {
            f->left = new node(c1);
            q1.push(f->left);
        }
        cin>>c2;
        if(c2!=-1)
        {
            f->right = new node(d);
            q1.push(f->right);
        }
    }
}
node* insertNode(node* root,int d)
{
    if(root==NULL)
    {
        return new node(d);
    }
    if(root->data<d)
    {
        root->right = insertNode(root->right,d);
    }
    else if(root->data>=d)
    {
        root->left = insertNode(root->left,d);
    }
    return root;
}
void buildBst(node*&root)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        root = insertNode(root,d);
        cin>>d;
    }
}
void root2LeafAllPaths(node*root,vector<int> &v){

    if(root==NULL){
        return;
    }

    if(root->left==NULL and root->right==NULL){
        v.push_back(root->data);
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" --> ";
        }
        //check if the sum is greater - 
        //delete in BST -
        //if(val <threshHoldVal)
        //else - just subtract 
        cout<<endl;
        v.pop_back();
        return;
    }
    //rec case
    v.push_back(root->data);
    root2LeafAllPaths(root->left,v);
    root2LeafAllPaths(root->right,v);
    v.pop_back();
    return;
}
void levelOrderPrint(node*root)
{

    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty())
    {
        node* f = q1.front();
        q1.pop();

        if(f==NULL)
        {
            cout<<endl;
            if(!q1.empty())
            {
                q1.push(NULL);
            }
            continue;
        }
        cout<<f->data<<" ";
        if(f->left!=NULL)
        {
            // f->left = new node(c1);
            q1.push(f->left);
        }
        
        if(f->right!=NULL)
        {
            
            q1.push(f->right);
        }
    }
}
int main(int argc, char const *argv[])
{
    node* root =NULL;
    // LevelOrderbuildTree(root);
    buildBst(root);
    levelOrderPrint(root);
    vector<int> v;
    root2LeafAllPaths(root,v);
    return 0;
}