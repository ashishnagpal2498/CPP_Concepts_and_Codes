// Kosaraju's Algorithm for Strongly connected components - Graph
// Mother vertix - find

#include<iostream>
#include<map>
#include<stack>
#include<list>
using namespace std;

// Templated graph
template<typename T>
class Graph {
    map<T,list<T> > adjList;

    // Transpose of a Graph ->
    Graph transposeGraph(){
        Graph g;

        for(auto i:adjList){
            for(auto neigh: i.second){
                g.addEdge(neigh,i.first,false);
            }
        }
        return g;
    }

    // DFS Helper function
    void dfsUtil(T node, map<T,bool>& visited,Graph &g){
        visited[node] = true;
        cout<<node<<" -> ";
        for(auto neigh:g.adjList[node]){
            if(!visited[neigh]){
                dfsUtil(neigh,visited,g);
            }
        }
    }
public:
    // Create Graph
    void addEdge(T u,T v,bool bidir=true){
        adjList[u].push_back(v);

        if(bidir){
            adjList[v].push_back(u);
        }
    }

    // Get the Order of finish time
    void fillOrder(T node,map<T,bool>& visited,stack<T>& order){
        visited[node] = true;

        for(auto neigh:adjList[node]){
            if(!visited[neigh]){
                fillOrder(neigh,visited,order);
            }
        }
        order.push(node);
    }

    void stronglyCC(){
        map<T,bool> visited;

        stack<T> order;

        for(auto node:adjList){
            if(!visited[node.first])
            fillOrder(node.first,visited,order);
        }
        // Reset the Visited MAP
        for(auto node:adjList){
            visited[node.first] = false; 
        }

        Graph g = transposeGraph(); 
    
        while(!order.empty()){

            T topEle = order.top();
            order.pop();
            if(!visited[topEle]){
                dfsUtil(topEle,visited,g);
                cout<<"\n";
            }

        }
    }
};

int main(){
    Graph<int> g;
     g.addEdge(1, 0,false);
    g.addEdge(0, 2,false);
    g.addEdge(2, 1,false);
    g.addEdge(0, 3,false);
    g.addEdge(3, 4,false);
  
    cout << "Following are strongly connected components in "
            "given graph \n";
    g.stronglyCC();
    return 0;
}

