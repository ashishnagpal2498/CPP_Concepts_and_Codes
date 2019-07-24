//sum at k- level
#include<iostream>
#include "generic_tree_header.h"
using namespace std;
int sumAtK_level(node*root,int k)
{
    if(root==NULL) return 0;

    if(k==0) return root->data;

    int ans = 0;
    for(int i=0;i<root->noofChild;i++)
    {
       ans+=sumAtK_level(root->nChild[i],k-1);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    node*root = NULL;
    root = BuildTree();
    // printTree(root);
    int k;
    cin>>k;
    cout<<sumAtK_level(root,k);
    return 0;
}