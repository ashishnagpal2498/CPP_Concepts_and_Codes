//Trees
//Binary trees

#include<iostream>
#include<queue>
using namespace std;
//Oops tell us how data writen , where as data structures are 
// Tree defination - node-

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data =d ;
        left =NULL;
        right = NULL;
    }

};

node* buildTree()
{
    int d;
    // cout<<"Enter data  ";
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    // create a new node
    node* n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;

}
// Preorder Traversal
void print_Tree(node* ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    cout<<ptr->data<<"  ";
    print_Tree(ptr->left);
    print_Tree(ptr->right);
}
void level_order_traversal(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {   
        node* f = q.front();
        cout<<f->data<<"  ";
        q.pop();
        if(f->left)
        {
            q.push(f->left);
        }
        if(f->right)
        {
            q.push(f->right);
        }

    }

}

int diameter(node* root)
{
    if(root==NULL) return 0;

    return diameter(root->left) + diameter(root->right) +1;
}

void level_order_traversal2(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    // Putting spacing after every level 
    // put null after ever entering of root
    while(!q.empty())
    {   
        node* f = q.front();
        if(f==NULL)
        {
            q.pop();
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
        cout<<f->data<<"  ";
        q.pop();
        if(f->left)
        {
            q.push(f->left);
        }
        if(f->right)
        {
            q.push(f->right);
        }
    }
    }

}

// Inorder travesal
void Inorder(node* root)
{
    if(root==NULL) return;

    Inorder(root->left);
    cout<<root->data<<"  ";
    Inorder(root->right);
}

// Post order Traversal

void Post_order(node*root)
{
    if(root==NULL)
    {
        return;
    }
    // Left Right then Root
    Post_order(root->left);
    Post_order(root->right);
    cout<<root->data<<"  ";
}
int no_of_Nodes(node*root)
{
    if(root==NULL) return 0;
        // Left subtree se puchh lo , bata ,
    //Right subtree will tell the ans
    // Add all the sum + root node.
    return 1 + no_of_Nodes(root->left) + no_of_Nodes(root->right);
}

int height(node* root)
{
    if(root==NULL)
        return 0;
    return 1+ max(height(root->left),height(root->right));
}
int main()
{
    node * root =NULL;
    root = buildTree();
    print_Tree(root);
    cout<<"\n Level order traversal "<<endl;
    level_order_traversal2(root);
    
    cout<<"\n Post Order Traversal \n";
    Post_order(root);

    cout<<"\n Inorder traversal"<<endl;
    Inorder(root);

    cout<<"\n No . of nodes "<<endl;
    cout<<no_of_Nodes(root);
    cout<<"\n Height "<<endl;
    cout<<height(root);
    cout<<"\n Diameter of tree is "<<endl;
    cout<<diameter(root);
    return 0;
}