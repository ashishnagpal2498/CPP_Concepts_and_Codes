//Snake and ladder Graphs - HackerBlocks
#include<iostream>
#include<map>
#include<queue>
#include <list>
using namespace std;
class Graph{
    map<int,list<int> > adjList;
    map<int,int> dist;
public:
    Graph(int n)
    {
        for(int i=1;i<=n;i++)
        {
            dist[i] = INT_MAX;
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
    void printGraph()
    {
        //Printing graph having each node of addList
        for(auto i:adjList)
        {
            cout<<i.first<<" -> ";
            for(auto neigh:i.second)
            {
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
    int bfs(int src,int n)
    {
        map<int,bool> visited;
        queue<int> q1;
        //distance - map ;
        dist[src] = 0;
        visited[src] = true;
        q1.push(src);
        while(!q1.empty())
        {
            int node = q1.front();
            q1.pop();
            for(auto neigh:adjList[node])
            {
                if(!visited[neigh]||dist[neigh]==INT_MAX)
                {
                    visited[neigh] = true;
                    dist[neigh] = dist[node] +1;
                    q1.push(neigh);
                }
            }
        }
        return dist[n];
    }
    
};

int main()
{
    //graph construct - main
    int testcase;
    cin>>testcase;
    while(testcase--)
    {   int n;
        cin>>n;
        Graph g_snake_ladder(n);
        //Increment or decrement - according to snake and ladder-
    
         int snake,ladder;
        cin>>ladder>>snake;
        int board[51] ={0};
        int index1,index2;
        for(int i=0;i<snake+ladder;i++)
        {
            cin>>index1>>index2;
            //Increamet or decrement-
            int val = index1 - index2 ;
            if(val<0)
            {
            //increment - 
            board[index1] = -1* (val);
            }
            else
            {
                board[index1] = -1* (val);
            }
        }
    // for(int i=0;i<=n;i++)
    // {
    //     cout<<board[i]<<"  ";
    // }
        for(int i=1;i<=n;i++)
        {
            //Develope Adj list of each node -
            for(int dice=1;dice<=6;dice++)
            {
            //directional edges-
                g_snake_ladder.addEdge(i,i+dice+board[i+dice],false);
            }
        }
    //cout<<endl;
    //g_snake_ladder.printGraph();
        cout<<g_snake_ladder.bfs(1,n)<<endl;
    }
    return 0;
}