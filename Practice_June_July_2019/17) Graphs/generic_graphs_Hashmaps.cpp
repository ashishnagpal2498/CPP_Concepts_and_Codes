//Graphs Using HashMaps -
#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
template<typename T>
class Graph{
    unordered_map< T, list<T> > adjList;
public:
    void addEdge(T u , T v, bool bidir= true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for(auto i:adjList)
        {
            //
            cout<<i.first<<"->";
            for(T vertix: i.second)
            {
                cout<<vertix<<",";
            }
            cout<<endl;
        }
    }
};
int main(int argc, char const *argv[])
{
    Graph<string> g;
    g.addEdge("Modi","Trump");
    g.addEdge("Modi","Yogi");
    g.addEdge("Yogi","Lalu");
    g.addEdge("Trump","Korea");
    g.printAdjList();
    return 0;
}