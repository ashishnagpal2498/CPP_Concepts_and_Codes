//Cycle-Detection using BFS
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
    void addEdge(T u,T v , bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void printG()
    {
        //Print the graph with iterating over all the key , 
        for(auto i:adjList)
        {
            cout<<i.first<<" -> ";
            for(auto vertex:i.second)
            {

                cout<<vertex<<" ";
            }
            cout<<endl;
        }
    }
    // BFS- 
    void bfs(T s)
    {
        queue<T> q1;
        map<T,bool> visited;

        q1.push(s);
        visited[s] = true;
        while(!q1.empty())
        {
            //Iterate-
            T node = q1.front();
            cout<<node<<"  ";
            q1.pop();
            for(auto neighbour:adjList[node])
            {
                if(!visited[neighbour])
                {
                    q1.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    bool isCyclic(T src)
    {
        map<T,bool> visited;
        map<T,T> parent;
        queue<T> q1;

        q1.push(src);
        visited[src] = true;
        while(!q1.empty())
        {
            T node = q1.front();
            q1.pop();
            for(auto neighbour:adjList[node])
            {
                if(!visited[neighbour])
                {
                    q1.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = node;
                }
                else if(visited[neighbour]&&parent[node]!=neighbour)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(1,4);
    g.bfs(1);
    cout<<endl;
    cout<<g.isCyclic(1);
    return 0;
}