// Binary Tree ->
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};
int height(Node* root){
    if(root == NULL) return 0;

    return 1 + max(height(root->left),height(root->right));
}
int diameter(Node* root){
    if(root == NULL) return 0;
    // if(root->left == NULL && root->right == NULL) return 1;

    int leftTreeHeight = height(root->left);
    int rightTreeHeight = height(root->right);
    int opt1 = leftTreeHeight+rightTreeHeight;
    int opt2 = diameter(root->left);
    int opt3 = diameter(root->right);
    return max({opt1,opt2,opt3});
}
Node* buildTree(){
    int d;
    cin>>d;
    if(d == -20) return NULL;
    Node* root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
class myPair{
public:
    int diameter;
    int height;
    myPair(){
        diameter = height = 0;
    }
};
myPair diameter2(Node* root){
    myPair p;
    if(root == NULL) return p;

    myPair leftTree = diameter2(root->left);
    myPair rightTree = diameter2(root->right);

    p.height = 1+ max(leftTree.height,rightTree.height);

    p.diameter = max({leftTree.height+rightTree.height,leftTree.diameter,rightTree.diameter});

    return p;
}
void levelOrderPrint(Node* root){
    if(root == NULL) return;
    queue<Node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty()){
        Node* f = q1.front();
        q1.pop();
        if(f == NULL){
            cout<<endl;
            if(!q1.empty()) q1.push(NULL);
        }
        else{
            cout<<f->data<<" ";
            if(f->left){
                q1.push(f->left);
            }
            if(f->right){
                q1.push(f->right);
            }
        }
    }
}
int maxPathSum(Node* root,int &res){
    if(root == NULL) return 0;

    int leftSum = maxPathSum(root->left,res);
    int rightSum = maxPathSum(root->right,res);

    // int opt1 = root->data;
    // int opt2 = leftSum + opt1;
    // int opt3 = rightSum+ opt1;
    int opt4 = leftSum+rightSum+ root->data;
    int max_single = max(max(leftSum,rightSum)+root->data,root->data);

    int max_multiple = max(max_single,opt4);
    res = max(res,max_multiple);
    return max_single;
}
int maxSum(Node* root){
    if(root ==NULL) return 0;
    int res = 0;

    maxPathSum(root,res);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cin>>n;
    Node* root = buildTree();
    levelOrderPrint(root);
    cout<<"Diameter -> "<<diameter(root)<<endl;    
    myPair ans = diameter2(root);
    cout<<"Diameter 2 -> "<<ans.diameter<<endl;
    cout<<maxSum(root);
    return 0;
}    