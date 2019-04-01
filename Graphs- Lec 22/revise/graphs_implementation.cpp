//Graphs Revision - 
#include<iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;
//Graphs can be implemented using adjancy matrix edge list and adjancey list
//1) BFS - breadth first search - queue - visited map - 
// If the node is visited before - leave varna visted mark - push into queue
int dp[10000]={0};
int fact(int n)
{
    if(n==0||n==1) return 1;
    if(dp[n]!=0) return dp[n];
    dp[n] = n* fact(n-1);
    return dp[n];
}

int nCr(int n,int r)
{
    return fact(n)/(fact(r)*fact(n-r));
}

template<typename T>
class Graph{
    //we take a list of nodes -
    //either take a Adjancey list map<
    //
    map<T,list<T> > adjList;
public:
    Graph(int n)
    {
        for(int i=0;i<n;i++)
        {
            adjList[i].push_back(INT_MAX);
        }
    }
    Graph()
    {

    }
    void addEdge(T u, T v,bool bidir = true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    // void Bfs(T src)
    // {
    //     queue<T> q1;
    //     map<T,bool> visited;

    //     q1.push(src);
    //     visited[src] = true;
    //     while(!q1.empty())
    //     {
    //         T node = q1.front();
    //         q1.pop();
    //         cout<<node<<" ";
    //         for(auto neighbour: adjList[node] )
    //         {
    //             if(!visited[neighbour])
    //             {
    //                 q1.push(neighbour);
    //                 visited[neighbour] = true;
    //             }
    //         }
    //     }
    // }
    //Single source Shortest path
    // int single_source_Spath(T src,T des)
    // {
    //     map<T,int> dist;
    //     map<T,T> parent;
    //     queue<T> q1;
    //     for(auto node_pair:adjList)
    //     {   //Default value set to int MAX
    //         dist[node_pair.first] = INT_MAX;
    //     }
    //     dist[src] = 0;
    //     q1.push(src);
    //     while(!q1.empty())
    //     {   T node = q1.front();
    //         q1.pop();
    //         for(auto neigh: adjList[node])
    //         {
    //             if(dist[neigh]==INT_MAX)
    //             {
    //                 dist[neigh] = dist[node] +1;
    //                 q1.push(neigh);
    //                 parent[neigh] = node;
    //             }
    //         }

    //     }
    //     //Retrace the path-
    //     T d = des;
    //     cout<<endl;
    //     while(d!=src)
    //     {
    //         cout<<d<<" ";
    //         d = parent[d];
    //     }
    //     cout<<src<<endl;
    //     return dist[des];
    // }
    // //Snake and ladder - number of throws needed - 

    //DFS - 
    void dfsHelper(T src,map<T,bool> &visited,map<int,int> &component_pair,int comp)
    {
        visited[src] = true;
        cout<<src<<" ";
        component_pair[comp]++;
        for(auto neigh: adjList[src])
        {
            if(!visited[neigh]&&neigh!=INT_MAX)
            {
                dfsHelper(neigh,visited,component_pair,comp);
            }
        }
    }
    void dfs(T src)
    {
        map<T,bool> visited;
        map<int,int> component_pair;
        int component = 0;
        for(auto node:adjList)
        {
            T n = node.first;
            if(!visited[node]&&node!=INT_MAX)
            {   component++;
                dfsHelper(n,visited,component_pair,component);
            }
        }
        for(auto i:component_pair)
        {
            cout<<"component val  "<<i.first<<" no. - "<<i.second<<endl;
        }
        int ans = 0;
        for(int i=1;i<=component;i++)
        {
            for(int j=i+1;j<=component;j++)
            {
                ans = ans + nCr(component_pair[i],1)*nCr(component_pair[j],1);
            }
        }
        cout<<"Component "<<component;
        cout<<"Combinations  "<<ans;
    }
    //Topolgical Sort - BFS
    void topolocial_BFS()
    {
        map<T,bool> visited;
        map<T,int> indegree;
        queue<T> q1;
        // Initialising of all the nodes to indegree 0
        for(auto i:adjList)
        {
            indegree[i.first] = 0;
        }
        //Value according to neighbour
        for(auto i:adjList)
        {
            for(auto neigh:i.second)
            {
                indegree[neigh]++;
            }
        }
        for(auto i :adjList)
        {
            if(indegree[i.first]==0)
            {
                q1.push(i.first);
            }
        }
        while(!q1.empty())
        {
            T node = q1.front();
            cout<<node<<"  ";
            q1.pop();
            for(auto neigh:adjList[node])
            {
                indegree[neigh]--;
                if(indegree[neigh]==0)
                {
                    q1.push(neigh);
                }
            }
        }
    }
    void dfsHelperfun2(T src,map<T,bool > &visited,list<T> &ordering)
    {
        //make the visited true
        visited[src] = true;
        for(auto neigh:adjList[src])
        {
            if(!visited[neigh])
            {
                dfsHelperfun2(neigh,visited,ordering);
            }
        }
        ordering.push_front(src);
    }
    void topological_sort_DFS()
    {
        map<T,bool > visited;
        list<T> ordering;
        queue<T> q1;
        for(auto i:adjList)
        {
            if(!visited[i.first])
            {
                //Then call the helper Function
                dfsHelperfun2(i.first,visited,ordering);
            }
        }
        //Print the ordering -
        for(auto head:ordering)
        {
            cout<<head<<" ";
        }
    }
    //Cycle in Undirect BFS
    bool cycle_Undirected(T src)
    {
        map<T,bool > visited;
        queue<T> q1;
        map<T,T> parent;

        visited[src] = true;
        q1.push(src);
        parent[src] = src;
        while(!q1.empty())
        {
            T node = q1.front();
            q1.pop();
            for(auto neigh:adjList[node])
            {
                if(visited[neigh]&&parent[node]!=neigh)
                {
                    return true;
                }
                else if(!visited[neigh])
                {
                    q1.push(neigh);
                    visited[neigh] = true;
                    parent[neigh] = node;
                }
            }
        }
        return false;
    }
    //Cycle detection - Directed Graph

    bool dfs_Helper_cycle(T src,map<T,bool> &visited, map<T,bool> inStack)
    {
        visited[src] = true;
        inStack[src] = true;
        //Check for all the neighbours
        for(T neigh:adjList[src])
        {
            //There could be two possibility - 
            //1) either the node is not visited but could be the possible path
            //for a cycle then - 
            //2) The neigh is already present inStack
            if((!visited[neigh]&&dfs_Helper_cycle(neigh,visited,inStack))||inStack[neigh])
            {
                return true;
            }
        }
        //Pop out the node from the stack
        inStack[src] = false;
        return false;
    }

    bool cycle_detection_Directed()
    {
        map<T,bool> visited;
        map<T,bool> inStack;
        for(auto i:adjList)
        {
            T node = i.first;
            if(!visited[node])
            {
               bool isCyclic = dfs_Helper_cycle(node,visited,inStack);
                if(isCyclic) return true;
            }
        }
        return false;
    }

};
int main()
{   //int n;
    //cin>>n;
    
    Graph<string> g1;

    //Topological sort BFS -
    // g1.addEdge("English","Programming Logic",false);
    // g1.addEdge("Maths","Programming Logic",false);
    // g1.addEdge("English","Html",false);
    //   g1.addEdge("Programming Logic","Python",false);
    // g1.addEdge("Programming Logic","Html",false);
  
    // g1.addEdge("Programming Logic","Java",false);
    // g1.addEdge("Programming Logic","Js",false);
    // g1.addEdge("Html","Css",false);
    // g1.addEdge("Css","Js",false);
    // g1.addEdge("Js","Web Developement",false);
    // g1.addEdge("Python","Web Developement",false);
    // g1.addEdge("Java","Web Developement",false);

    // g1.topolocial_BFS();
    // cout<<endl;
    // g1.topological_sort_DFS();


    // Cycle detection Undirected Graph

    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(1,4);

    g.cycle_Undirected(1) ? cout<<"Cycle present \n" : cout<<"Acyclic \n";

    Graph<int> g_cycle;
    g_cycle.addEdge(0,1,false);
    g_cycle.addEdge(0,2,false);
    g_cycle.addEdge(2,3,false);
    g_cycle.addEdge(2,4,false);
   // g_cycle.addEdge(3,0,false);
    g_cycle.addEdge(4,5,false);
    g_cycle.addEdge(1,5,false);

    g_cycle.cycle_detection_Directed() ? cout<<"Cycle Exist\n" : cout<<"Not present\n";
    // Input 1
    // g1.addEdge(1,0);
    // g1.addEdge(2,3);
    // g1.addEdge(0,4);
   // g1.addEdge(4,1);
   // g1.addEdge(6,7);
    // g1.Bfs(1);
    //cout<<endl<<g1.single_source_Spath(2,4)<<endl;
    // cout<<"Dfs  "; g1.dfs(1);
    // cout<<"\nNCR of  4C1"<<nCr(4,2);
    return 0;
}