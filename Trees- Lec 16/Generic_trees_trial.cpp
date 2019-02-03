//generic- trees
//implementation
//Depth , height , root node
#include<iostream>
#include<queue>
using namespace std;
// class Node {
// public:
//     int data;
//     int nChild; //number of children
//     Node** childArr;
//     Node(int d, int n) {
//         data = d;
//         nChild = n;
//         if (nChild == 0) {
//             childArr = NULL;
//         }
//         else {
//             childArr = new Node*[nChild];
//         }
//     }
// };


// Node* createTree() {
//     int d, n;
//     cin >> d;

//     if (d == -1) {
//         return NULL;
//     }

//     cin >> n;
//     Node * root = new Node(d, n);
//     for (int i = 0; i < root->nChild; ++i) {
//         root->childArr[i] = createTree();
//     }
//     return root;
// }

// void printTree(Node* root) {
//     if (root == NULL) {
//         return;
//     }

//     cout << root->data << " ";
//     for (int i = 0; i < root->nChild; ++i) {
//         printTree(root->childArr[i]);
//     }
// }


class node{
public:
    int data;
    int noofChild;
    node* *nChild;
    node(int d,int n)
    {   data =d;
            noofChild =n;
        if(n==0)
        {   
            nChild=NULL;
        }
        else{
            nChild = new node*[n];
            
        }
    }
};

void createTree(node* &root)
{    int d,n;
    cin>>d;
    if(d==-1)
    {   //If we dont NULL the root when input it -1 , then junk value is taken by the nChild
        root = NULL;
        return;
    }
    cin>>n; //no of children
    root = new node(d,n);
    for(int i=0;i<root->noofChild;i++)
    {
        createTree(root->nChild[i]);
    }
}
void print(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->noofChild;i++)
    {
        print(root->nChild[i]);
    }
}
//Find the largest value of the node;
int largest_val(node* root)
{
    if(root==NULL)
    {
        return -10000;
    }
    int result_val = root->data;
    for(int i=0;i<root->noofChild;i++)
    {
        int max_of_children = largest_val(root->nChild[i]);
        result_val = max(result_val,max_of_children);
    }
    return result_val;
}
//kth value print
void k_thPrint(node* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<"  ";
    }
    for(int i=0;i<root->noofChild;i++)
    {
        k_thPrint(root->nChild[i],k-1);
    }
}

//Post Order Traversal
void post_order_print(node*root)
{
    if(root==NULL)
    {
        return;
    }
    for(int i=0;i<root->noofChild;i++)
    {
        post_order_print(root->nChild[i]);
    }
    //This will print the Post order Traversal - left right root

    cout<<root->data<<" ";
}

//level order traversal;
//It uses a queue to iterate
// Non recursive function , which uses loop
void level_order(node* root)
{   
    if(root==NULL)
    {
        return;
    }
    queue<node*> q1;
    q1.push(root);
    
    while(!q1.empty())
    {
        node* top_root = q1.front();
        q1.pop();
        for(int i=0;i<top_root->noofChild;i++)
        {   if(top_root->nChild[i]!=NULL)
            q1.push(top_root->nChild[i]);
        }
        cout<<top_root->data<<"  ";
    }

}

//Level order print with space at each level
void level_order_print2(node* root)
{   
    if(root==NULL)
    {
        return;
    }
    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty())
    {   
        node* top_root = q1.front();
        if(top_root==NULL)
        {   q1.pop();
            cout<<endl;
            if(!q1.empty())
            {
                q1.push(NULL);
            }

        }
        else{
        q1.pop();
        for(int i=0;i<top_root->noofChild;i++)
        {   if(top_root->nChild[i]!=NULL)
            q1.push(top_root->nChild[i]);
        }
        cout<<top_root->data<<"  ";
        }
    }

}

//Number of nodes which are greater than a given value-
int cnt_GreaterNodes(node*root,int x)
{
    if(root==NULL)
    {
        return 0;
    }
    int res =0;
    if(root->data > x) res = res+1;
    for(int i=0;i<root->noofChild;i++)
    {
        int subTree_result = cnt_GreaterNodes(root->nChild[i],x);
        res+=subTree_result;
    }
    return res;
}
//Total sum of the nodes -
// Child ans + result of the root node 
int total_sum_Nodes(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int res =0;
    //if(root->data > x) 
    res = res+root->data;
    for(int i=0;i<root->noofChild;i++)
    {
        int subTree_result = total_sum_Nodes(root->nChild[i]);
        res+=subTree_result;
    }
    return res;
}


//No. of nodes in a tree-

int No_of_nodes(node*root)
{
    if(root==NULL) return 0;

    //if node is not null then it is equal to 1;
    int res = 1;
    for(int i=0;i<root->noofChild;i++)
    {
        int child_result = No_of_nodes(root->nChild[i]);
        res +=child_result;
    }
    return res;
}

int familySum(node* root){
    //calculating sum for current family    
    if (root == NULL){
        return 0;
    }

    int curSum = root->data;
    for (int i = 0; i < root->noofChild; ++i) {
        curSum += root->nChild[i]->data;
    }
    return curSum;
}

// node* maxSumNode(node* root) {
//     if (root == NULL) {
//         return NULL;
//     }

//     node * ans = root;
//     int curFamilySum = familySum(root);
    
//     //for every subtree
//     for(int i = 0; i < root->noofChild; ++i){
//         node* childNode = maxSumNode(root->nChild[i]);    //best family in the subtree
//         int childSum = familySum(childNode);

//         if (curFamilySum < childSum){
//             ans = childNode;
//             curFamilySum = childSum; 
//         }
//     }

//     return ans;
// }

int main()
{
    node* root = NULL;
    createTree(root);
    print(root);
    cout<<endl;
    cout<<largest_val(root)<<endl;
    int k;
    cin>>k;

    k_thPrint(root,k);
    cout<<endl;
    post_order_print(root);
    cout<<endl;
    level_order(root);
    cout<<endl;
    level_order_print2(root);

    int val;
    cin>>val;
    cout<<"Nodes greater than "<<val<<" are  "<<cnt_GreaterNodes(root,val)<<endl;
    // cout<<familySum(root);
    // cout<<total_sum_Nodes(root)<<endl;
    // node* ans = maxSumNode(root);
    cout<<"No of nodes in a generic tree are : - "<<No_of_nodes(root);
    return 0;
}