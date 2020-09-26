#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t,n,u,v;
class Graph{
public:
    map<ll,list<ll> > adjList;
    void addEdge(ll u,ll v){
        adjList[u].push_back(v);
    }
void dfsHelper(ll start,map<ll,bool>&visited,ll &noOfNodesTraversed){
    noOfNodesTraversed++;
    visited[start] = true;
    for(auto neigh: adjList[start]){
        if(!visited[neigh]){
            dfsHelper(neigh,visited,noOfNodesTraversed);
        }
    }
}
ll dfs(){
    ll noOfNodesTraversed = 0, minVal = INT_MAX;
    for(ll i=1;i<=n;i++){
    map<ll,bool> visited;
    noOfNodesTraversed = 0;
    // cout<<i<<" -> ";
        dfsHelper(i,visited,noOfNodesTraversed);
        // cout<<"No of nodes traversed "<<noOfNodesTraversed<<" -> "<<minVal<<endl;
        minVal = min(minVal,n- noOfNodesTraversed);
        if(minVal == 0) break;
    }
    return minVal;
}
};
int main()
{
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        ll count =0;
        // if(n == 2) {cout<<0<<endl;}
        // else{
        Graph g;
        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            // if(v == 1) count++;
            g.addEdge(u,v);
        }
        count = g.dfs();
        cout<<count<<endl;
        // }

    }
    return 0;
}