//Graphs Using Hash-Maps
#include<iostream>
#include<map>
#include<queue>
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

    // BFS using adjancy list and Hash-Map
    void bfs(T src)
    {
        map<T,bool> visited;
        queue<T> q1;

        q1.push(src);
        visited[src] = true;

        // Now check for all the neighbours of src node;
        while(!q1.empty())
        {
            T val = q1.front();
            q1.pop();
            cout<<val<<"  ";

            // Neighbours
            for(auto neigh:myAdjList[val])
            {
                if(!visited.count(neigh))
                {
                    visited[neigh] = true;
                    q1.push(neigh);
                }
            }
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
    cout<<endl;
    g.bfs("Modi");
    return 0;
}