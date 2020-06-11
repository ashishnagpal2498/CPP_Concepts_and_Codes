// Advance Data Structure - Segment Trees
#include<iostream>
using namespace std;
void build(int *tree,int *a,int index,int start,int end)
{   //base case -
    if(start>end) return;
    if(start == end)
    {   // Leave Node filling --
        tree[index] = a[start];
        return;
    }
    int mid = (start+end)/2;
    //Left Tree -
    build(tree,a,2*index,start,mid);
    // Right tree
    build(tree,a,2*index+1,mid+1,end);
     
    tree[index] = min(tree[2*index],tree[2*index +1]); 
    return;
}
int query(int *tree,int index,int start,int end,int l,int r)
{
    if(start > r || end < l) return INT_MAX;

    if(start >= l && end <= r)
    {
        return tree[index];
    }
    int mid = (start+end)/2;
    int leftAns = query(tree,2*index,start,mid,l,r);
    int rightAns = query(tree,2*index+1,mid+1,end,l,r);
    return min(rightAns,leftAns);
}
int main()
{
    int arr[] = {1,3,2,-2,4,5};
    int n = 6;

    int *tree = new int[(4*n)+1];
    // for(int i=0;i<(4*n)+1;i++) tree[i] = INT_MAX;
    build(tree,arr,1,0,n-1);
    for(int i=1;i< (4*n)+1 ;i++)
    {
        cout<<tree[i]<<" ";
    }
    int no_of_q;
    cin>>no_of_q;
    int l,r;
    while(no_of_q--)
    {
        cin>>l>>r;
        cout<<"Min element between l and r"<<l<<" "<<r<<endl;
        cout<<query(tree,1,0,n-1,l,r)<<endl;
    }

    return 0;
}