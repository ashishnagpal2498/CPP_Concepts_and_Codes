//BST - Implementation
#include<iostream>
#include<queue>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
//PreOrder Traversal
void preOrder_traversal(node*root)
{   if(root==NULL)
    return ;
    cout<<root->data<<" ";
    preOrder_traversal(root->left);
    preOrder_traversal(root->right);

}
//PostOrder Traversal
void postOrder_traversal(node*root)
{
    if(root==NULL)
    {
        return;
    }
    postOrder_traversal(root->left);
    postOrder_traversal(root->right);
    cout<<root->data<<" ";
}

//Level order traversal
void level_order_traversal(node*root)
{
    if(root==NULL) return;
    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty())
    {
        node* f = q1.front();
        q1.pop();
        if(f==NULL)
        {
            cout<<endl;
            if(!q1.empty())
            {
                q1.push(NULL);
            }
        }
        else{
            if(f->left)
            {
                q1.push(f->left);

            }
            if(f->right)
            {
                q1.push(f->right);
            }
            cout<<f->data<<" ";
        }
    }
}

node* insertNodes(node* root,int d)
{
    if(root==NULL)
    {
        // Its the first node
       // root = new node(d);
        //return root;
    return new node(d);
    }
    if(d < root->data)
    {
        root->left = insertNodes(root->left,d);
    }
    else{
        root-> right= insertNodes(root->right,d);
    }
    return root;
}

//Insertion , until and unless u get a -1 , insert the nodes
void buildTree(node*&root)
{   //node* root =NULL;
    int d;
    cin>>d;
    while(d!=-1)
    {
        root = insertNodes(root,d);
        cin>>d;
    }
}

// Overloading ostream object
ostream& operator<<(ostream& os,node*root)
{
    level_order_traversal(root);
    return os;
}

//Overload istream
istream& operator>>(istream&is,node*&root)
{
    buildTree(root);
    return is;
}

//The Complexity of search function is O(height)

bool search(node*root,int data)
{
    if(root==NULL) return false;

    if(root->data==data)
    {
        return true;
    }
    if(root->data < data)
    {
        search(root->right,data);
    }
    else
    {
        search(root->left,data);
    }
}
//In-order taversal
void inorder_traversal(node*root)
{
    if(root==NULL) return;

    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}


//Function to check if a tree is height balanced or not
//15_01_19
//Lecture BST - 1_08
class myPair{
public:
    int height;
    bool isbalanced;
};

myPair balanced_Tree(node* root)
{
    //post- order
    myPair p;
    if(root==NULL)
    {
        p.height =0;
        p.isbalanced =true;
        return p;
    }

    //Root is not null , so go check for left sub-tree and right sub-tree
    myPair left_subTree = balanced_Tree(root->left);
    myPair right_subTree = balanced_Tree(root->right);

    int diff = abs(left_subTree.height- right_subTree.height);
    if(diff<=1&&left_subTree.isbalanced&&right_subTree.isbalanced)
    {
        p.isbalanced=true;
    }
    else
    {
        p.isbalanced = false;
    }
    //Height of root node
    p.height = 1+ max(left_subTree.height,right_subTree.height);
    return p;
}

//For loop ke andar we'll find the placement-
//Create a formula for the ith node
int countBsts(int n)
{
    //Base Case
    if(n<=0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }

    //Recursive case-
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int left_bsts = countBsts(i-1);
        int right_bsts = countBsts(n-i);
        ans = ans + left_bsts * right_bsts;
    }
    return ans;
}

//Deletion In BST can occur in 3 ways
//Either the node to be deleted has
// 0 child - That is a leave node - delete that node , and return NULL;
// 1 child - if left part exist , then attach that to parent else attach right
// 2 child

node* minNode(node* root)
{
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}

node* deletion_in_BST(node*root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==key)
    {
        //Deletion Perform karni hai
        //Handle the cases of 0,1 child and 2 children of the node

        //if 0 child exist
        if(root->left==NULL&&root->right==NULL)
        {
            delete root;
            return NULL;
        }

        //If the root node has 1 child
        //check if the child is at right or left
        if(root->left==NULL&&root->right!=NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->left!=NULL&&root->right==NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

        //Now if the root node has two children - 
        // we find out the smallest node from right subtree
        node * smallest_node_rightTree = minNode(root->right);
        root->data = smallest_node_rightTree ->data;
        //This will handle the deletion of that replacement node from the-
        //actual position of the node- , This will always have a 0 child
        //or 1 child case , else it won't be the smallest node
        root->right = deletion_in_BST(root->right,root->data);

    }
    if(root->data>key)
    {
        //left tree mein jana hai
        root->left = deletion_in_BST(root->left,key);
        
    }
    else
    {
        root->right = deletion_in_BST(root->right,key);
    }
    return root;
}

//Given a sorted array - 
//Find out the mid point of the array-
//that will become the root node -
//call the left sub tree 

