//DFS - 
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
//Topological Sort ------
    void topologicalSortBFS()
    {
        queue<T> q1;
        map<T,bool> visited;
        map<T,int> indegree;

        //INITIALIZE THE INDEGREE WITH 0
        for(auto i:adjList)
        {
            indegree[i.first] = 0;
        }

        //Calculate the INDEGREE
        for(auto i:adjList)
        {
            T node = i.first;
            for(T neighbour:adjList[node])
            {
                indegree[neighbour]++;
            }
        }

        //Intialize the Queue with all the 0 indegrees of the node
        for(auto i:adjList)
        {
            if(indegree[i.first]==0)
            {
                q1.push(i.first);
            }
        }

        //Algo -
        while(!q1.empty())
        {
            T f = q1.front();
            q1.pop();
            cout<<f<<"->";
            for(T neigh:adjList[f])
            {
                indegree[neigh]--;
                if(indegree[neigh]==0)
                {
                    q1.push(neigh);
                }
            }
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
    // g.dfs_Topological_Sort();
    g.topologicalSortBFS();
    return 0;
}