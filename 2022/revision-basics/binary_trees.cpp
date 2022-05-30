// Binary Trees

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

Node* createTree(){
    int d;
    cin>>d;
    if( d == -1) return NULL;
    Node* newNode = new Node(d);
    newNode->left = createTree();
    newNode -> right = createTree();

    return newNode;
}

// Level order Print
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

int height(Node* root){
    if( root == NULL) return 0;

    return 1 + max( height(root->left),height(root->right));
}

// Diameter of a Tree 
int DiameterSimple(Node* root){
    if(root == NULL) return 0;

    int heightOfNode = height(root);
    int leftTreeDiameter = DiameterSimple(root->left);
    int rightTreeDiameter = DiameterSimple(root->right);

    return max(1+heightOfNode,max(leftTreeDiameter,rightTreeDiameter));
}
// Diameter Post order class
class pairDaimeter{
    public:

    int height;
    int diameter;

    pairDaimeter(){
        height =0;
        diameter = 0;
    }
};

// Diameter Post order ->
pairDaimeter DiameterPostOrder(Node* root){
    pairDaimeter p;
    if(root == NULL){
        return p;
    }

    // Left Tree -
    pairDaimeter leftTree = DiameterPostOrder(root->left);
    pairDaimeter rightTree = DiameterPostOrder(root->right);

    p.height = 1 + max(leftTree.height,rightTree.height);

    p.diameter = max(1 + p.height,max(leftTree.diameter,rightTree.diameter));

    return p;
}
int main(){
    Node* root = createTree();
    print(root);
    cout<<"Height of tree "<<height(root)<<endl;
    cout<<"Diameter of Tree - "<<DiameterSimple(root)<<"\n";
    pairDaimeter ans = DiameterPostOrder(root);
    cout<<"Diameter post order "<<ans.diameter<<"\n";
}

/*
1
2
4 -1 -1
5 -1 
8 -1 
10 -1 -1
3
6 -1
9 -1 -1
7 -1 -1
*/