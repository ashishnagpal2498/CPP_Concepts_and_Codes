//BST implementation and revision OWN
#include<iostream>
#include<queue>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node* createTree(node*root,int d)
{
    if(root==NULL)
    {
        return new node(d);
    }
    if(root->data>d)
    {
        root->left = createTree(root->left,d);
    }
    else
    {
        root->right = createTree(root->right,d);
    }
    return root;
}

node* buildTree()
{
    int d;
    cin>>d;
    node* root = NULL;
    while(d!=-1)
    {
        root = createTree(root,d);
        cin>>d;
    }
    return root;
}
void preorder_print_tree(node*root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder_print_tree(root->left);
    preorder_print_tree(root->right);
}
void levelorder_print_tree(node*root)
{
    if(root==NULL) return;
    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty())
    {
        node* front_val = q1.front();
        q1.pop();
        if(front_val==NULL)
        {
            cout<<endl;
            if(!q1.empty())
            {
                q1.push(NULL);
            }
        }
        else
        {
            cout<<front_val->data<<" ";
            if(front_val->left!=NULL)
            {
                q1.push(front_val->left);
            }
            if(front_val->right!=NULL)
            {
                q1.push(front_val->right);
            }
        }
    }
}
//Element search - in BST
bool search_an_element_tree(node*root,int key)
{
    if(root==NULL) return false;
    if(root->data ==key)
    {
        return true;
    }
    if(root->data>key)
    {
        return search_an_element_tree(root->left,key);
    }
    if(root->data<key)
    {
        return search_an_element_tree(root->right,key);
    }
}
void inorder_print_tree(node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder_print_tree(root->left);
    cout<<root->data<<" ";
    inorder_print_tree(root->right);
}

//Check if a tree is Balanced BST or not
//left subtree and right subtree , difference of height should be abs 1;
//And both the trees should themselves be balanced
class myPair_balancedTree{
public:
    int height;
    bool isbalanced;
    myPair_balancedTree()
    {
        height = 0;
        isbalanced = true;
    }
};

myPair_balancedTree balancedBST(node*root)
{
    myPair_balancedTree root_obj;
    if(root==NULL)
    {
        return root_obj;
    }

    //Left subtree se height and isbalanced pata karke aaja
    myPair_balancedTree left_tree = balancedBST(root->left);
    myPair_balancedTree right_tree = balancedBST(root->right);

    int diff = abs(left_tree.height-right_tree.height);
    root_obj.height = 1+ max(left_tree.height, right_tree.height);
    if(diff<=1&&left_tree.isbalanced&&right_tree.isbalanced)
    {
        root_obj.isbalanced = true;
    }
    else
    {
        root_obj.isbalanced = false;
    }
    return root_obj;
}

//check if a given tree is BST or not - 
//Wrong approach - can be - check left subtree , right subtree and root left right
//BUT that IS NOT TRUE

//Approach - KEEP A UPPER LIMIT AND A LOWER LIMIT WITH ROOT

bool isBst(node*root,int min_val = -100000,int max_val = 1000000)
{
    if(root==NULL) return true;
    
    if(root->data<max_val&&root->data>min_val&&isBst(root->left,min_val,root->data)
        && isBst(root->right,root->data,max_val))
    {
        return true;
    }
    return false;
}

//Create a balanced BST using sorted array
node* bst_from_array(int *arr,int beg,int end)
{
    if(beg>end)
    {
        return NULL;
    }
    if(beg==end)
    {
        //there is only one element
        return new node(arr[beg]);
    }
    int mid = (beg+end)/2;
    node* root = new node(arr[mid]);
    root->left = bst_from_array(arr,beg,mid-1);
    root->right = bst_from_array(arr,mid+1,end);
    return root;
}

node* findnode(node*root)
{
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}

