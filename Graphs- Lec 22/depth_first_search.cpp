//Depth - First search - 
#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T> > adjList;
public:
    Graph()
    {

    }
    void addEdge(T u, T v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void print()
    {

    }
    void dfsHelper(T node,map<T,bool> &visited)
    {   visited[node] = true;
        cout<<node<<" ";
        for(auto i:adjList[node])
        {
            if(!visited[i])
            {   //Instead of using , stack DS we use recursive stack for implementation
                // If the node isn't visited , go to that node
                dfsHelper(i,visited);
            }
        }
    }
    void dfs(T s)
    {
        map<T,bool> visited;
        // Using recursive Stack
        dfsHelper(s,visited);
    }
};
int main()
{
        Graph<int> g;
        g.addEdge(1,2);
        g.addEdge(1,4);
        g.addEdge(2,3);
        g.addEdge(3,4);
        g.dfs(1);
        cout<<endl;
        g.print();
        return 0;
}