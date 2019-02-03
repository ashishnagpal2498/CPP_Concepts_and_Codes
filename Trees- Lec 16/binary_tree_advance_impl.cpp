//Binary Tree Advance Concepts 
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
        left =  right = NULL;
    }
};
node* buildTree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node* root = new node(d);
    root ->left = buildTree();
    root->right = buildTree();
    return root;
}
//Pre - Order traversal
void preorder_print(node*root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder_print(root->left);
    preorder_print(root->right);
}

//level order input-
void level_order_input(node*&root)
{
    int d;
    cin>>d;
    queue<node*> q1;
    root = new node(d);
    q1.push(root);
    while(!q1.empty())
    {
        node* parent = q1.front();
        q1.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1)
        {
            //left child exist
            parent->left = new node(c1);
            q1.push(parent->left);
        }
        if(c2!=-1)
        {
            parent->right = new node(c2);
            q1.push(parent->right);
        }
    }
}

//height of tree
int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int height_left = height(root->left);
    int height_right = height(root->right);

    return 1 + max(height_left,height_right);
}


//diameter of tree - with more complexity
int diameter_of_tree(node*root)
{
    if(root==NULL) return 0;
    //if the diameter includes the root node
    int root_diameter = height(root->left) + height(root->right);
    //if diameter doesn't include the root node.
    int left_diameter = diameter_of_tree(root->left);
    int right_diamter = diameter_of_tree(root->right);
    
       return max(root_diameter,max(left_diameter,right_diamter));
}

//Diameter of a Tree - better way O(n) - Bottom up approach - post order traversal
class Mypair{
public:
    int height;
    int diameter;
};
Mypair diameter_effective(node*root)
{
    //
    Mypair p;
    if(root==NULL)
    {
        p.height=0;
        p.diameter =0;
        return p;
    }
    Mypair left = diameter_effective(root->left);
    Mypair right = diameter_effective(root->right);

    int d1 = left.diameter;
    int d2 = right.diameter;
    int h1 = left.height;
    int h2 = right.height;

    p.diameter = max(h1+h2,max(d1,d2));
    p.height = 1+ max(h1,h2);
    return p;
}

//create a subset of maximum sum such that , parent and children of that node
//does not include in subset

class Sumpair{
public:
    int include_node;
    int exclude_node;
};

Sumpair Maxsubset_sum(node*root)
{
    Sumpair p;
    if(root==NULL) {
        p.include_node = 0;
        p.exclude_node = 0;
        return p ;}
    Sumpair left = Maxsubset_sum(root->left);
    Sumpair right = Maxsubset_sum(root->right);

    p.include_node = root->data + left.exclude_node + right.exclude_node;
    p.exclude_node = max(left.exclude_node,left.include_node) + max(right.exclude_node,right.include_node);

 return p;   

}

void mirror_image(node*root)
{
    if(root==NULL) return;

    swap(root->left,root->right);
    mirror_image(root->left);
    mirror_image(root->right);
}
void level_order_print(node*root)
{
    //queue is FIFO type of datastructure - hence we are using queue
    if(root==NULL) return;
    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty())
    {
        node* frontval = q1.front();
        q1.pop();
        if(frontval==NULL)
        {
            cout<<endl;
            if(!q1.empty())
            {
                q1.push(NULL);
            }
        }
        //if the front val is not null then only its data exist-
        else 
        {
            cout<<frontval->data<<" ";
            if(frontval->left!=NULL)
            {
                q1.push(frontval->left);
            }
            if(frontval->right!=NULL)
            {
                q1.push(frontval->right);
            }
        }
    }
}

int main()
{
    node* root =NULL;
    //root = buildTree();
    level_order_input(root);
    preorder_print(root);
   cout<<"Height of tree is  "<<height(root);
   cout<<"\n Diameter of tree is  "<<diameter_of_tree(root);
    cout<<"\n Diameter effective gives value  ";
   Mypair ans =diameter_effective(root);
    cout<<ans.diameter;
Sumpair maxSum_ans = Maxsubset_sum(root);
cout<<"maximum sum of subset is  ";
cout<<max(maxSum_ans.exclude_node,maxSum_ans.include_node);
 cout<<endl<<"Level order print is \n";
 level_order_print(root);
    cout<<endl<<"Mirror IMage of the tree is";
cout<<endl<<"Level order print is \n"; mirror_image(root);
 level_order_print(root);
    return 0;

}