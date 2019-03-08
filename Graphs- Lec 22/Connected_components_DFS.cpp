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
        dfsHelper(s,visited);
        // Traverse the adj list
        int component = 1;
        cout<<endl;
        for(auto i:adjList)
        {
            T city = i.first;
            if(!visited[city])
            {    //This helps in visiting nodes in graph which are not connected
                dfsHelper(city,visited);
                component++;
            }
        }
        cout<<endl<<"The connected components are "<<component;
    }
};
int main()
{
        Graph<string> g;
        g.addEdge("Amritsar","Jaipur");
        g.addEdge("Amritsar","Delhi");
        g.addEdge("Delhi","Jaipur");
        g.addEdge("Mumbai","Jaipur");
        g.addEdge("Mumbai","Bhopal");
        g.addEdge("Mumbai","Bhopal");
        g.addEdge("Delhi","Bhopal");
        g.addEdge("Mumbai","Bangalore");
        g.addEdge("Delhi","Agra");
        g.addEdge("Andaman","Nicobar");

        g.dfs("Amritsar");
        cout<<endl;
        // g.print();
        return 0;
}