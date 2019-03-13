//Topological sort - 
#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T> > adjList;
public:
    Graph()
    {

    }
    void addEdge(T u,T v , bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void printG()
    {
        //Printing the graph taking all the nodes 
        for(auto i:adjList)
        {
            cout<<i.first<<" -> ";
            for(auto vertex:i.second)
            {
                cout<<vertex<<" ";

            }
            cout<<endl;
        }
    }
    // void topological_Sort()
    // {
    //     queue<T> q1;
    //     map<T,bool> visited;
    //     map<T,int> indegree;

    //     for(auto i:adjList)
    //     {   //All the nodes have 0 indegree initially
    //         indegree[i.first] = 0;
    //     }

    //     // Alloting the indegree accordingly
    //     for(auto i:adjList)
    //     {
    //         // T u = i.first;
    //         for(auto child:i.second)
    //         {
    //             indegree[child]++;
    //         }
    //     }

    //     // Now pushing all the nodes into queue which have 0 indegree
    //     for(auto i:adjList)
    //     {
    //         T u = i.first;
    //         if(indegree[u]==0) q1.push(u);
    //     }

    //     while(!q1.empty())
    //     {
    //         T u = q1.front();
    //         cout<<u<<" -> ";
    //         q1.pop();

    //         // Neighbour nodes of the source node -indegree --
    //         for(T node:adjList[u])
    //         {
    //             indegree[node]--;
    //             if(indegree[node]==0)
    //             {
    //                 q1.push(node);
    //             }
    //         }
    //     }
    // }
    void dfsHelper(T node,map<T,bool> &visited,list<T> &ordering)
    {
        //  
        // Sapiet - 
        // 
        visited[node] = true;
        for(auto neighbour:adjList[node])
        {
            if(!visited[neighbour])
            {
                dfsHelper(neighbour,visited,ordering);
            }
        }
        // Topological Sort - add 1 line
        ordering.push_front(node);
    }
    void dfsTopologicalSort()
    {
        map<T,bool> visited;
        list<T> ordering;

        for(auto i:adjList)
        {
            T currnode = i.first;
            if(!visited[currnode])
            {
                dfsHelper(currnode,visited,ordering);
            }
        }  
        for(T element:ordering)
        {
            cout<<element<<"  ";
        }

    }
};
int main()
{
    Graph<string> g;
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,4);
    // g.addEdge(1,4);
    // g.printG();
    g.addEdge("English","Programming Logic",false);
        g.addEdge("Maths","Programming Logic",false);
    g.addEdge("Programming Logic","HTML",false);
    g.addEdge("Programming Logic","Java",false);
    g.addEdge("Programming Logic","Python",false);
    g.addEdge("Programming Logic","JS",false);
    g.addEdge("Python","Web Dev",false);
    g.addEdge("HTML","CSS",false);
    g.addEdge("CSS","JS",false);
    g.addEdge("JS","Web Dev",false);
    g.addEdge("Java","Web Dev",false);
    g.addEdge("Python","Web Dev",false);

    // g.topological_Sort();
    g.dfsTopologicalSort();
    return 0;
}