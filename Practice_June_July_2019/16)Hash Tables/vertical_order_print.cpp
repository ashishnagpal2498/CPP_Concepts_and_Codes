//verticle order print Binary Tree
#include <iostream>
#include<map>
#include<vector>
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
void buildTree(node*&root)
{   int d;
    cin>>d;
    if(d!=-1)
    {
        root = new node(d);
        buildTree(root->left);
        buildTree(root->right);
    }
    return;
}
void vop(node*root,map<int,vector<int> > &m ,int d=0)
{
    if(root==NULL)
    {
        return;
    }
    m[d].push_back(root->data);
   
        vop(root->left,m,d-1);

  vop(root->right,m,d+1);
    
}
void printTree(node*root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}
int main()
{
    node* root = NULL;
    buildTree(root);
    printTree(root);
    map<int, vector<int> > m;
    vop(root,m);
    for(auto it = m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" ->";
        for(int i=0;i<it->second.size();i++)
        {
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}