#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = right = nullptr;
    }
    Node(int d){
        data = d;
        left = right = NULL;
    }
};
void levelOrderPrint(Node* root){
    if(root==NULL) return;
    queue<Node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty()){
        Node* f = q1.front();
        q1.pop();
        if(f == NULL){
            cout<<endl;
            if(!q1.empty()){
                q1.push(NULL);
            }
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
void printPostOrder(int in[],int pre[],int n){


    int* it = find(in,in+n,pre[0]); // Returns an iterator 
    int root = it - in;
    if(root != 0){
        printPostOrder(in,pre+1,root);
    }
    if(root != n-1){
        printPostOrder(in+root+1,pre+root+1,n-root-1);
    }
    cout<<in[root]<<" ";
}
Node* buildTree(){
    int d;
    cin>>d;
    if(d == -1) return NULL;
    Node* root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
}

// Temporary node for case 2 
Node* temp = new Node(); 

// function to find left most node in a tree 
Node* leftMostNode(Node* node) 
{ 
    while (node != NULL && node->left != NULL) 
        node = node->left; 
    return node; 
} 
  
// function to find right most node in a tree 
Node* rightMostNode(Node* node) 
{ 
    while (node != NULL && node->right != NULL) 
        node = node->right; 
    return node; 
} 
  
// recursive function to find the Inorder Scuccessor 
// when the right child of node x is NULL 
Node* findInorderRecursive(Node* root, Node* x ) 
{ 
    if (!root) 
        return NULL; 
  
    if (root==x || (temp = findInorderRecursive(root->left,x)) || 
                   (temp = findInorderRecursive(root->right,x))) 
    { 
        if (temp) 
        { 
            if (root->left == temp) 
            { 
                cout << "Inorder Successor of " << x->data; 
                cout << " is "<< root->data << "\n"; 
                return NULL; 
            } 
        } 
  
        return root; 
    } 
  
    return NULL; 
} 
  
// function to find inorder successor of  
// a node 
void inorderSuccesor(Node* root, Node* x) 
{ 
    // Case1: If right child is not NULL 
    if (x->right != NULL) 
    { 
        Node* inorderSucc = leftMostNode(x->right); 
        cout<<"Inorder Successor of "<<x->data<<" is "; 
        cout<<inorderSucc->data<<"\n"; 
    } 
  
    // Case2: If right child is NULL 
    if (x->right == NULL) 
    {     
        int f = 0; 
          
        Node* rightMost = rightMostNode(root); 
  
        // case3: If x is the right most node 
        if (rightMost == x) 
            cout << "No inorder successor! Right most node.\n"; 
        else
            findInorderRecursive(root, x); 
    } 
} 
void inorderSuccesor2(Node* root,Node* targetNode,Node*&nextNode){
    if(root == NULL) return;

    inorderSuccesor2(root->right,targetNode,nextNode);
    if(root->data == targetNode->data){
        if(nextNode == NULL){
            cout<<"No Successor of node -> "<<targetNode->data;
        }
        else {
            cout<<"Successor of node -> "<<targetNode->data<<" is "<<nextNode->data;
        }
    }
    nextNode = root;
    inorderSuccesor2(root->left,targetNode,nextNode);
}
void nThNodeInorder(Node*root,int n,int &i){
    if(root==NULL) return;

    nThNodeInorder(root->left,n,i);
    if(i == n){
        cout<<"Nth node is  -> "<<root->data;
        return;
    }
    i++;
    nThNodeInorder(root->right,n,i);
}
void nThNodePostOrder(Node*root,int n,int &i){
    if(root == NULL) return;

    nThNodePostOrder(root->left,n,i);
    nThNodePostOrder(root->right,n,i);
    if(i==n){
        cout<<"Nth node is  -> "<<root->data;
    }
    i++;
}
Node* buildDLLFromTreeHelper(Node* root){
    if(root == NULL) return root;

    if(root->left){
        Node* left = buildDLLFromTreeHelper(root->left);

        // Find inOrderPredecessor ->
        while(left->right != NULL){
            left = left->right;
        }

        root->left = left;
        left->right = root;
    }
    if(root->right){
        Node* right = buildDLLFromTreeHelper(root->right);

        for(;right->left !=NULL; right = right->left);

        root->right = right;
        right->left = root;
    }
    return root;
}
Node* buildDLLFromTree(Node* root){
    if (root == NULL)  
        return root;  
  
    // Convert to DLL using bintree2listUtil()  
    root = buildDLLFromTreeHelper(root);  
  
    // bintree2listUtil() returns root node of the converted  
    // DLL. We need pointer to the leftmost node which is  
    // head of the constructed DLL, so move to the leftmost node  
    while (root->left != NULL)  
        root = root->left;  
  
    return (root);
}
void treeToLL(Node* root,Node*&head){
    if(root == NULL) return;

    static Node* prev = NULL;

    treeToLL(root->left,head);

    if(prev == NULL){
        head = root;
    }
    else{
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    treeToLL(root->right,head);
}
int TreeSumNodes(Node* root){
    if(root == NULL) return 0 ;
    if(!root->left && !root->right){
        int temp = root->data;
        root->data = 0;
        return temp;
    }
    int sum = TreeSumNodes(root->left) + TreeSumNodes(root->right);
    int temp = root->data;
    root->data = sum;
    return temp+sum;
}
// Check Sum -> preOrder ->
bool checkSum(Node* root){
    if(root == NULL || (root->left== NULL && root->right == NULL)) return true;

    else if(root->left != NULL && root->right == NULL){
        if(root->data == root->left->data) return true;
        return false;
    }
    else if(root->left == NULL && root->right != NULL){
        if(root->data == root->right->data) return true;
        return false;
    }
    else if( root-> data == root->left->data + root->right->data && checkSum(root->left) && checkSum(root->right))
        return true;
    return false;
}
// Post order Traversal
bool checkSum2(Node*root){
    if(root == NULL || (root->left== NULL && root->right == NULL)) return true;

    bool leftTree = checkSum(root->left);
    bool rightTree = checkSum(root->right);
    int leftTreeVal = root->left ? root->left->data : 0;
    int rightTreeVal = root->right ? root->right->data : 0;
    return leftTree && rightTree && root->data == leftTreeVal + rightTreeVal;
}
bool checkCousins(Node* root,int a,int b){
    if(root == NULL) return false;
    map<Node*,pair<Node*,int> > parentMapping;
    queue<Node*> q1;
    int level = 1;
    Node* aVal = NULL;
    Node* bVal = NULL;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty()){
        Node* f = q1.front();
        q1.pop();
        if(f == NULL){
            // Reached level 
            level++;
            if(!q1.empty()) q1.push(NULL);
        }
        else{
                if(f->data == a){
                    aVal = f;
                }
                else if(f->data == b){
                    bVal = f;
                }
                if(f->left){
                    parentMapping[f->left] = {f,level};
                    q1.push(f->left);
                }
                if(f->right){
                    parentMapping[f->right] = {f,level};
                    q1.push(f->right);
                }
                if(aVal && bVal) break;
            }
    }
    cout<<"Parent of A ->"<<parentMapping[aVal].first->data<< " level "<< parentMapping[aVal].second;
    cout<<"Parent of B ->"<<parentMapping[bVal].first->data<< " level "<< parentMapping[bVal].second;
    
    if(parentMapping[aVal].first != parentMapping[bVal].first && parentMapping[aVal].second == parentMapping[bVal].second)
        return true;
    return false;
}
class myPair{
public:
    bool subTreeHalf;
    int sizeSubtree;
    myPair(){
        subTreeHalf = true;
        sizeSubtree = 0;
    }
};
int countNodes(Node* root){
    if(root==NULL) return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}
myPair removeEdgeFromBTree(Node* root,int n){
    myPair p;
    if(root == NULL) return p;

    myPair leftTree = removeEdgeFromBTree(root->left,n);
    myPair rightTree = removeEdgeFromBTree(root->right,n);

    int sizeSubtree = leftTree.sizeSubtree+rightTree.sizeSubtree + 1;
    p.subTreeHalf = sizeSubtree;
    if(leftTree.subTreeHalf || rightTree.subTreeHalf || sizeSubtree == n- sizeSubtree ){
        p.subTreeHalf = true;
    }
    return p;
}
void rootToLeafPath(Node* root,vector<vector<int> > &paths,vector<int> path){
    if(root == NULL) return;
     path.push_back(root->data);
    if(root->left ==NULL && root->right == NULL){

        paths.push_back(path);
        return;
    }
   
    rootToLeafPath(root->left,paths,path);
    rootToLeafPath(root->right,paths,path);
}
bool isArrayPathExist(Node* root,int arr[],int i,int n){
    if(root==NULL || i == n) return false;

    // Imp becase-> recursive -> and i reaches end it will return false
    if(!root->left && !root->right){
        if(root->data == arr[i] && i == n-1) return true;
        return false;
    }

    return root->data == arr[i] && (isArrayPathExist(root->left,arr,i+1,n) || isArrayPathExist(root->right,arr,i+1,n));
}
void printMiddleLevelPerfectBTree(Node* root,int &height){
    if(root == NULL) return;
    static int v = 0;
    printMiddleLevelPerfectBTree(root->left,height);
    if(v == 0) v = height;
    if(height == v/2){
        cout<<root->data<<" -> ";
    }
    printMiddleLevelPerfectBTree(root->right,height);
}

int height(Node* root,int & ans){
    if(root == NULL) return 0;

    int leftTree = height(root->left,ans);
    int rightTree = height(root->right,ans);

    ans = max(ans,1+leftTree+rightTree);

    return 1 + max(leftTree,rightTree);
}
int diameter(Node* root){
    if(root == NULL) return 0;
    int ans = INT_MAX;
    ans = height(root,ans);
    return ans;
}
bool sumOfAllNodesHavingChildX(Node* root,int & sum,int x){
    if(root == NULL) return false;
    
    bool leftTree = sumOfAllNodesHavingChildX(root->left,sum,x);
    bool rightTree = sumOfAllNodesHavingChildX(root->right,sum,x);

    if(leftTree || rightTree){
        cout<<"Root -> data "<<root->data<<endl;
        sum+=root->data;
    }

    return root->data == x;
}
int leftLeaveSum(Node* root){
    if(root == NULL) return 0;

    int res = 0;

    if(root->left == NULL && root->right == NULL) res+=root->left->data;
    else res+= leftLeaveSum(root->left);

    res+= leftLeaveSum(root->right);

    return res;
}
void rootToLeafSumMaxSum(Node* root,int &ans,int &sum){
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL){
        ans = max(ans,root->data+sum);
        return;
    }
    sum+= root->data;
    rootToLeafSumMaxSum(root->left,ans,sum);
    rootToLeafSumMaxSum(root->right,ans,sum);
    sum-=root->data;
}
Node* removeNodesPathSumNotK(Node* root,int k,int sum){
    if(root == NULL) return NULL;

    // leave node sum-
    root->left = removeNodesPathSumNotK(root->left,k,sum+root->data);
    root->right = removeNodesPathSumNotK(root->right,k,sum+root->data);

    if(root->left == NULL && root->right == NULL){
        if(sum+root->data >= k) return root;
        return NULL;
    }

    return root;
}
int maxSumBetweenTwoLeaves(Node* root,int &ans){
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL) return root->data;
    int leftTreeNodeSum = maxSumBetweenTwoLeaves(root->left,ans);
    int rightTreeNodeSum = maxSumBetweenTwoLeaves(root->right,ans);

    if(root->left && root->right){

        ans = max(ans,leftTreeNodeSum+rightTreeNodeSum+root->data);

        return max(leftTreeNodeSum,rightTreeNodeSum) + root->data;
    }

    return root->left ? leftTreeNodeSum+root->data : rightTreeNodeSum+ root->data;
}
int maxPathSumBetweenLeaves(Node *root) 
{ 
    int res = INT_MIN; 
    maxSumBetweenTwoLeaves(root, res); 
    return res; 
}
class MyPairSum{
    int nodeSum;
    int maxSum;
    MyPairSum(){
        nodeSum = 0;
        maxSum = 0;
    }
};
MyPairSum maxPathSumBTreeHelper(Node* root){
    MyPairSum p;
    if(root == NULL) return p;

    MyPairSum leftTree = maxPathSumBTreeHelper(root->left);
    MyPairSum rightTree = maxPathSumBTreeHelper(root->right);

    p.nodeSum = max((max(leftTree,rightTree) + root->data), root->data);

    p.maxSum = max({nodeSum,root->data+leftTree.maxSum,root->data+rightTree.maxSum});

    return p;
}
int maxPathSumBTree(Node* root){
    if(root == NULL) return 0;
    int ans = INT_MIN;
    ans = max(ans);

    return ans;
}
int main(){
    Node* root = buildTree();
    levelOrderPrint(root);
    // // Inorder and PreOrder ->
    //   inorderSuccesor(root, root->left->right);
    //   Node* nextNode = NULL;
    //   inorderSuccesor2(root,root->left->right,nextNode);
    //   cout<<endl;
    //   int i =1,j=1;
    //   nThNodeInorder(root,4,i);
    //   nThNodePostOrder(root,4,j);
    //   cout<<endl;
    //   // Node* root2 = buildDLLFromTree(root);
    //   // while(root2){
    //   //   cout<<root2->data<<" -> ";
    //   //   root2 = root2->right;
    //   // }
    //   Node* head = NULL;
    //   treeToLL(root,head);
    //   while(head){
    //     cout<<head->data<<" -> ";
    //     head = head->right;
    //   }

    // Convert Tree nodes to its sum ->
    cout<<endl;
    // TreeSumNodes(root);
    // levelOrderPrint(root);
    // cout<<" Check sum of Tree "<<checkSum(root)<<" Check Sum 2 "<<checkSum2(root)<<endl;
    // int a,b;
    // cin>>a>>b;
    // cout<<"Check Cousins -> "<<checkCousins(root,a,b);

    // Check if removal ->
    // int n = countNodes(root);
    // myPair ans = removeEdgeFromBTree(root,n);
    // cout<<" Edge exist which divides tree into half -> "<<ans.subTreeHalf<<endl;
    // vector<vector<int> > rootLeavePaths;
    // rootToLeafPath(root,rootLeavePaths,{});
    // for(auto v: rootLeavePaths){
    //     for(int i=0;i<v.size();i++){
    //         cout<<v[i]<<" -> ";
    //     }
    //     cout<<endl;
    // }
    // int arr[] = {1,3,7,9};
    // cout<<"Path of array Exist ->"<<isArrayPathExist(root,arr,0,sizeof(arr)/sizeof(arr[0]));

    // cout<<"Diameter -> "<<diameter(root);
    // int sum = 0;
    // cout<<endl;
    // sumOfAllNodesHavingChildX(root,sum,2);
    // cout<<sum<<endl;
    cout<<" MAX PATH SUM IS -> "<<maxPathSumBetweenLeaves(root);
}