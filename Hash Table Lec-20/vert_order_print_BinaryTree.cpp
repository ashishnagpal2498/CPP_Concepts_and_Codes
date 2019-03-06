//Vertical order print - Binary Tree
#include<iostream>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
public:
    node(int d)
    {
        left= right = NULL;
        data = d;
    }

};

node* buildTree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printTree(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<"  ";
    printTree(root->left);
    printTree(root->right);
}
void level_order_print(node*root)
{
    if(root==NULL)
    {
        return;
    }
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
        }
        else
        {   cout<<f->data<<" ";
            if(f->left!=NULL)
            {
                q1.push(f->left);
            }
            if(f->right!=NULL)
            {
                q1.push(f->right);
            }
        }
    }
}
void vertical_o_print(node* root,map<int, vector<int> > &m,int d=0)
{
    if(root==NULL)
    {
        return;
    }
    //m[d] - will give a vector- 
    m[d].push_back(root->data);
    vertical_o_print(root->left,m,d-1);
    vertical_o_print(root->right,m,d+1);
}
int main()
{
    node* root = NULL;
    root = buildTree();
    // Build the tree;
    printTree(root);
    cout<<endl;
    level_order_print(root);
    map<int,vector<int> > m;
    vertical_o_print(root,m,0);
    // This will create a hash- map
    for(auto it = m.begin();it!=m.end();it++)
    {
        //Bucket value Cout
        cout<<"Bucket "<<it->first<<"  ->  ";
        for(int i=0;i<it->second.size();i++)
        {
            cout<<it->second[i]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}