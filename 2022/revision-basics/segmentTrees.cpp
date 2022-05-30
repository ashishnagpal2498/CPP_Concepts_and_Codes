// Segment Trees
#include<bits/stdc++.h>
using namespace std;

// Basically we need to understand what should be stored in Node of Segment Tree

// Build Tree - it will be a linear Array only index - node and Children - 2*index and 2*index+1
int tree[100];
void buildTree(int node,int start,int end,int*arr){
    if( start == end){
        tree[node] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    buildTree(2*node,start,mid,arr);
    buildTree(2*node+1,mid+1,end,arr);

    tree[node] = tree[2*node] + tree[2*node+1];
}

void updateTree(int node,int start,int end,int ind,int val,int*arr)
{
    if(start == end){
        arr[ind] = val;
        tree[node] = val;
        return;
    }
    int mid = (start+end)/2;
    if(start<=ind && ind<=mid){
        // Left tree -
        updateTree(2*node,start,mid,ind,val,arr);
    }
    else {
        updateTree(2*node +1,start ,mid+1,ind,val,arr);
    }
    tree[node] = tree[2*node] + tree[2*node+1];
}
// Update Node - Check if left tree ki side or right Tree ki side hai

// Query - 

int query(int node,int start,int end,int l,int r){
    if(r < start || l > end){
        return 0;
    }

    // completely inside -
    if(l<=start && end<=r){
        return tree[node];
    }

    // Partial
    int mid = (start+end)/2;
    int p1 = query(2*node,start,mid,l,r);
    int p2 = query(2*node+1,mid +1,end,l,r);
    return p1 + p2;
}

void printTree(int* arr){
    queue<int> q1;
    if(tree[1] == -1) return;
    q1.push(1);
    q1.push(-1000);
    int i=1;
    while(!q1.empty()){
        int topEle = q1.front();
        q1.pop();
        if(topEle == -1000){
            cout<<"\n";
            if(!q1.empty()) q1.push(-1000);
        }
        else{
            cout<<tree[topEle]<<" ";
            if(tree[topEle*2] != -1 ) q1.push(topEle*2);
            if(tree[topEle*2 +1 ] != -1) q1.push(2*topEle +1);
        }
    }
}

int main(){
    int q,n,*arr,a,b;
    memset(tree,-1,sizeof(tree));
    char c;
    // int n = sizeof(arr)/sizeof(int);
    cin>>n>>q;
    arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    buildTree(1,0,n-1,arr);
    printTree(arr);
    while(q){
        cin>>c;
        if(c == 'q'){
            cin>>a>>b;
            // a = l
            // b = r
            cout<<query(1,0,n-1,a-1,b-1)<<endl;
        }
        else{
            cin>>a>>b;
            // a = index
            // b = value
            updateTree(1,0,n-1,a-1,b,arr);
        }
        q--;
    }

}