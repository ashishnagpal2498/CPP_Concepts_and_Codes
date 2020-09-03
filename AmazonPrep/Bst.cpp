// Binary Search Trees
// Special Type of Binary trees in which Root->data > left subtree and < right subTree
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
Node* createTree(Node*root,int d){
    if(root == NULL){
        return new Node(d);
    }
    if(d>root->data){
        root->right = createTree(root->right,d);
    
    }
    else{
        root->left = createTree(root->left,d);
    }
    return root;
}
void preOrderTraversal(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(Node* root){
    if(root == NULL) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
void inOrderTraversal(Node* root){
    if (root ==NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
void levelOrderTraversal(Node* root){
    if(root==NULL) return;
    queue<Node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty()){
        Node* f = q1.front();
        q1.pop();
        if(f==NULL){
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
class myPair{
public:
    int height;
    bool isBalanced;
    myPair(){
        height = 0;
        isBalanced = true;
    }
};
myPair heightBalanced(Node* root){
    myPair p;
    if(root == NULL) return p;

    myPair leftTree = heightBalanced(root->left);
    myPair rightTree = heightBalanced(root->right);

    int h1 = leftTree.height, h2 = rightTree.height;
    p.height = 1+ max(h1,h2);

    if(leftTree.isBalanced && rightTree.isBalanced && abs(h1-h2)<=1){
        p.isBalanced = true;
    } 
    else p.isBalanced = false;
    return p;
}
ostream& operator<<(ostream& ob,Node*&root){
    levelOrderTraversal(root);
    return ob;
}
Node* findRightMaxNode(Node* root){
    if(root == NULL) return NULL;
    while(root->left) root = root->left;
    return root;
}
Node* deleteInBST(Node* root,int key){
    if(root == NULL) return root;
    if(root->data>key){
        root->left = deleteInBST(root->left,key);
        return root;
    }
    else if(root->data<key){
        root->right = deleteInBST(root->right,key);
        return root;
    }
    else{
        // CASE OF EQUALITY
        if(root->left == NULL && root->right == NULL){
            Node* waste = root;
            delete waste;
            return NULL;
        }
        else if(root->left == NULL && root->right != NULL){
            Node* rRight = root->right,*waste = root;
            delete waste;
            return rRight;
        }
        else if(root->left != NULL && root->right == NULL){
            Node* lRight = root->left,*waste = root;
            delete waste;
            return lRight;
        }
        else{
            // Both side of nodes exist ->
            Node* f = findRightMaxNode(root->right);
            root->data = f->data;
            root->right = deleteInBST(root->right,root->data);
            return root;
        }
    }
}
// Given a sorted Array Build Balanced BST
Node* newBst(ll* arr,ll s,ll e){
    if(s>e){
        return NULL;
    }
    if(s==e){
        return new Node(arr[s]);
    }
    Node* root = NULL;
    int mid = (s+e)/2;
    root = new Node(arr[mid]);
    root->left = newBst(arr,s,mid-1);
    root->right = newBst(arr,mid+1,e);
    return root;
}
bool IsBST(Node* root,int minVal = INT_MIN,int maxVal=INT_MAX){
    if(root == NULL) return true;

    if(root->data>= minVal && root->data<=maxVal && IsBST(root->left,minVal,root->data) &&
         IsBST(root->right,root->data,maxVal)) return true;

    return false;
}
class LL{
public:
    Node* head;
    Node* tail;
    LL(){
        head = tail = NULL;
        // head->left = head->right = tail->
    }
}; 
LL treeToLinkedLL(Node* root){
    LL p;
    if(root == NULL) return p;

    if(root->left == NULL && root->right == NULL){
        p.head = p.tail = root;
        return p;
    }
    else if(root->left == NULL && root->right != NULL){
        LL rightTree = treeToLinkedLL(root->right);
        p.head = root;
        p.head->right = rightTree.head;
        p.tail = rightTree.tail;
        // DOubly linked LIST 
        rightTree.head->left = root;
        return p;
    }
    else if(root->left != NULL && root->right == NULL){
        LL leftTree = treeToLinkedLL(root->left);
        p.head = leftTree.head;
        p.tail = root;
        leftTree.tail->right = root;
        // Doubly Linked List ->
        root->left = leftTree.head;
        
        return p;
    }
    else{
        // Bring Linked List from both the ends
        LL leftTree = treeToLinkedLL(root->left);
        LL rightTree = treeToLinkedLL(root->right);

        p.head = leftTree.head;
        p.tail = rightTree.tail;
        // Joined Root with both ends
        leftTree.tail->right = root;
        root->right = rightTree.head;
        // Doubly Linked List
        root->left = leftTree.tail;
        rightTree.head->left = root;
        return p;
    }
}
Node* createTreePreOrderInOrder(ll* inorder,ll*preOrder,ll inS,ll inE,ll &i){
    if(inS > inE) return NULL;
    if(i == n) return NULL;
    ll val = preOrder[i++];
    ll s=inS,e = inE;
    ll index = -1;
    while(s<=e){
        ll mid = (s+e)/2;
        if(inorder[mid] == val){
            index = mid;
            break;
        }
        else if(inorder[mid]>val){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    Node* root = new Node(val);
    cout<<"val -> "<<val<<" -> "<<inorder[index]<<endl;
    root->left = createTreePreOrderInOrder(inorder,preOrder,inS,index-1,i);
    root->right = createTreePreOrderInOrder(inorder,preOrder,index+1,inE,i);
    return root;
}
Node* createTreePostOrderInOrder(ll *inorder,ll* postorder,ll inS,ll inE,ll postS,ll postE){
    // EIther construct right tree first then left tree or divide ->post order Array Accordingly ->
    if(inS > inE) return NULL;

    if(inS == inE){
        return new Node(inorder[inS]);
    }
    ll val = postorder[postE];
    ll index = -1;
    for(ll i=inS;i<=inE;i++){
        if(val == inorder[i]){
            index = i;
            break;
        }
    }
    ll leftTreeSize = inS - index;
    ll rightTreeSize = inE - index;

    Node* root = new Node(val);
    root->left = createTreePostOrderInOrder(inorder,postorder,inS,index-1,postS,postS+leftTreeSize-1);
    root->right = createTreePostOrderInOrder(inorder,postorder,index+1,inE,postE-rightTreeSize-1,postE);
    return root;
}
int main()
{
    // Practice - 1 
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cin>>n;
    // ArrIn(n) cin>>arr[i];
    // Node* root = NULL;
    // ArrIn(n){
    //     root = createTree(root,arr[i]);
    // }
    // cout<<root; // Level Order Print -> 
    // cout<<"PreOrder Traversal - "; preOrderTraversal(root);
    // cout<<"\nPostOrder Traversal - "; postOrderTraversal(root);
    // cout<<"\nInOrder Traversal - "; inOrderTraversal(root);
    // cout<<"\nHeight Balanced Tree ? - "; myPair ans = heightBalanced(root); cout<<ans.isBalanced<<endl;
    // int key;
    // cin>>key;
    // root = deleteInBST(root,key);
    // cout<<root;
    // cout<<"Enter size and elements of sorted Array - "; cin>>n; ArrIn(n) cin>>arr[i];
    // Node* root2 = newBst(arr,0,n-1);
    // cout<<root2;
    // // Given a tree -> IsBST;
    // IsBST(root2) ? cout<<"It is a Binary Search Tree\n" : cout<<"It is not a BST\n";
    // LL ansLinkedList = treeToLinkedLL(root);
    // Node* temp = ansLinkedList.head;
    // while(temp != NULL){
    //     cout<<temp->data<<" -> ";
    //     temp = temp->right;
    // }
    // cout<<endl;
    // Node* temp2 = ansLinkedList.tail;
    // while(temp2 != NULL){
    //     cout<<temp2->data<<" <- ";
    //     temp2 = temp2->left;
    // }
    // cout<<endl;


    // Inorder - preOrder Tree 
    // 
    ll* inorder,*postorder,*preorder;
    cout<<"Input array size and inorder preOrder traversal of tree "<<endl;
    cin>>n;
    inorder = new ll[n];
    preorder = new ll[n];
    ArrIn(n) cin>>inorder[i];
    ArrIn(n) cin>>preorder[i];
    ll i=0;
    Node* root3 = createTreePreOrderInOrder(inorder,preorder,0,n-1,i);
    cout<<root3;
    return 0;
}    