node* Balanced_bst_from_array(int * arr,int n,int beg,int end)
{
    //base case
    if(n==0||beg>end)
    {
        return NULL;
    }
    if(beg==end)
    {
        return new node(arr[beg]);
    }

    int mid = (beg+end)/2;
    node* root = new node(arr[mid]);
    root->left = Balanced_bst_from_array(arr,n/2,beg,mid-1);
    root->right = Balanced_bst_from_array(arr,n/2,mid+1,end);
    return root;
}

//Post order traversal in checking if the binary tree is BST or not
class myBSTpair
{
public:
    int data;
    bool bsthai;

};
//Wrong approach
/*
bool isBst(node*root)
{
    if(root==NULL)
    {
        return true;
    }
    bool left_subtree = isBst(root->left);
    bool right_subTree = isBst(root->right);

    bool root_ans_left = (root->left==NULL||root->data>root->left->data) ? 1:0;
    bool root_ans_right = (root->right==NULL||root->data<root->right->data) ? 1:0;
    if(left_subtree&&right_subTree&&root_ans_left&&root_ans_right)
    {
        return true;
    }
    return false;
}*/

//Maintain a max val and min value of every node and check , if the
//root node is less than upper bound and and greater than lower bound
//then it is a BST
bool isBST_new(node*root,int min_val=-100000,int max_val=100000)
{
    if(root==NULL)
    {
        return true;
    }   
    if(root->data>min_val&&root->data<max_val&&isBST_new(root->left,min_val,root->data)
        && isBST_new(root->right,root->data,max_val)      )
    {
        return true;
    }
    return false;
}

//Flatten a BST into a sorted linked list
//inorder traversal of BST gives sorted output
//important
class linkedlist{
public:
    node*head;
    node*tail;
};

linkedlist tree_2_LL(node*root)
{
    linkedlist root_list;
    if(root==NULL)
    {
        root_list.head = NULL;
        root_list.tail = NULL;
        return root_list;
    }
    else if(root->left==NULL&&root->right==NULL)
    {
        //The given node is the leave node
        root_list.head = root;
        root_list.tail = root;
        return root_list;
    }
    else if(root->left==NULL&&root->right!=NULL)
    {
        linkedlist right_subTree = tree_2_LL(root->right);
        root_list.head = root;
        root->right = right_subTree.head;
        root_list.tail = right_subTree.tail;

        return root_list;
    }
    else if(root->left!=NULL&&root->right==NULL)
    {
        //left subtree exist
        //left subtree ka pointer le aa
        linkedlist left_subtree = tree_2_LL(root->left);
        root_list.head = left_subtree.head;
        //this line means - left_sybtree - head - and tail
        left_subtree.tail->right = root;
        root_list.tail = root;
    }
    else
    {
        linkedlist lefttree = tree_2_LL(root->left);
        linkedlist righttree = tree_2_LL(root->right);

        root_list.head = lefttree.head;
        lefttree.tail->right = root;
        root->right = righttree.head;
        root_list.tail = righttree.tail;
    }
    return root_list;
}


int main()
{
    node * root =NULL;
     //buildTree(root);
        //Now - ostream istream - overloading
    cin>>root;
    // cout<<"PreOrder traversal is\n"; preOrder_traversal(root);
    // cout<<"\nPost Order Traversal Is \n"; postOrder_traversal(root);
    cout<<"\nLevel order traversal is \n"; level_order_traversal(root);
    cout<<endl;
    cout<<"Inorder Traversal";
    inorder_traversal(root);
    cout<<endl;
    // cout<<root;
    // int ele;
    // cin>>ele;
    // search(root,ele) ? cout<<"\n true\n": cout<<"False\n";
    // myPair ans = balanced_Tree(root);
    // ans.isbalanced ? cout<<"Tree is Balanced " : cout<<"Tree is Not Balanced";
   
   // int x;
   // cin>>x;
   //  cout<<"No of BSTs from "<<x<<" Nodes are  "<<countBsts(x);

    //Deletion of node from BST
    // int keyval;
    // cout<<"Enter node to be deleted\n";
    // cin>>keyval;
    // while(keyval!=-1)
    // {   
    //     root = deletion_in_BST(root,keyval);
    //     cout<<"Enter node to be deleted\n";
    //     cin>>keyval;
    // }
    // level_order_traversal(root);
   
    linkedlist hdptr = tree_2_LL(root);
    node*temp = hdptr.head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    cout<<endl;

    // int arr[] = {1,2,3,4,5,6};
    // int n = sizeof(arr)/sizeof(int);
    // node* treefromarr = Balanced_bst_from_array(arr,n,0,n-1);
    
    // level_order_traversal(treefromarr);
    // cout<<"Tree is "; isBST_new(root) ? cout<<"BST \n":cout<<"Not BST";
    return 0;
}