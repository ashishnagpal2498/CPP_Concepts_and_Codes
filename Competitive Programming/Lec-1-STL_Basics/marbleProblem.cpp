#include<iostream>
#include<list>
#include<map>
#define ll long long int
using namespace std;
class Graph{
    public:
     map<ll, list<ll> > adjList;
     void addEdge(ll u, ll v,bool biDir=true)
     {
        adjList[u].push_back(v);
        if(biDir)
            adjList[v].push_back(u);
     }
     void dfsHelper(map<ll,bool> &visited,ll start)
     {
        visited[start] = true;
        for(auto neigh: adjList[start])
        {
            if(!visited[neigh])
            {
                dfsHelper(visited,neigh);
            }
        }
     }
     int connectedComponents(ll start)
     {
        map<ll,bool> visited;
        int connectedComp = 0;
        for(auto val: adjList)
        {
            if(!visited[val.first])
            {
                dfsHelper(visited,val.first);
                connectedComp++;
            }
        }
        return connectedComp;
     }   
};
int main()
{
    Graph g;
    ll n,k;
    cin>>n>>k; // No of marbles and no of edges
    // No of marbles 1 to N
    ll a,b;
    for(int i=0;i<k;i++)
    {
        cin>>a>>b;
        g.addEdge(a,b);
    }
    ll connectedComp = g.connectedComponents(1);
    cout<<"Maximum Marbles - "<<(n-connectedComp)<<endl;
    return 0;
}