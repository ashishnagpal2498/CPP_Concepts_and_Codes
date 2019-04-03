#include<iostream>
#include<queue>
#include<list>
#include<map>
using namespace std;
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
class Graph{
    map<int,list<int > > adjList;
public:
    Graph(int n)
    {
        for(int i=0;i<n;i++)
        {
            adjList[i].push_back(INT_MAX);
        }
    }
    void printGraph()
    {
        for(auto i:adjList)
        {
            int Node = i.first;
            cout<<Node<<" ->  ";
            for(int neigh:adjList[Node])
            {
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
    void addEdge(int u,int v,bool bidir=true)
    {
        adjList[u].push_front(v);
        if(bidir)
        {
            adjList[v].push_front(u);
        }
    }
    int dfsHelper(int src,map<int,bool> &visited,map<int,int> &component_pair,int comp)
    {
        visited[src] = true;
        // cout<<src<<" ";
        int sz =1;
        component_pair[comp]++;
        for(auto neigh: adjList[src])
        {
            if(!visited[neigh]&&neigh!=INT_MAX)
            {   
               sz+= dfsHelper(neigh,visited,component_pair,comp);
            }
        }
        return sz;
    }
    void dfs(int V)
    {
        map<int,bool> visited;
        map<int,int> component_pair;
        int component = 0;
        int ans =0;
        ans+= (V*(V-1))/2;    
        for(auto node:adjList)
        {
            int n = node.first;
            if(!visited[n]&&n!=INT_MAX)
            {   component++;
              int sz =  dfsHelper(n,visited,component_pair,component);
                ans -= (sz*(sz-1))/2;
            }
        }
        // for(auto i:component_pair)
        // {
        //     cout<<"component val  "<<i.first<<" no. - "<<i.second<<endl;
        // }
        //int ans = 0;
        // for(int i=1;i<=component;i++)
        // {
        //     for(int j=i+1;j<=component;j++)
        //     {
        //         ans = ans + nCr(component_pair[i],1)*nCr(component_pair[j],1);
        //     }
        // }
        // cout<<"Component "<<component;
        // cout<<"Combinations  "<<ans;
        cout<<ans<<endl;
    }
};
int main()
{   
    int n,m;
    cin>>n>>m;
    Graph g(n);
    int u,v;
    for(int i=0;i<m;i++)
    {   cin>>u>>v;
        g.addEdge(u,v);
    }
    g.dfs(n);
    return 0;
}
/* include<iostream>
#include<list>
using namespace std;

class Graph{
    list<int> *l;
    int V;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    int dfs_helper(int i,bool *visited){
        visited[i] = true;
        int sz = 1;

        for(int neighbour:l[i]){
            if(!visited[neighbour]){
                sz += dfs_helper(neighbour,visited);
            }
        }
        return sz;
    }

    int dfs(){
        bool *visited = new bool[V]{0};
        int ans = V*(V-1)/2;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                int sz = dfs_helper(i,visited);
                ans -= (sz)*(sz-1)/2;
            }
        }
        return ans;
    }


};


int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(0,4);
    cout<<g.dfs()<<endl;

    return 0;
}*/