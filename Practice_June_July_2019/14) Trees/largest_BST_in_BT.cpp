//Largest BST in a BT
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;
    node(int d)
    {
        data=d;
        left = right = NULL;
    }
};

class isBst{
public:
    int maxVal;
    int minVal;
    bool isBST;
    int length;
    isBst()
    {   length = 0;
        maxVal = -1000000;
        minVal = 1000000;
        isBST = true;
    }
};

isBst largestBST(node*root)
{
    isBst p;
    if(root==NULL) return p;
    if(root->left==NULL&&root->right==NULL)
    {
        p.length = 1;
        p.minVal = root->data;
        p.maxVal = root->data;
        p.isBST = true;
        return p;
    }
    isBst leftTree = largestBST(root->left);
    isBst RightTree = largestBST(root->right);

    if(root->data>leftTree.maxVal&&root->data<RightTree.minVal&&leftTree.isBST&&RightTree.isBST)
    {
        p.isBST = true;
        p.length = max(leftTree.length,RightTree.length) +1;
        p.minVal = min(RightTree.minVal,min(root->data,leftTree.minVal));
        p.maxVal = max(leftTree.maxVal,max(root->data,RightTree.maxVal));
    }
    else
    {
        p.isBST = false;
        p.length = max(leftTree.length,RightTree.length);
    }
    
    return p;
}


node* BtreeInPre(int in[],int pre[],int s,int e)
{
    static int i =0;
    if(s>e) return NULL;
    int ele = pre[i++];
    int index = 0;
    for(int j=s;j<=e;j++)
    {
        if(ele==in[j]) {index =j; break;}

    }
    node*root = new node(ele);

    root->left = BtreeInPre(in,pre,s,index-1);
    root->right = BtreeInPre(in,pre,index+1,e);
    return root;
}
void printTree(node*root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}
int main(int argc, char const *argv[])
{
        int n;
         cin>>n;
           int in [10005];
     int pre[10005]; //= {60,50,65,70};
      for(int i=0;i<n;i++) cin>>pre[i];
      for(int i=0;i<n;i++) cin>>in[i];   
   
     node* root = NULL;
     root= BtreeInPre(in,pre,0,n-1);
     // printTree(root);   
    cout<<largestBST(root).length<<endl;
    return 0;
}