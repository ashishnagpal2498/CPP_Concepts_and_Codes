// Buying laptop - Postman-
#include<bits/stdc++.h>
using namespace std;
void buildTree(int* tree,vector<pair<int,int> > items,int index,int start,int end)
{
    if(start> end) return;

    if(start == end)
    {
        tree[index] = items[start].second;
        return;
    }
    int mid = (start+ end)/2;
    buildTree(tree,items,2*index,start,mid);
    buildTree(tree,items,2*index+1,mid+1,end);
    int leftTreeValue = tree[2*index];
    int rightTreeValue = tree[2*index+1];
    tree[index] = max(leftTreeValue,rightTreeValue);
}

int query(int * tree,vector<pair<int,int> > items,int index,int start,int end,int l,int r)
{   
    // Out of range query
    if(items[start].first > r || items[end].first < l) return INT_MIN;

    if(items[start].first >= l && items[end].first <= r )
    {
        return tree[index];
    }
    int mid = (start+end)/2;
    int leftTreeValue = query(tree,items,2*index,start,mid,l,r);
    int rightTreeValue = query(tree,items,2*index+1,mid+1,end,l,r);
    return max(leftTreeValue,rightTreeValue);
}

int main(){
    int n,p,r;
    cin>>n;
    int *tree = new int[(4*n)+1];
    vector<pair<int,int> > items(n+1);
    items[0] = make_pair(0,0);
    for(int i=1;i<=n;i++)
    {
        cin>>p>>r;
        items[i] = make_pair(p,r);
    }
    sort(items.begin(),items.end());
    for(int i=0;i<=n;i++)
    {
        cout<<items[i].first<<" "<<items[i].second<<endl;
    }
    for(int i=0;i<(4*n)+1;i++) tree[i] = INT_MIN;
    buildTree(tree,items,1,0,n);
    cout<<"TREE ------ \n";
    for(int i=0;i<(4*n)+1;i++)
    {
        cout<<tree[i]<<"   ";
    }
    cout<<endl;
    int q;
    cin>>q;
    int l;
    while(q--)
    {
        cin>>l>>r;
        cout<<"Maximum Rating in given price range"<<l<<" "<<r<<" is:\n";
        cout<<query(tree,items,1,0,n,l,r)<<endl;
    }
    return 0;
}