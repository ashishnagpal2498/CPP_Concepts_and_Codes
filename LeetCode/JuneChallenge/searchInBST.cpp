// Search In BST
#include<iostream>
#include<queue>
using namespace std;
class Node{
    int val;
    Node* left;
    Node* right;
    Node(int d){
        val = d;
        left = NULL;
        right = NULL;
    }
};
void createTree(Node* &root,int data)
{
    if(root == NULL){
        root = new Node(data);
        return;
    }
    else if(data == -1){
        root = NULL;
        return;
    }
    else if(root->val >= data){
        createTree(root->left,data);
    }
    else{
        createTree(root->right,data);
    }
}
void levelOrderTraversal(Node* root)
{   
    queue<int> q;
    q.push(root->val);
    while(!q.empty())
    {
        
    }
}
int main(){
    // -1 means NULL 
    int n,a;
    cin>>n;
    Node* tree = NULL;
    while(n--){
        cin>>a;
        createTree(tree,a);
    }
    levelOrderTraversal(tree);
}