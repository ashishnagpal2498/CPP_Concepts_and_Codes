//K-Core Graph -
#include <iostream>
#include<list>
#include<vector>
using namespace std;
class Graph{
    list<int>*adjList;
    int V;
public:
    void addEdge(int u,int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    Graph(int v)
    {
        V=v;
        adjList = new list<int>[V];
    }
    bool DFSUtil(int v,vector<int>&vDegree,int k,vector<bool>&visited)
    {
        visited[v] = true;
        for(auto i=adjList[v].begin();i!=adjList[v].end();i++)
        {
            if(vDegree[v]<k)
            {
                vDegree[*i]--;
            }
            if(!visited[*i])
            {
                if(DFSUtil(*i,vDegree,k,visited))
                {
                    vDegree[v]--;
                }
            }
        }
        return (vDegree[v]<k);
    }
    void k_Cores(int k)
    {
        vector<bool> visited(V,false);
        vector<int> vDegree(V);
        int startIndex;
        int minVal = INT_MAX;
        for(int i=0;i<V;i++)
        {
            vDegree[i] = adjList[i].size();
            if(vDegree[i]<minVal)
            {
                minVal=vDegree[i];
                startIndex = i;
            }
        }
        DFSUtil(startIndex,vDegree,k,visited);
        //Now DFS for the whole Graph
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                DFSUtil(i,vDegree,k,visited);
            }
        }
        cout<<"DFS COMPLETE"<<endl;
        //Printing graph
        for(int i=0;i<V;i++)
        {
            if(vDegree[i]>=k)
            {
                //
                cout<<i<<" -> ";
                for(auto neigh:adjList[i])
                {   if(vDegree[neigh]>=k)
                    cout<<neigh<<" ";
                }
                cout<<endl;
            }
        }
    }
};
int main(int argc, char const *argv[])
{
     int k = 3; 
    Graph g1(9); 
    g1.addEdge(0, 1); 
    g1.addEdge(0, 2); 
    g1.addEdge(1, 2); 
    g1.addEdge(1, 5); 
    g1.addEdge(2, 3); 
    g1.addEdge(2, 4); 
    g1.addEdge(2, 5); 
    g1.addEdge(2, 6); 
    g1.addEdge(3, 4); 
    g1.addEdge(3, 6); 
    g1.addEdge(3, 7); 
    g1.addEdge(4, 6); 
    g1.addEdge(4, 7); 
    g1.addEdge(5, 6); 
    g1.addEdge(5, 8); 
    g1.addEdge(6, 7); 
    g1.addEdge(6, 8); 
    g1.k_Cores(k); 
    return 0;
}