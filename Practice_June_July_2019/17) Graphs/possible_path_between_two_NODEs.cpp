//Count possible paths between two nodes
#include<iostream>
#include<list>
#include<map>
#include<vector>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T> > adjList;
public:
    Graph()
    {
        
        //adjList = new list<int>[V];
    }
    void addEdge(T u,T v, bool bidir=false)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void print()
    {
        for(auto i:adjList)
        {
            //1st will be value , second will be - list
            cout<<i.first<<"->";
            for(auto neigh:i.second)
            {
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
    int DfsPaths(T start,T destination,map<T,bool>&visited,vector<T>path)
    {
        if(start==destination)
        {   //cout<<" ";
            for(int i=0;i<path.size();i++)
            {
                cout<<path[i]<<" ";
            }
            cout<<endl;
            // visited[destination]= false;
            return 1;
        
        }
        int ans=0;
        visited[start] = true;
        for(auto neigh:adjList[start])
        {
            if(!visited[neigh])
            {   path.push_back(neigh);
                ans += DfsPaths(neigh,destination,visited,path);
                path.pop_back();
            }
        }
        visited[start] = false;
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Graph<char> g1;
    g1.addEdge('A','B');
    g1.addEdge('A','E');
    g1.addEdge('A','C');
    g1.addEdge('B','D');
    g1.addEdge('B','E');
    g1.addEdge('C','E');
    g1.addEdge('D','C');
    // g1.addEdge('','B');
    // g1.addEdge('A','B');
    map<char,bool> visited;
    vector<char> path;
    path.push_back('A');
    cout<<g1.DfsPaths('A','E',visited,path);
    return 0;
}