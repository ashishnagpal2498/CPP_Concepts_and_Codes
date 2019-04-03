#include<iostream>
#include<queue>
#include<list>
#include<map>
using namespace std;
//Using AdjList - of array type -

int A,B;
class Graph{
    list<int>* adjList;
public:
    Graph(int n)
    {   adjList = new list<int>[n+1];
        // for(int i=1;i<=n;i++)
        // {
        //     adjList[i].push_back(INT_MAX);
        // }
    }
    // void printGraph()
    // {
    //     for(auto i:adjList)
    //     {
    //         int Node = i.first;
    //         cout<<Node<<" ->  ";
    //         for(int neigh:adjList[Node])
    //         {
    //             cout<<neigh<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
    void addEdge(int u,int v,bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void dfsHelper(int node, map<int,bool> &visited,long long int &ans)
    {   
        visited[node] = true;
        for(auto neigh:adjList[node])
        {   
            if(!visited[neigh])
            {
                if(A>=B)
                {
                    //create a road between then the node and neighbour
                    ans+=B;
                }
                else
                {   //Creating a temple - 
                    ans+=A;
                }
                dfsHelper(neigh,visited,ans);
            }
        }
    }
   long long int dfs(int n)
    {
        map<int,bool> visited;
       long long int ans = 0;
        for(int i = 1;i<=n;i++)
        {   //If the node isn't visited then -
            if(!visited[i])
            {   //Every Component will have atleast one temple in
                //
                ans+=A;
                dfsHelper(i,visited,ans);
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
        cout<<g.dfs(N)<<endl;
        //g.printGraph();
    }
    return 0;
}