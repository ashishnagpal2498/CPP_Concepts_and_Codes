// Graphs Implementation
// Degree - Indegree , outdegree 
//Video Lectures - 
//Edge Rank Algorithm
//Network latency - Bellman Ford algo
//Terminology
// Minimum Spanning Tree
//Weighted Unweigthed graph
// Edge List, Adjancy matrix and Adjancey LIST
// Linked list
#include<iostream>
#include<list>
using namespace std;

class Graph{
    // Number of vertix;
    int V;
    list<int>* l;
public:
    Graph(int v)
    {
        V=v;
        l = new list<int>[V];
    }
    void addEdge(int u , int v , bool bidir=true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(int i=0;i<V;i++)
        {
            // l is a Linked LIst
            // ForEach Loop
            cout<<i<<" ->  ";
            for(auto vertix:l[i])
            {
                cout<<vertix<<"  ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.printAdjList();

    return 0;
}