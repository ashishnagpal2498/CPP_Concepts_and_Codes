//Replace with Sum -
#include<iostream>
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" ";}
#define ArrIn for(int i=0;i<n;i++) cin>>arr[i];
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
void createBst(node*&root,int ele)
{
    if(root==NULL)
    {
        root = new node(ele);
        return;
    }
    if(root->data>=ele)
    {
        createBst(root->left,ele);
    }
    else
    {
        createBst(root->right,ele);
    }

}
node* Bst(int*arr,int n)
{
    int i=0;
    node*root=NULL;
    while(i<n)
    {
        createBst(root,arr[i]);
        i++;
    }
    return root;
}
class myPair{
public:
    int lsum;
    int rsum;
    myPair(){
        lsum = rsum = 0;
    }
};
node* balancedBst(int*arr,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid = (s+e)/2;
    node*root = new node(arr[mid]);
    root->left = balancedBst(arr,s,mid-1);
    root->right = balancedBst(arr,mid+1,e);
    return root;
}

myPair replace_Sum(node*&root)
{
    myPair p;
    if(root==NULL)
    {
        return p;
    }
    myPair leftTree = replace_Sum(root->left);
    myPair rightTree = replace_Sum(root->right);
    int rdata = root->data;
    root ->data = root->data + rightTree.rsum+ leftTree.lsum;
    p.lsum = rdata;
    p.rsum = root->data;
    return p;

}

void replaceNode(node*&root,int &sum)
{
    if(root==NULL)
        return;
    replaceNode(root->right,sum);
    sum += root->data;
    root->data = sum;
 replaceNode(root->left,sum);
    return;
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
    int arr[100005];
    ArrIn;
    node* root =NULL;
    root = balancedBst(arr,0,n-1);
    int sum=0;
    replaceNode(root,sum);
    printTree(root);
    return 0;
}