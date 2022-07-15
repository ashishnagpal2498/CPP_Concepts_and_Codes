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
    cout<<"Print tree - Level Order\n";
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

Node* replacementNode(Node* root){
    while(root && root->right){
        root = root->right;
    }
    return root;
}

Node* DeleteNode(Node* root, int deleteVal){
    if(root == NULL){
        return NULL;
    }
    if(root->data < deleteVal){
        return DeleteNode(root->right,deleteVal);
    }
    else if(root->data > deleteVal){
        return DeleteNode(root->left,deleteVal);
    }
    else{
        // Both the Values are equal Node Found;

        // Leaf Node -
        if(root->left == NULL && root ->right == NULL) {
            delete root;
            return NULL;
        } 
        // Single Child
        else if(root->left == NULL && root->right !=NULL){
            Node* waste = root;
            root = root->right;
            delete waste;
            return root;
        }

        else if(root->left != NULL && root->right ==NULL){
            Node* waste = root;
            root = root->left;
            delete waste;
            return root;
        }
        else{
            // Find the replacement Node ->
            cout<<"Here -> ";
            Node* maxNode = replacementNode(root->left);
            cout<<" replacementNode data "<<maxNode->data<<endl;
            root->data = maxNode->data;
            root->left = DeleteNode(root->left,maxNode->data);
            return root;
        }
    }
}

// Flattening a BST -
class FlatTree{
public:
    Node* head;
    Node* tail;
    flatten(){
        head = tail = NULL;
    }
};

FlatTree flatenningTree(Node* root){
    FlatTree p;
    if( root == NULL ) return p;

    else if(root->left == NULL && root->right == NULL){
        // Head and Tail both same Node
        p.head = root;
        p.tail = root;
        return p;
    }

    else if(root->left != NULL && root->right == NULL){
        p.tail = root;

        FlatTree leftTree = flatenningTree(root->left);
        leftTree.tail->right = root;
        p.head = leftTree.head;
        return p;
    }

    else if(root->left == NULL && root->right != NULL){
        p.head = root;

        FlatTree rightTree = flatenningTree(root->right);
        root->right = rightTree.head;
        p.tail = rightTree.tail;
        return p;
    }
    else{
        FlatTree leftTree = flatenningTree(root->left);
        FlatTree rightTree = flatenningTree(root->right);
        
        //left tree Mapping
        p.head = leftTree.head;
        leftTree.tail->right = root;

        // right tree mapping
        root->right = rightTree.head;
        p.tail = rightTree.tail;

        return p;
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
    // isBST(root) ? cout<<"Tree is a BST\n": cout<<"Tree not a BST\n";
    FlatTree ans = flatenningTree(root);
    printFlatTree(ans.head);
    // printReverseFlatTree(ans.tail);
}