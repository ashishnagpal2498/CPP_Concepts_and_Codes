//DFS - 
#include<iostream>
#include<map>
#include<list>
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
//Topological Sort ------
    void dfsHelper(T node,map<T,bool> &visited,list<T> &ordering)
    {
        //Mark the node as visited-
        visited[node] = true;
        // cout<<node<<" ";
        //find the neighbour -
        for(T neighbour:adjList[node])
        {
            if(!visited[neighbour])
            {
                dfsHelper(neighbour,visited,ordering);
            }
        }
        //Adding in the ordering list - at front-
        ordering.push_front(node);
    }
    void dfs_Topological_Sort()
    {
        map<T,bool > visited;
        list<T > ordering;
        for(auto i:adjList)
        {
            T node = i.first;
            if(!visited[node])
            {
                dfsHelper(node,visited,ordering);
            }
        }
        //Print the list -
        for(T i:ordering)
        {
            cout<<i<<"-> ";
        }
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
    g.dfs_Topological_Sort();
    return 0;
}