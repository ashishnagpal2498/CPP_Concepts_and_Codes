//kosaraju's Algorithm for SCC
#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph{
    list<int> *adjList;
    int V;
public:
    Graph(int v)
    {
        V=v;
        adjList = new list<int>[v];
    }
    void addEdge(int u,int v,bool bidir=false)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    //Transpose of Graph -
    Graph* transpose()
    {
        Graph * g = new Graph(this->V);
        for(int v=0;v<V;v++)
        {
            //vertix
            for(auto i=adjList[v].begin();i!=adjList[v].end();i++)
            {
                g->addEdge(*i,v);
            }
        }
        return g; 
    }
    void DfsUtil(int u,bool *visited)
    {
        visited[u] = true;
        cout<<u<<" ";
        for(auto neigh:adjList[u])
        {
            if(!visited[neigh])
            {
                DfsUtil(neigh,visited);
            }
        }
    }
    void fillOrder(int u,bool *visited,stack<int>&fill)
    {
        visited[u] = true;
        for(auto neigh:adjList[u])
        {
            if(!visited[neigh])
            {
                fillOrder(neigh,visited,fill);
            }
        }
        fill.push(u);
    }
    void printStack(stack<int> s)
    {
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
    void printSCCs()
    {
        bool *visited = new bool[V];
        stack<int> fill;
        for(int i=0;i<V;i++) visited[i] = false;

        //Make the stack fill by applying dfs for the fisrt tyme
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                fillOrder(i,visited,fill);
            }
        }
        printStack(fill);
        Graph* gr = transpose();
        //
            for(int i=0;i<V;i++) visited[i] = false;

                //Now appling the dfs according to stack fill
        while(!fill.empty())
        {
            int tp = fill.top();
            fill.pop();
            if(!visited[tp])
            {
                gr->DfsUtil(tp,visited);
                cout<<endl;
            }
        }        
            
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
  
    cout << "Following are strongly connected components in "
            "given graph \n"; 
    g.printSCCs(); 
    return 0;
}