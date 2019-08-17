//DFS - 
#include<iostream>
#include<map>
#include<list>
using namespace std;
template<typename T>
class Graph{
    map<T , list<T> > adjList;
public:
    void addEdge(T u,T v,bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void dfsHelper(T node,map<T,bool> &visited)
    {
        //Mark the node as visited-
        visited[node] = true;
        cout<<node<<" ";
        //find the neighbour -
        for(T neighbour:adjList[node])
        {
            if(!visited[neighbour])
            {
                dfsHelper(neighbour,visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T,bool > visited;
        dfsHelper(src,visited);
    }
};
//Cities and Connected Components -
//Dfs call - visiting all the nodes - loop and checking if the city is not visited
//Then - 
int main(int argc, char const *argv[])
{
    Graph<int>  g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.dfs(0);
    return 0;
}