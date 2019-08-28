//Beautiful Vertices 2 - using array list
#include <iostream>
#include<list>
#include<map>
using namespace std;
template<typename T>
class Graph{
    int V;
    list<T>*adjList;
public:
    Graph(int n,int edge)
    {   V=n;
        adjList = new list<T>[n+1];
        int a,b;

        //Indexing of array start from 0 so -
        // 0th index -> 1
        for(int i=0;i<edge;i++)
        {
            cin>>a>>b;
            adjList[a].push_back(b);
        }
    }
     void dfsHelper(T src, map<T,bool> &visited,map<T,T> &parent,map<T,int>&parentDist,int &count)
    {
        visited[src] = true;
        for(T neighbour: adjList[src])
        {
            if(!visited[neighbour])
            {
                parent[neighbour] =  src;
                // if(parentDist[src]< parentDist[neighbour])
                // {
                //     count++;
                // }
                parentDist[src]++;
                dfsHelper(neighbour,visited,parent,parentDist,count);
            }
        }
    }
    //
    void dfs()
    {
        map<T,bool> visited;
        map<T,T> parent;
        map<T,int> parentDist;
        int count=0;
        for(int i=1;i<=V;i++)
        {
            parentDist[i] = 0; 
        }
        // int count=0;
        for(int i=1;i<=V;i++)
        {
            if(!visited[i])
            {   parent[i] = i;
                parentDist[i] = 0;
                dfsHelper(i,visited,parent,parentDist,count);
            }
        } 
        // cout<<count<<endl;
        for(int i=1;i<=V;i++)
        {
            if(parentDist[i]>parentDist[parent[i]])
            {
                count++;
            }
        }
        cout<<count<<endl;

    }
};
int main(int argc, char const *argv[])
{
    int n,e;
    cin>>n>>e;
    Graph<int> g(n,e);
    g.dfs();
    return 0;
}