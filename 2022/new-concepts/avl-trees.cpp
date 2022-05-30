// AVL trees - trial

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = right = NULL;
        height = 1;
    }
};

int height(Node* root){
    if(root == NULL) return 0;

    return root->height;
}
Node* newNode(int d){

    Node* n = new Node(d);   
    return n;
}

Node* rightRotate(Node* y){

    Node* x = y->left;
    Node* T2 = x->right;

    y->left = T2;
    x->right = y;

    y->height = 1+ max(height(y->left),height(y->right));
    x->height = 1+ max(height(x->left),height(x->right));

    return x;
}

Node* leftRotate(Node* y){

    Node* x = y->right;
    Node* T2 = x->left;

    y->right = T2;
    x->left = y;

    y->height = 1+ max(height(y->left),height(y->right));
    x->height = 1+ max(height(x->left),height(x->right));

    return x;
}

int balanceFactor(Node* root){
    if(root == NULL) return 0;

    return height(root->left) - height(root->right);
}

Node* insert(Node* root,int d){
    if(root == NULL){
        return newNode(d);
    }
    else if(root->data>= d){
        root->left = insert(root->left,d);
    }
    else root->right = insert(root->right,d);

    // Calculate 
    root->height = 1 + max(height(root->left),height(root->right));


    int bFactor = balanceFactor(root);

    // Left Left Case
    if(bFactor > 1 && d < root->left->data){
        return rightRotate(root);
    }

    else if(bFactor < -1 && d > root->right->data){
        return leftRotate(root);
    }
    // left - Right 
    else if(bFactor > 1 && d > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if(bFactor < -1 && d < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node* maxValueNode(Node* root){
    if(root == NULL) return NULL;

    while(root && root->right){
        root = root->right;
    }
    return root;
}

Node* deleteNode(Node* root, int d){
    if(root == NULL) return NULL;

    else if(root->data > d ){
        root->left = deleteNode(root->left,d);
    }
    else if(root->data < d){
        root->right = deleteNode(root->right,d);
    }

    else{
        // Root data is equal ->
        if(root->left == NULL && root->right == NULL){
            root = NULL;
        }
        // One Child Case
        else if(root->left != NULL && root->right == NULL){
            root = root->left;
        }
        else if(root->left == NULL && root->right != NULL){
            root = root->right;
        }
        else{
            Node* replacementNode = maxValueNode(root->left);
            root->data = replacementNode->data;
            root->left = deleteNode(root->left,root->data); 
        }
    }
    // Only 1 node was there;
    if(root == NULL){
        return NULL;
    }

    root->height = 1+ max(height(root->left),height(root->right));

    int reBalanceFactor = balanceFactor(root);

    // left- left case -
    if(reBalanceFactor > 1 && balanceFactor(root->left)>=0){
        return rightRotate(root);
    }
    else if(reBalanceFactor > 1 && balanceFactor(root->left)<0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if(reBalanceFactor < -1 && balanceFactor(root->right)<=0){
        return leftRotate(root);
    }
    else if(reBalanceFactor < -1 && balanceFactor(root->right)>0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void print(Node* root){
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

int main(){
    Node *root = NULL;
     
    /* Constructing tree given in
    the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    print(root);
     root = deleteNode(root, 10);
     print(root);
    return 0;
}