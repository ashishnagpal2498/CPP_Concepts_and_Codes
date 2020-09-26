// Generic Tree
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
    int noOfChildren;
    Node**nchild;
    Node(int d,int n){
        data= d;
        noOfChildren = n;

        if(n>0)
        {
            nchild = new Node*[n];
                for(int i=0;i<n;i++) nchild[i] = NULL;
            }
    }
};
Node* createTree(int d=-1,int n=-1){
    cin>>d;
    if(d == -1) return NULL;
    cin>>n;
    Node* root = new Node(d,n);
    for(int i=0;i<n;i++){
        root->nchild[i] = createTree(d,n);
    }
    return root;

}
void levelOrder(Node* root){
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
            for(int i=0;i<f->noOfChildren;i++){
                if(f->nchild[i] != NULL) q1.push(f->nchild[i]);
            }
        }
    }
}
void printTree(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" -> ";
    for(int i=0;i<root->noOfChildren;i++){
        printTree(root->nchild[i]);
    }

}
int height(Node* root){
    if(root == NULL) return 0;

    int ans = 1;
    int maxVal = INT_MIN;
    for(int i=0;i<root->noOfChildren;i++){
        int v = height(root->nchild[i]);
        maxVal = max(maxVal,v);
    }
    if(maxVal != INT_MIN) ans+=maxVal;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node*root = createTree();
    printTree(root);
    cout<<endl;
    levelOrder(root); 
    // Kth level print -> 
    cout<<"Height of tree is -> "<<height(root)<<endl;
    return 0;
}    