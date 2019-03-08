//Single source shortest path BFS
#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T> > adjList;
public:
    Graph(){

    }
    //Hash-Map are prefered - Easy to implement 
    void addEdge(T u,T v,bool bidir = true )
    {
        // How to insert in hashmap-
        //make pair and insert 
        // m[key] = val;
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void print()
    {
        // Need to print the graph - Iterate over hashmap
        for(auto i:adjList)
        {
            cout<<i.first<<" -> ";
            for(auto vertice:i.second)
            {
                cout<<vertice<<" ";
            }
            cout<<endl;
        }
    }
    // Breadth First Search 
    //Queue - 

};
int main()
{
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);
    g.print();
    return 0;
}