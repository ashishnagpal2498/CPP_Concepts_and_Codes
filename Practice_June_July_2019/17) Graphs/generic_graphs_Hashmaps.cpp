//Graphs Using HashMaps -
#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
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
    void bfs(T u)
    {
        queue<T> q1;
        q1.push(u);
        unordered_map<T,bool>visited;
        visited[u] = true;
        while(!q1.empty())
        {
            T node = q1.front();
            q1.pop();
            cout<<node<<"->";
            //Loop - for neighbours
            for(T neigh:adjList[node])
            {
                if(!visited[neigh])
                {   visited[neigh] = true;
                    q1.push(neigh);
                }
            }
        }
    }
    void singleS_Shortes_Path(T u)
    {
        unordered_map<T,T> parent;
        queue<T> q1;
        unordered_map<T,int> dist;
        
        for(auto i:adjList)
        {
            T node = i.first;
            dist[node] = INT_MAX;
        }
        q1.push(u);
        dist[u] = 0;
        parent[u] = u;

        //Loop to iterate Nodes - BFS
        while(!q1.empty())
        {
            T n = q1.front();
            q1.pop();
            for(T neighbour:adjList[n])
            {
                if(dist[neighbour]==INT_MAX)
                {
                    //not visited
                    parent[neighbour] = n;
                    dist[neighbour] = dist[n] +1;
                    q1.push(neighbour);
                }
            }
        }
        //PRINT ALL THE DISTANCES FROM  u 
        for(auto i:adjList)
        {
            cout<<i.first<<"-> ";
            cout<<dist[i.first]<<endl;
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
    cout<<endl<<"BFS  --> ";
    g.bfs("Modi");
    cout<<endl<<"SSSP  -->  ASSUMING UNWEIGHTED GRAPH ";
    g.singleS_Shortes_Path("Modi");
    return 0;
}