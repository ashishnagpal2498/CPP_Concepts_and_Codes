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

    // if(root->left==NULL&&root->right==NULL)
    // {
    //     //It is a leaf NOde -
    //     return 1;
    // }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1+ max(h1,h2);
}
class myPair{
public:
    int height;
    int diameter;
};
myPair fastDiameter(node*root)
{
    myPair p;
    if(root==NULL)
    {
        p.height =0;
        p.diameter =0;
        return p;
    }
    myPair leftTree = fastDiameter(root->left);
    myPair rightTree = fastDiameter(root->right);

    int h1 = leftTree.height;
    int h2 = rightTree.height;

    int d1 = leftTree.diameter;
    int d2 = leftTree.diameter;

    p.diameter = max(h1+h2,max(d1,d2));
    p.height = max(h2,h1) +1;

    return p;
   // leftTree.height > rightTree.height ? leftTree.height : rightTree.height;


}
int diameter(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int opt1 = height(root->left) + height(root->right);
    int opt2 = diameter(root->left);
    int opt3 = diameter(root->right);
    return max(opt1,max(opt2,opt3));
}

class myPair2{
public:
    int excl;
    int incl;
    myPair2()
    {
        excl =0; incl =0;
    }
};

myPair2 subsetSum(node*root)
{   myPair2 p;
    if(root==NULL)
    {
        return p;
    }

    myPair2 leftTree = subsetSum(root->left);
    myPair2 rightTree = subsetSum(root->right);

    //Check -
    p.incl = root->data + leftTree.excl+rightTree.excl;
    p.excl = max(leftTree.incl,leftTree.excl) + max(rightTree.incl,rightTree.excl);

    return p;
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
    myPair ans = fastDiameter(root);
    cout<<ans.diameter<<endl;
    myPair2 ans2 = subsetSum(root);
    cout<<max(ans2.excl,ans2.incl)<<endl;
    return 0;
}