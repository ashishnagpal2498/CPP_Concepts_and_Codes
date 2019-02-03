//Binary Tree Imeplementation
//10_01_19
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

//Building the tree 
//So we can either use the return statement or use & reference parameter
node* BuildTree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node* n = new node(d);
    n->left = BuildTree();
    n->right = BuildTree();

    return n;
}

//Pre - order traversal
void printTree(node* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);

}
//level order print -
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
//Inorder - traversal
//Post order Traversal
//count nodes in a tree , using recursion and iteration-
int count_nodes(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
   // this is similar to what - return 1 + count_nodes(root->left) + root->right
    int left_tree_ans = count_nodes(root->left);
    int right_tree_ans = count_nodes(root->right);
    return 1+ left_tree_ans + right_tree_ans;
}
//height of tree 

int height(node*root)
{
    if(root==NULL) return 0;

    int height_left = height(root->left);
    int height_right = height(root->right);

    return 1 + max(height_left,height_right);
}
   void topView(node * root) {
static bool flag = false;
        static int r_data = root->data;
        if(root==NULL) return;

        if(!flag)
        {   cout<<root->data<<" ";
            topView(root->left);
        //reached till leftmost node,
        
            if(root->data!=r_data)
            {
                return;
            }
            else{
                flag = true;
               // cout<<root->data<<" ";
                topView(root->right);
            }
        }
        else{
            cout<<root->data<<" ";
        topView(root->right);
        
        }

    }

//Replace the root node with sum of its children
    //All the decendants
class sumpair_2{
public:
    int sum;
    sumpair_2()
    {
        sum  = 0;
    }

};

sumpair_2 replace_sum(node*&root)
{
    sumpair_2 p;
    if(root==NULL)
    {
        return p;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        p.sum = root->data;
        return p;
    }
    sumpair_2 left_tree = replace_sum(root->left);
    sumpair_2 right_tree = replace_sum(root->right);
      p.sum = root->data + left_tree.sum + right_tree.sum;
        //leave node -
    root->data = left_tree.sum + right_tree.sum;
      return p;
}

//Simple method
int replace_sum2_easy(node*&root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return root->data;
    }
    int left_ans = replace_sum2_easy(root->left);
    int right_ans = replace_sum2_easy(root->right);
    int temp = root->data;
    root->data = left_ans+right_ans;
    return temp + root->data;
}

//BUILD TREE USING PREORDER AND INORDER TRAVERSAL
//Two traversal given create 
//1) Pick up the index from pre order
//2) find the node in the inorder 
//3) call the left and right tree

node* create_tree_from_traversal(int*inorder,int*preorder,int s,int e)
{   static int i = 0;
    if(s>e)
    {
        return NULL;
    }
    node* root = new node(preorder[i]);
    int index = -1;
    for(int j=s;j<=e;j++)
    {
        if(inorder[j]==preorder[i])
        {
            index = j;
            break;
        }
    }
   i++;
   root->left = create_tree_from_traversal(inorder,preorder,s,index-1);
   root->right = create_tree_from_traversal(inorder,preorder,index+1,e);
   return root; 
}
int main()
{
    node* root = NULL;
    root = BuildTree();
    printTree(root);
    cout<<endl;
    level_order_print(root);
    cout<<endl;
    cout<<"No of Nodes in a tree "<<count_nodes(root)<<endl;
    cout<<"Height of tree  "<<height(root);
    cout<<endl<<" Top view is \n";
    // topView(root);    
    replace_sum2_easy(root);
   // sumpair_2 ans = replace_sum(root);
    level_order_print(root);   
    cout<<"\nCreate Tree From Preorder and inorder traversal "<<endl;
    int inO[] = {3,2,8,4,1,6,7,5};
    int pre[] = {1,2,3,4,8,5,6,7};
    int n = sizeof(pre)/sizeof(int);
    node* treefromtraversal = create_tree_from_traversal(inO,pre,0,n-1);
    level_order_print(treefromtraversal);
}