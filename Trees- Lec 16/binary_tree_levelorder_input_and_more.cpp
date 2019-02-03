//23-12-18
#include<iostream>
#include<queue>
using namespace std;
class node{
public:
    int data;
    node* left;
    node*right;
    node(int d)
    {
        data = d;
        left =NULL;
        right = NULL;
    }
};

// Input function - Recursive
node* input_tree()
{   int d; cin>>d;
    if(d==-1) return NULL;
    node * root = new node(d);
    root->left = input_tree();
    root->right = input_tree();
}
// Pre- order printing
void print_preorder(node*root)
{
    if(root==NULL) return;
    cout<<root->data<<"  ";
    print_preorder(root->left);
    print_preorder(root->right);
}

//Level order input-
void level_orderInput(node* &root)
{
    //d is the data to be put on the node, 
    // create a new node and assign to root;

    int d;
    cin>>d;
    root = new node(d);

    queue<node*> q1;
    q1.push(root);
    while(!q1.empty())
    {
        node* front = q1.front();
        q1.pop();
        // Take two variable of the parent node
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1)
        {
            front->left = new node(c1);
            q1.push(front->left);
        }
        if(c2!=-1)
        {
            front->right = new node(c2);
            q1.push(front->right);
        }
    }

}

// Level order traversal with spacing at each level
//For spacing put a flag for each
void level_order_print(node*root)
{
    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty())
    {
        node* parent = q1.front();
        q1.pop();
        if(parent==NULL)
        {   cout<<endl;
            if(!q1.empty())
            {
                q1.push(NULL);
            }
        }
        else{
            cout<<parent->data<<"  ";
            if(parent->left)
            {
                q1.push(parent->left);
            }
            if(parent->right)
            {
                q1.push(parent->right);
            }
        }
    }
}
int height(node*root)
{
    if(root==NULL) return 0;

    return 1+ max(height(root->left),height(root->right));
}

//Diameter of a Tree - 
int diameter(node*root)
{
    if(root==NULL) return 0;

    // We have three options
    int opt1 = height(root->left) + height(root->right);
    int opt2 = diameter(root->left);
    int opt3 = diameter( root->right);
    //this algo takes o(n^2)
    return max (opt1,max(opt2,opt3)); 
}


// Optimised Diameter function
class myPair{
public:
    int diameter;
    int height;
};

myPair fast_Diameter(node* root)
{
    myPair p;
    if(root==NULL)
    {
        p.diameter=0;
        p.height =0; 
        return p;
    }
    //This is POST ORDER Travesal - Bottom up approach
    myPair left = fast_Diameter(root->left);
    myPair right = fast_Diameter(root->right);

    // Current height of tree will be given as h1+h2 - max - d1,d2
    int d1 = left.diameter;
    int h1 = left.height;
    int d2 = right.diameter;
    int h2 = right.height;

    //this gives the diameter of the node and height
    p.diameter = max(h1+h2,max(d1,d2));
    p.height = max(h1,h2)+1;
    return p;
}

//Print nodes at kth level
void level_order_Kth_print(node*root,int k)
{
    if(root==NULL) return;

    if(k==0)
    {
        cout<<root->data<<" ";
    }
    level_order_Kth_print(root->left,k-1);
    level_order_Kth_print(root->right,k-1);
}

//Find subset - such that - maximum sum , and parent & children does not include
//Either Root node will be included or excluded depending upon the maximum value
//if include - does not include child nodes
class mySumPair{
public:
    int inc;
    int excl;
}; //Two values will be there by the class , including and excluding

mySumPair maxSumSubset(node*root)
{   mySumPair p;
    if(root==NULL)
    {
        p.inc=0;
        p.excl = 0;
        return p;
    }
    mySumPair left = maxSumSubset(root->left);
    mySumPair right = maxSumSubset(root->right);

    //if i include the root node the the left and right should be excl
    p.inc = root->data + left.excl + right.excl;
    // If root is not taken then , two options 
    p.excl = max(left.inc,left.excl) + max(right.inc,right.excl);

    return p;
}
void mirror_image(node*root)
{
    if(root==NULL) return;
    swap(root->left,root->right);
    mirror_image(root->left);
    mirror_image(root->right);
}


int main()
{
    node* root = NULL;
    // Recursive input
    // root = input_tree();

    //Level order - iterative input
    level_orderInput(root);
    print_preorder(root);
    cout<<endl;
    level_order_print(root);
    cout<<"\n Diamter of the given tree is  "<<endl;
    cout<<diameter(root);
    myPair ans = fast_Diameter(root);
    cout<<"\n Fast Diameter "<<ans.diameter<<endl;
    level_order_Kth_print(root,1);
    mySumPair ans_pair = maxSumSubset(root);
    int ans_val = max(ans_pair.inc,ans_pair.excl);
    cout<<"\n Maximum value "<<ans_val<<endl; 
    cout<<"Mirror Image of tree \n ";
    mirror_image(root);
    level_order_print(root);
    return 0;
}