//deletion of node from BST
node* delete_in_BST(node*root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        //either root can have 0 , 1 child or 2 children
        if(root->left==NULL&&root->right==NULL)
        {
            //the node to be deleted is the leave node
            delete root;
            return NULL;
        }

        //If the node has 1 child 
        //left child
       else if(root->left!=NULL&&root->right==NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        //if right child exist
        else if(root->left==NULL&&root->right!=NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child case
        else
        {   
            //find out the node which is smallest in right subtree
            //or largest in left subtree
            node* element_tobe_replace = findnode(root->right);
            root->data = element_tobe_replace->data;
            root->right = delete_in_BST(root->right,root->data);

        }
    }
    else if(root->data>key)
    {
        root->left = delete_in_BST(root->left,key);
    }
    else
    {
        root->right = delete_in_BST(root->right,key);
    }

}

//flatten the tree into a linked list
//we cannot change the structure of node;
class linkedlist{
public:
    node*head;
    node*tail;
    linkedlist()
    {
        head = tail = NULL;
    }
};

linkedlist tree_2_LL(node*root)
{
    linkedlist p;
    if(root==NULL)
    {
        return p;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        p.head = root;
        p.tail = root;
        return p;
    }
    else if(root->left!=NULL&&root->right==NULL)
    {
        linkedlist left_tree = tree_2_LL(root->left);

        left_tree.tail->right = root;
        p.head = left_tree.head;
        p.tail = root;
        return p;
    }
    else if(root->left==NULL&&root->right!=NULL)
    {
        linkedlist right_tree = tree_2_LL(root->right);

        p.head = root;
        root->right = right_tree.head;
        p.tail = right_tree.tail;
        return p;
    }
    else
    {
        linkedlist left_tree = tree_2_LL(root->left);
        linkedlist right_tree = tree_2_LL(root->right);

        p.head = left_tree.head;
        left_tree.tail->right = root;
        root->right = right_tree.head;
        p.tail = right_tree.tail;
        return p;


    }
}

//Lowest Common ancestor of the two nodes- IN BST
node* lowestCommonancesstor(node*root , int v1,int v2)
{
    if(root->data< v1&&root->data<v2)
    {
      return  lowestCommonancesstor(root->right,v1,v2);
    }
    else if(root->data>v1 &&root->data>v2)
    {
       return lowestCommonancesstor(root->left,v1,v2);
    }
    return root;
}

//Top View of Binary tree
//horizontal distance of node left to x is x-1 and right - x+1

//Catalan's Number - Online video -
//Bionomial Cofficient - 
//Count Bsts
//number will be given from 1 to N we need to find the no. of bsts formed
// f(n) = sum where i goes from i to N( f(i-1)*f(n-i));
//No. of BST is given by - Catalan's number 1 1 2 5 14

int catalan(int n)
{
    if(n==0)
    {
        return 1;
    }
    //Self work 
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans+= catalan(i-1) * catalan(n-i);
    }
    return ans;
}


int tiling(int n)
{
    if(n==0) return 0;
    if(n==1||n==2||n==3)
    {
        return 1;
    }
    int ans = 0;
    ans = tiling(n-1) + tiling(n-4);
    return ans;
}


int main()
{
    node* root;
    root = buildTree();
    preorder_print_tree(root); cout<<endl;
    levelorder_print_tree(root); cout<<endl;
    //Inorder Traversal of BST gives sorted print 
    inorder_print_tree(root); cout<<endl;
    int k;
    cin>>k;
    search_an_element_tree(root,k) ? cout<<"Element found \n":cout<<"Element n found\n";
    myPair_balancedTree ans = balancedBST(root);
    cout<<"Is the given BST balanced ? "<<ans.isbalanced;
    cout<<"\n Is given tree a BST ? ";
    isBst(root) ? cout<<" YES \n" : cout<<"NO \n";

    int arr[] = {1,2,3,4 ,5,6 ,7,8};
    node* arr_tree = bst_from_array(arr,0,7);
    levelorder_print_tree(arr_tree); cout<<endl;

    int delnode ;
    cout<<"enter the node to be deleted "; cin>>delnode;
    root = delete_in_BST(root,delnode);
    levelorder_print_tree(root);
    cout<<endl;
    linkedlist ll_from_tree = tree_2_LL(root);
    node* temp = ll_from_tree.head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp = temp->right;
    }
    int v1,v2; //Nodes v1 and v2 
    cin>>v1>>v2;
    node* common_ancesstor = lowestCommonancesstor(root,v1,v2);
    cout<<"\nLowest Common ancestor is  "<<common_ancesstor->data;
    cout<<"Number of BSTS using catalan number is ";
    cout<<catalan(3);
    cout<<endl<<tiling(4);
    return 0;
}