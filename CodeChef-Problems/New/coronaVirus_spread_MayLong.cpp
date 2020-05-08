//CoronaVirus Spread - Long May - CodeChef
#include<iostream>
#include<map>
#include<list>
#include<vector>
#define ll long long int
using namespace std;
class Graph {
public:
    map<ll, list< ll> > adjList;

    void addEdge(ll u,ll v,bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir) adjList[v].push_back(u);
    }
    void dfsHelper(map<ll,bool> &visited,ll start,int &noOfNodes)
    {
        visited[start] = true;
        for(auto neigh: adjList[start])
        {   
            if(!visited[neigh] && neigh != -1)
            {   noOfNodes++;
                dfsHelper(visited,neigh,noOfNodes);
            }
        }
        return;
    }
    void connectedCompNodes(ll &maxVal,ll &minVal )
    {
        map<ll,bool> visited;
        for(auto nodes:adjList)
        {
            if(!visited[nodes.first])
            {   int noOfNodes = 1;
                dfsHelper(visited,nodes.first,noOfNodes);
                if(maxVal<noOfNodes) maxVal = noOfNodes;
                if(minVal>noOfNodes) minVal = noOfNodes;
            }
        }
    }
};

int main()
{   ll n, T;
    cin >> T;
    while (T--)
    {   cin >> n;
        ll val;
        Graph g;
        ll arr[11];
        for(int i=0;i<11;i++) arr[i] = -1; 
        for (int i = 0; i < n; i++)
        {
            cin>>val;
            g.addEdge(val,-1,false);
            for(int j=val+1;(j<=val+2 && j<11);j++)
            {
                if(arr[j]!=-1) g.addEdge(val,j);
            }
            for(int j=val-1;(j>=val-2&&j>-1);j--)
                if(arr[j]!=-1) g.addEdge(val,j);
            arr[val] = val;
        }
        // for(auto i: g.adjList)
        // {
        //     cout<<i.first<<" -> ";
        //     for(auto v: i.second)
        //     {
        //         cout<<v<<" ";
        //     }
        //     cout<<endl;
        // }
        ll maxVal = INT8_MIN,minVal=INT8_MAX;
        g.connectedCompNodes(maxVal,minVal);
        if(maxVal == INT8_MIN) maxVal = 1;
        if(minVal == INT8_MAX) minVal= 1;
        cout<<minVal<<" "<<maxVal<<endl;
    }
    return 0;
}