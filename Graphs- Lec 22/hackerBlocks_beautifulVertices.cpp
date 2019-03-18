//beautiful vertices - HackerBlocks
#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;
class Graph{
    map<int,list<int> > adjList;
    map<int,int> parent; //Stores the parent element in value
    map<int,int> children; //stores the number of children
public:
    Graph(int n)
    {
        for(int i=1;i<=n;i++)
        {
            parent[i] = -1;
            children[i] = 0;
        }
    }
    void addEdge(int u,int v)
    {   //directed graph
        adjList[u].push_back(v);
        parent[v] = u;
        children[u]++;
    }
    int master_parent()
    {
        for(auto i:adjList)
        {
            if(parent[i.first]==-1)
            {
                return i.first;
            }
        }
    }
    int bfs(int src,map<int,bool> &visited)
    { 
        //parent map and children map
        //queue<int> q1;
        // map<int,bool> visited;
        visited[src] = true;
       // q1.push(src);
        // while(!q1.empty())
        // {
        //     int node = q1.front();
        //     q1.pop();
        //     for(auto neighbour:adjList[node])
        //     {
        //         if(!visited[neighbour])
        //         {
        //             children[node]++;
        //             visited[neighbour] = true;
        //             parent[neighbour] = node;
        //             q1.push(neighbour);
        //         }
        //     }
        // } //end of while loop
        //Calculate all those vertices whose parent have less children than child
        int count=0;
        for(auto i:adjList)
        {   int node = i.first;
            if(parent[node]!=-1)
            {   visited[node]= true;
                int pnode = parent[node];
                if(children[pnode]<children[node])
                {
                    count++;
                }
            }
        }
    return count;        
    }
    void dfs(int src)
    {
        map<int,bool> visited;
       int ans = bfs(src,visited);
        for(auto i:adjList)
        {
            if(!visited[i.first])
            {
              ans+=bfs(i.first,visited);
            }
        }
        cout<<ans;
    }
    
};


int main()
{ int n;
    cin>>n;
    Graph g(n);
    int m; cin>>m;
    int v1,v2;
    for(int i=0;i<m;i++)
    {
        cin>>v1>>v2;
        g.addEdge(v1,v2);
    }
    int srcnode = g.master_parent();
    g.dfs(srcnode);
    return 0;
}