//hackerBlocks - Identical Trees
#include <iostream>
#include "binary_trees_header.h"
using namespace std;
bool structure_identical(node*root,node*root2)
{
    if(root==NULL&&root2==NULL) return true;
    if(root==NULL||root2==NULL) return false;
    return structure_identical(root->left,root2->left)&&structure_identical(root->right,root2->right);
}
int main()
{
    node*root = NULL;
    node*root2 = NULL;
    createTree(root,"true");
    createTree(root2,"true");
    // printTree(root);
    //cout<<endl;
    // printTree(root2);
    structure_identical(root,root2) ? cout<<"true"<<endl : cout<<"false"<<endl;
    return 0;
}