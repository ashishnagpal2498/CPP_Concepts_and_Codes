//Cycle Detection BFS
#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph{
    map<T , list<T> > adjList;
public:
    void addEdge(T u,T v,bool bidir=false)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    bool CycleDetectionBFS(T src)
    {
        map<T,bool> visited;
        map<T,T> parent;
        queue<T> q1;
        q1.push(src);
        visited[src]= true;
        parent[src] = src;
        while(!q1.empty())
        {
            T node = q1.front();
            q1.pop();
            for(T neigh:adjList[node])
            {
                if(visited[neigh]==true&&parent[node]!=neigh)
                {
                    return true;
                }
                else if(!visited[neigh])
                {
                    //add to queue
                    visited[neigh] = true;
                    q1.push(neigh);
                }
            }
        }
        return false;
    }
};
 
int main(int argc, char const *argv[])
{
    Graph<string>  g;
    g.addEdge("English","Programming Logic");
    g.addEdge("Maths","Programming Logic");
    g.addEdge("Programming Logic","Html");
    g.addEdge("Programming Logic","Python");
    g.addEdge("Programming Logic","Java");
    g.addEdge("Programming Logic","Js");
    g.addEdge("English","Html");
    g.addEdge("Html","CSS");
    g.addEdge("CSS","Js");
    g.addEdge("Js","Web D");
    g.addEdge("Java","Web D");
    g.addEdge("Python","Web D");
    // g.dfs_Topological_Sort();
    g.topologicalSortBFS();
    return 0;
}