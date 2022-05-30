// BST 
#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(int d){
        data = d;
        left = right = NULL;
    }
};

void createBST(Node* &root,int d){
    if( d == -1) return;

    if(root == NULL ) {
        root = new Node(d);
        return;
    }

    if(root-> data >= d) {
        createBST(root->left,d);
        return;
    }

    else {
        createBST(root->right,d);
        return;
    }
}

void createTree(Node*& root){
    int d;
    cin>>d;
    while(d != -1 ){
        createBST(root,d);
        cin>>d;
    }
}

void printTree(Node* root){
    if( root == NULL) return;

    queue<Node*> q1;
     q1.push(root);
    q1.push(NULL);

    while(!q1.empty()){
        Node* topNode = q1.front();
        q1.pop();
        if(topNode == NULL){
            cout<<"\n";
            if(!q1.empty()) q1.push(NULL);
        }
        else{
            cout<<topNode->data<<" ";
            if(topNode -> left ){
                q1.push(topNode->left);
            }
            if(topNode -> right){q1.push(topNode->right);}
        }
    }
}

bool SearchElement(Node* root,int ele){

    if( root == NULL) return false;

    if(root->data == ele) return true;

    if( root-> data > ele) return SearchElement(root->left,ele);

    else return SearchElement(root->right,ele);

}
Node* replacementNode(Node* root){
    if(root == NULL) return NULL;

    while(root && root->right){
        root = root->right;
    }
    return root;
}
// Delete a Node in BST ->
Node* DeleteNode(Node* root,int ele){
    if(root == NULL) return NULL;

    if(root->data > ele ) {
        root->left = DeleteNode(root->left,ele);
        return root;
    }
    else if(root->data < ele){
         root->right = DeleteNode(root->right,ele);
        return root;
    }
    else{
        // Node is equal 
    if(root->left == NULL && root->right == NULL)
        {
            Node* waste = root;
            delete waste;
            return NULL;
        }
        else if(root->left == NULL && root -> right != NULL){
            return root->right;
        }
        else if(root->right == NULL && root -> left != NULL){
            return root->left;
        }
        else{
            // 2 children exist;
            Node* nextNode = replacementNode(root->left);
            root->data = nextNode -> data;
            root->left = DeleteNode(root->left,nextNode->data);
            return root;
        }
    }
}

// Check if Given tree is BST or not

bool isBST(Node* root,int upperBound = 1000000,int lowerBound = -10000000){
    if( root == NULL) return true;

    if(root->data<= upperBound && root->data >= lowerBound && isBST(root->left,root->data,lowerBound)
        && isBST(root->right,upperBound,root->data)) return true;

     return false;   
}

// Balanced BST using Sorted Array -
Node* arrayToBST(int* arr,int end,int start){
    // Base case
    if(start>end) return NULL;
    if( start == end) return new Node(arr[start]);
    int midPoint = (start+end)/2;
    Node* root = new Node(arr[midPoint]);

    root->left = arrayToBST(arr,midPoint-1,start);
    root->right = arrayToBST(arr,end,midPoint+1);
    return root;

}

// Flattening A BST ->
class flatTree{
public:
    Node* head;
    Node* tail;

    flatTree(){
        head = tail = NULL;
    }
};

flatTree flatenningTree(Node* root){
    flatTree p;
    if(root == NULL) return p;

    // Single Node
    if(root->left == NULL && root->right == NULL) {
        p.head = root;
        p.tail = root;
        return p;
    }
    // Right Tree Exist
    else if(root->left == NULL && root->right !=NULL){
        p.head = root;
        root->left == NULL;
        flatTree rightTree = flatenningTree(root->right);
        // Change here a bit
        //p.head->right = rightTree.head;
        root->right = rightTree.head;
        p.tail = rightTree.tail;
        
        // Doubly linkedList
        rightTree.head->left = root;
        return p;
    }
    else if(root->left != NULL && root->right ==NULL){
     p.tail = root;
     p.tail->right = NULL;
        flatTree leftTree = flatenningTree(root->left);
        leftTree.tail->right = root;
        p.head = leftTree.head;

        // Doubly linkedList
        root->left = leftTree.tail;
        return p;   
    }
    else{
        // Both Side of Nodes Exist ->

        flatTree leftTree = flatenningTree(root->left);
        flatTree rightTree = flatenningTree(root->right);

        // Left 
        leftTree.tail->right = root;
        

        // Right Tree
        root->right = rightTree.head;

        
        // 
        p.head = leftTree.head;
        p.tail = rightTree.tail;
        
        // Doubly LinkedList
        
        p.head->left = leftTree.tail;
        rightTree.head->left = root;
        leftTree.head->left = NULL;
        rightTree.tail -> right = NULL;
        return p; 
    }
}

void printFlatTree(Node* root){
    cout<<"Print Flatt Tree"<<endl;
    if( root == NULL) return;

    while(root){
        cout<<root->data<<" ";
        root = root->right;
    }
    cout<<endl;
}

void printReverseFlatTree(Node* root){
    cout<<"Print Reverse Flatt Tree"<<endl;
    if( root == NULL) return;

    while(root){
        cout<<root->data<<" ";
        root = root->left;
    }
}

int main(){
    Node* root = NULL;
    createTree(root);
    printTree(root);
    int deleteVal;
    cout<<"Enter node to be Deleted"<<endl;
    cin>>deleteVal;
    root = DeleteNode(root,deleteVal);
    printTree(root);
    isBST(root) ? cout<<"Tree is a BST\n": cout<<"Tree not a BST\n";
    flatTree ans = flatenningTree(root);
    printFlatTree(ans.head);
    printReverseFlatTree(ans.tail);
}

// 5 8 4 3 7 6 2 -1 