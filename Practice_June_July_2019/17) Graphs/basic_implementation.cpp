//Graph - Implementation -
#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
//Adjancey List - 
// template<typename T>
class Graph{
public:
   int V;
   list<int> *l;
   Graph(int v)
   {
        V= v;
        l = new list<int>[V];
   }
   void addEdge(int u,int v,bool bidir=true)
   {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
   }
   void printAdjList()
   {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->";
            for(int vertex:l[i])
            {
                cout<<vertex<<",";
            }
            cout<<endl;
        }
   }
};
int main(int argc, char const *argv[])
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.printAdjList();
    return 0;
}
