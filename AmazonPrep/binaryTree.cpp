// Binary Tree -> Implementation ->
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
class myPair2 {
public: 
    int maxVal;
    int singleNodeSum;
    myPair2(){
        maxVal = INT_MIN;
        singleNodeSum = 0;
    }
};
myPair2 maxPathSum2(Node* root){
    // Here -> I can take whichever node -> to start , and ignore its children-> descendants
    // Therefore -> NodeSum -> 
    myPair2 p;
    if(root==NULL) return p;

    myPair2 leftTree = maxPathSum2(root->left);
    myPair2 rightTree = maxPathSum2(root->right);

    p.maxVal = max({leftTree.maxVal,rightTree.maxVal,leftTree.singleNodeSum+rightTree.singleNodeSum+root->data});
    p.singleNodeSum = max(root->data,max(leftTree.singleNodeSum,rightTree.singleNodeSum)+root->data);

    return p;
}
void maxXorpath(Node*root,vector<int> values,int &xorVal){
    if(root== NULL) return;
    // If passed by value -> no need to remove ->
    values.push_back(root->data);
    if(root->left == NULL && root->right == NULL){
        int v = 0;
        for(int i:values){
            v^=i;
        }
        // v^=root->data;
        xorVal = max(xorVal,v);
    }

    maxXorpath(root->left,values,xorVal);
    maxXorpath(root->right,values,xorVal);
    // values.pop_back();
    return;
}
// Max Path between two leaves
class myPair3{
public:
    int maxV;
    int nodeSum;
    myPair3(){
        nodeSum = 0;
        maxV = INT_MIN;
    }
};
myPair3 maxLeaveSum(Node* root){
    myPair3 p;
    if(root == NULL) return p;
    if(root->left == NULL && root->right == NULL) {
        p.nodeSum = root->data;
        p.maxV = root->data;
        return p;
    }
    myPair3 leftTree = maxLeaveSum(root->left);
    myPair3 rightTree = maxLeaveSum(root->right);

    // Leave comparison ->MAX leave SUM tabhi ho payega when we have both children ->
    if(root->left && root->right)
    {  
        p.maxV = max({leftTree.maxV,rightTree.maxV,leftTree.nodeSum+rightTree.nodeSum+root->data});
    }

     p.nodeSum = max(leftTree.nodeSum,rightTree.nodeSum)+ root->data;
    // p.rightLeave = max(rightTree.rightLeave,leftTree.rightLeave);
    return p;
}

// Maximum Sum Leave to root Path 
// -> POST ORDER TRAVERSAL ->
ll leaveToRootSum(Node* root){
    // Base Case
    if(root == NULL) return INT_MIN;
    if(root->left == NULL && root-> right == NULL) return root->data;
    
    // cout<<root->data<<" -> ";
    
    ll leftTree = leaveToRootSum(root->left);
    ll rightTree = leaveToRootSum(root->right);
    
    return max(leftTree,rightTree)+root->data;
}
// PRE_ORDER TRAVERSAL ->
void leaveToRootSumPreOrder(Node*root,int &maxSum,int currSum,Node*&targetPath){
    if(root == NULL) return;

    currSum += root->data;

    // path.push_back(root->data);
    if(root->left == NULL && root->right == NULL){
        if(currSum > maxSum){
            maxSum = currSum;
            targetPath = root;
        }
        // else{
        //     path.pop_back();
        // }
        return;
    }
    leaveToRootSumPreOrder(root->left,maxSum,currSum,targetPath);
    leaveToRootSumPreOrder(root->right,maxSum,currSum,targetPath);
    // path.pop_back();
}
//Print Path
bool printPath(Node* root,Node* targetPath){
    if(root == NULL) return false;


    if(root == targetPath || printPath(root->left,targetPath) || printPath(root->right,targetPath)){
        cout<<root->data<<" ";
        return true;
    }
    return false;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cin>>n;
    Node* root = buildTree();
    levelOrderPrint(root);
    // cout<<"Diameter -> "<<diameter(root)<<endl;    
    // myPair ans = diameter2(root);
    // cout<<"Diameter 2 -> "<<ans.diameter<<endl;
    // cout<<"Max value -> path 1 -> "<<maxSum(root)<<endl;
    // myPair2 ans2 = maxPathSum2(root);
    // cout<<"Max value path 2 ->"<<ans2.maxVal<<endl;
    // int ans3 = INT_MIN;
    // vector<int> values;
    // maxXorpath(root,values,ans3);
    // cout<<"Max Xor value is -> "<<ans3<<endl;

    myPair3 ans4 = maxLeaveSum(root);
    cout<<"Max Leave Sum is -> "<<ans4.maxV<<endl;
    ll ans5 = leaveToRootSum(root);
    cout<<"Leave to root max Sum -> "<<ans5<<endl;
    Node*targetPath = NULL;
    // vector<int> p;
    int ans6 = INT_MIN; leaveToRootSumPreOrder(root,ans6,0,targetPath);
    cout<<"Max Leave to root sum -> "<<ans6<<"\nPath size -> ";
    printPath(root,targetPath);
    // for(int i:p) {cout<<i<<" ";}
    return 0;
}    