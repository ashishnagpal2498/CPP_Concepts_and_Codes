// Maximum Skills Postman
#include<bits/stdc++.h>
using namespace std;
void buildTree(int* tree,vector<pair<int,int> > items,int index,int start,int end)
{
    if(start>end) return;
    if(start == end)
    {
        tree[index] = items[start].second;
        return;
    }
    int mid = (start+end)/2;
    buildTree(tree,items,2*index,start,mid);
    buildTree(tree,items,2*index+1,mid+1,end);
    tree[index] = max(tree[2*index],tree[2*index+1]);
}
int query(int* tree,vector<pair<int,int> > items,int index,int start,int end,int l,int r)
{
    if(items[start].first > r || items[end].first < l) return INT_MIN;

    if(items[start].first>= l && items[end].first <= r){
        return tree[index];
    }
    int mid = (start+end)/2;
    int leftVal = query(tree,items,2*index,start,mid,l,r);
    int rightVal = query(tree,items,2*index+1,mid+1,end,l,r);
    return max(rightVal,leftVal);
}
int main()
{
    int n,b,s,l,r,q;
    cin>>n;
    int* tree = new int[(4*n)+1];
    vector<pair<int,int> > items(n);
    for(int i=0;i<n;i++)
    {   cin>>b>>s;
        items[i] = make_pair(b,s);
    }
    sort(items.begin(),items.end());
    for(int i=0;i<n;i++)
    {
        cout<<items[i].first<<" "<<items[i].second<<endl;
    }
    cout<<"Building tree \n";
    for(int i=0;i<(4*n)+1;i++) tree[i] = 0;
    buildTree(tree,items,1,0,n-1);
    cout<<"Tree build \n";
    for(int i=0;i<(4*n)+1;i++)
    {
        cout<<tree[i]<<"   ";
    }
    cout<<endl;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<"Maximum skill in given budget - "<<l<<" "<<r<<" is:"<<endl;
        cout<<query(tree,items,1,0,n-1,l,r)<<endl;
    }
    return 0;
}