//cycle detection in a Directed graph
// If the cycle is found then ancesstor - 
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

    bool dfs_helper(T node,map<T,bool> &visited,map<T,bool> &inStack)
    {
        visited[node]= true;
        inStack [node] = true;

        // Neighbours;
        for(auto neigh:adjList[node])
        {
            if((!visited[neigh]&&dfs_helper(neigh,visited,inStack))||inStack[neigh])
            {
                return true;
            }
        }
        // Backtracking
        inStack[node] = false;
        return false;
    }


    bool isCyclic_DFS(T src)
    {
        map<T,bool> visited;
        map<T,bool> inStack;

        for(auto i:adjList)
        {
            if(!visited[i.first])
            {
                bool cyclic = dfs_helper(i.first,visited,inStack);
                if(cyclic) return true;
            }
        }
        return false;
    }
   
};

int main()
{
    Graph<int> g;
    g.addEdge(0,2,false);
    g.addEdge(0,1,false);
    g.addEdge(2,4,false);
    g.addEdge(1,5,false);
    g.addEdge(2,3,false);
    g.addEdge(4,5,false);
    g.addEdge(3,0,false);
    cout<<g.isCyclic_DFS(0);
    return 0;
}