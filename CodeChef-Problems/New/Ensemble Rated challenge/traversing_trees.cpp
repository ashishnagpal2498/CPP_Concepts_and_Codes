// Traversing Trees 
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=1;i<=n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,q;
ll arr[200005];
void recursiveTree(int index,vector<int> &vect,int* tree,int n,int i,ll &v){
    if(index >= (4*n+1)) return;

    if(i>0 && i%2 == 0){
        // cout<<"Index -> "<<index<<" -> val "<<tree[index]<<endl;
        v+= tree[index];
        tree[index] = 0;
        vect.push_back(index);
    }
    if(tree[2*index] != -1 ) recursiveTree(2*index,vect,tree,n,i+1,v);
    if(tree[2*index+1] != -1 ) recursiveTree(2*index+1,vect,tree,n,i+1,v);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        int* tree;
        ll a,b;
        map<ll,ll> treeIndexToArr;
        map<ll,ll> arrayToTreeIndex;
        cin>>n>>q;
        tree = new int[4*n+1];
        for(int i=0;i<(4*n+1);i++){
            tree[i] = -1;
        }    
        ArrIn(n) cin>>arr[i];
        // vector<pair<int,int> > edges;
        // ArrIn(n-1){
            
        //     edges.push_back(make_pair(a,b));
        // }
        // sort(edges.begin(),edges.end());
        for(int i=0;i<n-1;i++){
            // cin>>a>>b;
            cin>>a>>b;
            // a = edges[i].first;
            // b = edges[i].second;
            // parent - a
            if(i==0)
            {   tree[a] = arr[a];
                treeIndexToArr[a] = a;
                arrayToTreeIndex[a] = a;
            }
            int index = arrayToTreeIndex[a];
            if(tree[2*index] == -1){
                
                tree[2*index] = arr[b];
                arrayToTreeIndex[b] = 2*index;
                treeIndexToArr[2*index] = b;
            }
            else {
                treeIndexToArr[2*index+1] = b;
                arrayToTreeIndex[b] = 2*index+1;
                tree[2*index+1] = arr[b];
            }
        }
        // OUTPUT TREE
        // cout<<"Tree \n";
        // for(int i=0;i<(4*n+1);i++) {cout<<tree[i]<<" ";}
        //     cout<<endl;

        ll v;
        while(q--){
            cin>>v;
            int index = 0;

            // for(index;index<(4*n+1);index++){
            // // this need to be corrected
            // if(tree[index] == arr[v]) break;
            // }
            index = arrayToTreeIndex[v];
            //cout<<index<<" index ----"<<endl;
        // Root of tree found ->
            vector<int> vect;
            ll val = tree[index];
            recursiveTree(index,vect,tree,n,0,val);
            for(auto value: vect){
                arr[treeIndexToArr[value]] =0; 
            }
           // OUTPUT VALUES 

           // cout<<"Q -> "<<q<<" -> val "<<val<<" Tree index "<<index<<" Array Index -> "<<arr[treeIndexToArr[index]]<<endl;
            arr[treeIndexToArr[index]] = val;
        }
        ArrIn(n){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}    