// Trees Generic

#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    int noOfChildren;
    Node** nChild;

    Node(){
        data =0;
        noOfChildren = 0;
        nChild = NULL;
    }
    Node(int d,int children){
        data = d;
        noOfChildren = children;
        if(children>0)
        nChild = new Node*[noOfChildren];
    }

    Node* createTree(){
        int d;
        cin>>d;
        if(d == -1) return NULL;
        int children;
        cin>>children;
        Node* newNode = new Node(d,children);
        for(int i=0;i<children;i++){
            newNode->nChild[i] = createTree();
        }
        return newNode;
    }
    void printTree(Node* root){
        if( root == NULL) return;
        cout<<root->data<<" ";
        for(int i=0;i<root->noOfChildren;i++){
            printTree(root->nChild[i]);
        }
        cout<<endl;
    }
    void levelOrderPrint(Node* root){
        queue<Node*> q1;
        if(root == NULL) return;

        q1.push(root);
        q1.push(NULL);
        while(!q1.empty()){
            Node* frontNode = q1.front();
            q1.pop();
            if(frontNode == NULL) { cout<<"\n"; if(!q1.empty()) q1.push(NULL);}
            else{
                cout<<frontNode->data<<" ";

                for(int i=0;i<frontNode->noOfChildren;i++){
                    if(frontNode->nChild[i])
                    q1.push(frontNode->nChild[i]);
                }
            }
        }
    }
    void postOrderTraversal(Node* root){
        if(root == NULL) return;

        for(int i=0;i<root->noOfChildren;i++){
            postOrderTraversal(root->nChild[i]);
        }
        cout<<root->data<<" ";
    }
    void kthLevel(Node* root,int k){
        if(root == NULL) return;

        if(k == 0) {
            cout<<root->data<<" ";
            return;
        }
        for(int i=0;i<root->noOfChildren;i++){
            kthLevel(root->nChild[i],k-1);
        }
    }
    int height(Node* root){
        if(root == NULL) return 0;
        int maxVal = 0;
        for(int i=0;i<root->noOfChildren;i++){
            int smallHeight = height(root->nChild[i]);
            maxVal = max(maxVal,smallHeight);
        }
        return 1 + maxVal;
    }

};

int main(){
    Node* root = NULL;
    root = root->createTree();
    root->levelOrderPrint(root);
    cout<<"Post order traversal ->"<<endl;
    root->postOrderTraversal(root);
    cout<<"\n Kth Level ";
    root->kthLevel(root,2);
    cout<<"\n Height of Tree "<<root->height(root)<<endl;
    return 0;
}