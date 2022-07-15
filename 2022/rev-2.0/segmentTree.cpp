// Given q queries and an array of integers. Find Max Element

#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int tree[1000];

    void buildTree(int* arr,int node, int start,int end){
        if(start == end){
            tree[node] = arr[start];
            return;
        }

        int mid = ( start + end)/2;
        buildTree(arr,2*node,start,mid);
        buildTree(arr,2*node+1,mid+1,end);

        tree[node] = max(tree[node*2],tree[2*node+1]); 
    }

    int queryHelper(int node,int start,int end,int l, int r){
        // Base Case -
        // Out of range Query
        if( r < start || end < l) return INT_MIN;

        // Query lies completely within the range
        else if(l<= start && r>= end){
            return tree[node];
        }

        // Partially in the Query
        int mid = ( start + end )/2;
        int leftTree = queryHelper(2*node,start,mid,l,r);
        int rightTree = queryHelper(2*node+1,mid+1,end,l,r);

        return max(leftTree,rightTree);
    }
public:
    SegmentTree(){
        // Tree works on root pointer. Here we are taking NODE -> starting from 1 as root. 
        //tree = new int[1000];
        memset(tree,-1,sizeof(tree));
    }
    void printTree(){

        queue<int> q;
        q.push(1);
        q.push(-1);
        while(!q.empty()){
            int topEleIndex = q.front();
            q.pop();
            if(topEleIndex == -1){
                cout<<"\n";
                if(!q.empty()) q.push(-1);
            }
            else{
                cout<<tree[topEleIndex]<<" ";

                if(tree[topEleIndex*2] != -1){
                    q.push(2*topEleIndex);
                }
                
                if(tree[(2* topEleIndex) + 1] != -1){
                    q.push((2*topEleIndex)+1);
                }
            }
        }
    }
    void insertArray(int* arr,int n){
        buildTree(arr,1,0,n-1);
    }

    int query(int n, int l,int r){
        return queryHelper(1,0,n-1,l-1,r-1);
    }
};


int main(){
    int n, *arr,q,l,r,k,ans;
    cin>>n;
    
    // Dynamic Memory Allocation
    arr = new int[n];
    cout<<"Enter Array Elements ->\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // Tree Creation
    SegmentTree obj;
    obj.insertArray(arr,n);
    
    obj.printTree();
    cout<<"Number of Queries ->\n";
    cin>>k;

    while(k--){
        cout<<"Enter type of Query\n";
        cin>>q;

        switch(q){
            case 1: cout<<" Enter query Range ( l-r )  ";
                    cin>>l>>r;
                    ans = obj.query(n,l,r);
                    cout<<ans<<"\n";
                    break;
            default: break;
        }
    }
    return 0;
}