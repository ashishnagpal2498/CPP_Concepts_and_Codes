#include<iostream>
#include<queue>
#include<list>
#include<map>
using namespace std;
int A,B;
class Graph{
    map<int,list<int > > adjList;
public:
    Graph(int n)
    {
        for(int i=1;i<=n;i++)
        {
            adjList[i].push_back(INT_MAX);
        }
    }
    void addEdge(int u,int v,bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void dfsHelper(int node, map<int,bool> &visited,int &ans)
    {   
        visited[node] = true;
        for(auto neigh:adjList[node])
        {   
            if(!visited[neigh]&&neigh!=INT_MAX)
            {
                if(A>=B)
                {
                    //create a road between then the node and neighbour
                    ans+=B;
                }
                else
                {
                    ans+=A;
                }
                dfsHelper(neigh,visited,ans);
            }
        }
    }
    int dfs(int src)
    {
        map<int,bool> visited;
        int ans = 0;
        for(auto i:adjList)
        {   int node = i.first;
            if(!visited[node])
            {   ans+=A;
                dfsHelper(node,visited,ans);
            }
        }
        return ans;
    }
};
int main()
{   int T;
    cin>>T;
    while(T--)
    {   int N,M;
        cin>>N>>M>>A>>B;
        Graph g(N);
        int u,v;
        for(int i=0;i<M;i++)
        {
            cin>>u>>v;
            g.addEdge(u,v,false);
        }
        cout<<g.dfs(1)<<endl;
    }
    return 0;
}