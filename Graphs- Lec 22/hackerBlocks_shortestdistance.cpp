//HackerBlocks - Graph Shortest distance-
#include<map>
#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph{
    map<int,list<int> > adjList;
    map<int,int> dist;
public:
    Graph(int n)
    {   
        for(int i=1;i<=n;i++)
        {
            dist[i] = 0;
        }
    }
    void addEdge(int u,int v,bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void bfs(int src)
    {
        map<int,bool> visited;
        queue<int> q1;
        q1.push(src);
        visited[src] = true;
        // dist[src] = 0;
        while(!q1.empty())
        {
            int node = q1.front();
            q1.pop();
            for(auto neighbour:adjList[node])
            {
                if(!visited[neighbour])
                {
                    dist[neighbour] = dist[node] + 6;
                    visited[neighbour] = true;
                    q1.push(neighbour);
                }
            }
        }
        for(auto i:dist)
        {
            int node = i.first;
            if(dist[node]==0&&node!=src)
            {
                cout<<"-1 ";
            }
            else if(node==src)
            {
                
            }
            else
            {
                cout<<dist[node]<<" ";
            }
        }
    }
};
int main()
{
    int testcase;
    cin>>testcase;
    int noofnode,edges,v1,v2,src;
    while(testcase--)
    {   
        cin>>noofnode>>edges;
        Graph g(noofnode);
        for(int i=0;i<edges;i++)
        {
            cin>>v1>>v2;
            g.addEdge(v1,v2);
        }
        cin>>src;
        g.bfs(src);
        cout<<endl;
    }
    return 0;
}