//Trees - Binary Trees 
#include<iostream>
#include<queue>
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
void BuildTree(node*&root)
{   int d;
    cin>>d;
    if(d==-1) return;
      root = new node(d);
        BuildTree(root->left);
        BuildTree(root->right);
    
}
void preOrderTraversal(node*root)
{
    if(root==NULL) return;

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(node*root)
{
    if(root==NULL) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
void inOrderTraversal(node*root)
{
    if(root==NULL) return;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
void levelOrderTraversal(node*root)
{
    if(root==NULL) return;
    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty())
    {
        node* fr = q1.front();
        q1.pop();
        if(fr==NULL)
        {
            cout<<endl;
            if(!q1.empty()) q1.push(NULL);
        }
        else
        {
            cout<<fr->data<<" ";
            if(fr->left!=NULL)
            {
                q1.push(fr->left);
            }
            if(fr->right!=NULL)
            {
                q1.push(fr->right);
            }
        }
    }
}
void levelOrderInput(node*root)
{

}

int height(node*root)
{
    if(root==NULL) return 0;

    if(root->left==NULL&&root->right==NULL)
    {
        //It is a leaf NOde -
        return 1;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1+ max(h1,h2);
}
int diameter(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int opt1 = height(root);
    int opt2 = diameter(root->left);
    int opt3 = diameter(root->right);
    return max(opt1,max(opt2,opt3));
}
int main()
{
    node* root = NULL;
    BuildTree(root);
    preOrderTraversal(root); cout<<endl;
    postOrderTraversal(root); cout<<endl;
    inOrderTraversal(root); cout<<endl;
    levelOrderTraversal(root);
    cout<<height(root)<<endl;
    cout<<diameter(root)<<endl;
    return 0;
}