// Range Minimum Query - Segment Tree;

#include<bits/stdc++.h>
using namespace std;

int tree[100005];

void buildTree(int node,int start,int end,int* arr){
    if(start == end){
        tree[node] = arr[start];
        //cout<<node<<" -> "<<tree[node]<<endl;
        return;
    }
    int mid = (start+end)/2;
    buildTree(2*node,start,mid,arr);
    buildTree(2*node+1,mid+1,end,arr);
    tree[node] = min(tree[2*node],tree[2*node+1]);
}

void update(int node,int start,int end,int index,int val,int* arr){
    if(start == end){
        arr[start ] = val;
        tree[node] = val;
        return;
    }
    int mid = (start+end)/2;
    if(index>=start && index<=mid){
        update(2*node,start,mid,index,val,arr);
    }
    else{
        update(2*node+1,mid+1,end,index,val,arr);
    }
    tree[node] = min(tree[2*node],tree[2*node+1]);
}

int query(int node,int start,int end,int l,int r){
    if(r < start || end < l) return INT_MAX;

    if(l<=start && end<=r){
        return tree[node];
    }

    int mid = (start+end)/2;
    int ans1 = query(2*node,start,mid,l,r);
    int ans2 = query(2*node+1,mid+1,end,l,r);
    return min(ans1,ans2);
}

// void printTree(){
//     queue<int> q1;
//     if(tree[1] == INT_MAX) return;
//     q1.push(1);
//     q1.push(-1000);
//     while(!q1.empty()){
//         int topEle = q1.front();
//         q1.pop();
//         if(topEle == -1000){
//             cout<<"\n";
//             if(!q1.empty()) q1.push(-1000);
//         }
//         else{
//             cout<<tree[topEle]<<" ";
//             if(tree[topEle*2] != INT_MAX && tree[topEle*2] != -1  ) q1.push(topEle*2);
//             if(tree[topEle*2 +1 ] != INT_MAX && tree[topEle*2 +1 ] != -1) q1.push(2*topEle +1);
//         }
//     }
// }

int main(){
    int n,q,*arr,a,b;
    char c;
    memset(tree,INT_MAX,sizeof(tree));
    cin>>n>>q;
    arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    buildTree(1,0,n-1,arr);
    //printTree();
    while(q){
        cin>>c;
        if(c == 'q'){
            cin>>a>>b;
            cout<<query(1,0,n-1,a-1,b-1)<<"\n";
        }
        else{
            cin>>a>>b;
            update(1,0,n-1,a-1,b,arr);
        }
        q--;
    }
}