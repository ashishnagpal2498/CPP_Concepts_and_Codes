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
    if(root == NULL) return true;

    if(root->data == a){
        
    }
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
    cout<<" Check sum of Tree "<<checkSum(root)<<" Check Sum 2 "<<checkSum2(root);
}