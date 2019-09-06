#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph{
    list<int> *adjList;
    int V;
public:
    Graph(int v)
    {
        V=v;
        adjList = new list<int>[V];
    }
    void addEdge(int u,int v)
    {
        adjList[u].push_back(v);
    }
    void Dfs(int u,vector<bool>&visited)
    {
        visited[u] = true;
        for(auto i:adjList[u])
        {
            if(!visited[i])
            {
                Dfs(i,visited);
            }
        }
    }
    int motherVertix()
    {
        vector<bool> visited(V,false);
        int v=0;

        //Apply the Dfs and get the 
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            { 
                Dfs(i,visited);
                v = i;
            }
        }
        //reset the visited
        fill(visited.begin(),visited.end(),false);
        Dfs(v,visited);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                return -1;
            }
        }
        return v;
    }
};
int main(int argc, char const *argv[])
{
    Graph g(7);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 
    cout << "A mother vertex is " << g.motherVertix();
    return 0;
}