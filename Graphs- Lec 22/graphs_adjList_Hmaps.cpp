//Graphs Using Hash-Maps
#include<iostream>
#include<map>
#include<list>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T> > myAdjList;

public:
    Graph()
    {

    }
    void addEdge(T u,T v , bool bidir=true)
    {
        myAdjList[u].push_back(v);
        if(bidir)
        {
            myAdjList[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for(auto i:myAdjList)
        {
            // i is basically iterating over index of buckets
            cout<<i.first<<" -> ";
            for(auto vertix:i.second)
            {
                cout<<vertix<<" , ";
            }
            cout<<endl;
        }
    }

};
int main()
{
    Graph<string> g;
    g.addEdge("Putin","Trump",false);
       g.addEdge("Putin","Modi",false);
    g.addEdge("Putin","Pope",false);
  g.addEdge("Modi","Trump");
    g.addEdge("Prabhu","Modi",false);
  g.addEdge("Yogi","Prabhu",false);
  g.addEdge("Yogi","Modi");

    g.printAdjList();

    return 0;
}