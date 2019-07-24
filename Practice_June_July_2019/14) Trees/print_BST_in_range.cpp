//Print BST in Given Range
#include<iostream>
#include<algorithm>
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

void printTree(node*root)
{
    if(root==NULL) return;

    cout<<root->data<<"  ";
    printTree(root->left);
    printTree(root->right);
}
void printBst(node*root,int k1,int k2)
{
    if(root==NULL) return;
    printBst(root->left,k1,k2);
    if(root->data>=k1&&root->data<=k2)
    {
        cout<<root->data<<" ";
    }
    printBst(root->right,k1,k2);
}
int main()
{   int T;
    cin>>T;
    while(T--)
    {   int n;
    cin>>n;
    int arr[10005];
    ArrIn;
     int k1,k2;
    cin>>k1>>k2;

    // sort(arr,arr+n);
    node* root = NULL;
    root = Bst(arr,n);
    // printTree(root); 
    cout<<"# Preorder : "; printTree(root);
   
    
    cout<<endl<<"# Nodes within range are : "; printBst(root,k1,k2);
   cout<<endl; }
}