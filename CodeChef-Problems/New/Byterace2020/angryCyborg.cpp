// Angry Cyborg
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t, n, k, m;
int query(int* tree,int index,int s,int e,int l,int r){
    // No overlap

    if(l>e || s>r){
        return INT_MAX;
    }
    if(s>=l && e<=r){
        return tree[index];
    }
    int mid = (s+e)/2;
    int leftChild = query(tree,2*index,s,mid,l,r);
    int rightChild = query(tree,2*index+1,mid+1,e,l,r);

    return min(leftChild,rightChild);


}
void update(int* tree,int index, int s , int e,int i,int val){
    if(i<s || i>e) return;

    if(s==e){
        tree[index] = val;
        return;
    }
    int mid = (s+e)/2;
    update(tree,2*index,s,mid,i,val);
    update(tree,2*index+1,mid+1,e,i,val);
    tree[index] = tree[2*index]+tree[2*index+1];
}
void buildTree(int* tree,int* arr,int index,int s,int end){

    if(s>end) return;

    if(s==end){
        tree[index] = arr[s];
        return;
    }

    // recursive case
    int mid = (s+end)/2;
    buildTree(tree,arr,2*index,s,mid);
    buildTree(tree,arr,2*index+1,mid+1,end);

    int leftVal = tree[2*index];
    int rightVal = tree[2*index+1];

    tree[index] = min(leftVal,rightVal);
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin>>n;
    int* tree = new int[4*n+1];
    memset(tree,INT_MAX,sizeof(tree));
    // buildTree(tree,arr,1,0,n-1);
    int noOfQueries;
    cin>>noOfQueries;
    int l,r;
    while(noOfQueries--){
        cin>>l>>r;
        cout<<update(tree,1,0,n-1,l,r)<<endl;
    }    
    }
    
    return 0;
}