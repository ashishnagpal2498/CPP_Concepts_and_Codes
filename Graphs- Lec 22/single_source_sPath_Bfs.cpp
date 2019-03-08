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
    void bfs(T s)
    {
        // visited - 
        // Queue
        queue<T> q1;
        map<T,bool> visited;

        q1.push(s);
        visited[s] = true;

        while(!q1.empty())
        {
            T node = q1.front();
            q1.pop();
            cout<<node<<"  ";

            for(auto vert:adjList[node])
            {
                if(!visited[vert])
                {
                    q1.push(vert);
                    visited[vert] = true;
                }
            }
        }
    }
    // Single source shortest path -
    int bfs_shortest_path(T s,T d)
    {
        // Queue - and Distance hash-map
        queue<T> q1;
        map<T,int> dist;
        map<T,T> parent;
        // Making all other values as INFINITY
        for(auto i:adjList)
        {
            dist[i.first] = INT_MAX;
        }
        q1.push(s);
        dist[s] = 0;

        while(!q1.empty())
        {
            T node = q1.front();
            q1.pop();
            cout<<node<<"  ";

            for(auto neigh:adjList[node])
            {
                if(dist[neigh]==INT_MAX)
                {
                    q1.push(neigh);
                    dist[neigh] = dist[node] +1;
                    parent[neigh] = node;
                }
            }
        }
        // Print the distance;
        for(auto i:adjList)
        {
            T node = i.first;
            cout<<"Distance of "<<node<<" From source node  "<<s<<" is  "<<dist[node]<<endl;
        }

        //Need to find the path
        cout<<endl<<"Path is   ";
        for(;d!=s;)
        {   
            cout<<d<<"  ";
            d = parent[d];
            // return destination node distance
        }
        cout<<s<<" ";

    return dist[d];
    }

};
int main()
{
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);
    g.print();
    cout<<endl;
    g.bfs(1);
    cout<<endl;
    int ans = g.bfs_shortest_path(1,3);
    cout<<endl<<"Distance is "<<ans;
    return 0;
}