//Beautiful Vertices
#include<iostream>
#include<list>
#include<map>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T> > adjList;
public:
    Graph(int n,int e)
    {   map<T,bool>visited;
        int a,b;
        for(int i=0;i<e;i++)
        {   cin>>a>>b;
            if(!visited[a])
            {
                adjList[a].push_back(INT_MAX);
                visited[a] = true;
            }
            if(!visited[b])
            {
                adjList[b].push_back(INT_MAX);
                visited[b] = true;
            }
            adjList[a].push_front(b);
        }
    }
    void printGraph()
    {
        for(auto i:adjList)
        {
            cout<<i.first<<"-> ";
            for(auto neigh:i.second)
            {
                cout<<neigh<<" , ";
            }
            cout<<endl;
        }
    }
    void addEdge(T u, T v , bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void dfsHelper(T src, map<T,bool> &visited,map<T,T> &parent,map<T,int> &parentDist)
    {
        visited[src] = true;
        for(T neighbour: adjList[src])
        {   
            if(neighbour==INT_MAX) continue;

            if(!visited[neighbour])
            {
                parent[neighbour] =  src;
                parentDist[src]++;
                dfsHelper(neighbour,visited,parent,parentDist);
            }
        }
        return;
    }
    //
    void dfs()
    {
        map<T,bool> visited;
        map<T,T> parent;
        map<T,int> parentDist;
        int count=0;
        for(auto i:adjList)
        {
            parentDist[i.first] = 0; 
        }
        for(auto i:adjList)
        {
            if(!visited[i.first])
            {   parent[i.first] = i.first;
                dfsHelper(i.first,visited,parent,parentDist);
            }
        } 
        for(auto i:adjList)
        {
            if(parentDist[i.first]>parentDist[parent[i.first]])
            {
                count++;
            }
        }
        cout<<count<<endl;
    }

};
int main(int argc, char const *argv[])
{
    /* code */
    int n,e;
    cin>>n>>e;
    Graph<int> g(n,e);
    // g.printGraph();
    g.dfs();
    return 0;
}