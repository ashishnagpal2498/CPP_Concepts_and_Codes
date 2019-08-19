//cycle Detection in - Directed Graph -
#include<iostream>
#include<map>
#include<list>
using namespace std;
template<typename T>
class Graph{
    map< T, list<T> > adjList;
public:
    void addEdge(T u,T v,bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void printGraph()
    {
        for(auto i:adjList)
        {
            //That will be a key value pair in which - i.first - key
            //i.second - linked List
            cout<<i.first<<" -> ";
            for(T node:i.second)
            {
                cout<<node<<" ";
            }
            cout<<endl;
        }
    }
    bool dfsHelper(T src,map<T,bool> &visited, map<T,bool> &inStack)
    {
        //Mark the node as - visited-
        visited[src] = true;
        inStack[src] = true;

        for(T neighbour:adjList[src])
        {
            if(visited[neighbour]&&inStack[neighbour])
            {
                return true;
            }
            else if(!visited[neighbour])
            {
                return dfsHelper(neighbour,visited,inStack);
            }
        }
        inStack[src] = false;
        return false;
    }
    bool cycleDetectionDFS_Directed()
    {
        map<T,bool> visited;
        map<T,bool> inStack;
        bool ans = false;
        for(auto i:adjList)
        {
            if(!visited[i.first])
            {
              ans = dfsHelper(i.first,visited,inStack);
            }
            if(ans)
            {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Graph<int> g;
    g.addEdge(1,2,false);
    g.addEdge(2,3,false);
    g.addEdge(3,4,false);
    g.addEdge(4,7,false);
    g.addEdge(1,5,false);
    g.addEdge(5,6,false);
    g.addEdge(6,7,false);
    g.addEdge(6,1,false);
    // g.addEdge(1,2,false);
    if(g.cycleDetectionDFS_Directed())
    {
        cout<<"CYCLE EXIST"<<endl;
    }
    else
    {
        cout<<"NO CYCLE"<<endl;
    }
    return 0;
}