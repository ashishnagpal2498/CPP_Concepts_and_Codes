// Graphs - 
// Can be created by 2D vector 
// Adjcency list -> to every Node a list is mapped-

// Minimum spanning tree - 
//
#include<iostream>
#include<map>
#include<string>
#include<list>
#include<queue>
#include<typeinfo>
using namespace std;
// In this Graph it will be from 0 iteration
template<typename T >
class Graph{
    list<T>* adjList;
    int V;
    map<string,int> indexVal;
     int count;    //list<string> s;
public:
    Graph(int v = 5){
        V = v;
        count = 0;
        adjList = new list<T>[V];
    }
    void addEdge(T u,T v,bool birDir = true){
       // const type_info& t1 = typeid(7);
       //  cout<<t1.name()<<endl;
        if(*typeid(u).name() != 'i')
        {   
            if(indexVal.find(u) != indexVal.end()){
                // Already present
                adjList[indexVal[u]].push_back(v);
            }
            else{
                indexVal[u] = count;
                count++;
                adjList[indexVal[u]].push_back(v);
            }
        }
        else{
        // adjList[u].push_back(v);
        // if(birDir){
        //     adjList[v].push_back(u);
        // }
        }
    }
    void printGraph(){
        for(int i=0;i<V;i++){
            cout<<i<<" -> ";
            for(auto vertex: adjList[i]){
                cout<<vertex<<",";
            }
            cout<<"\n";
        }
    }
    void bfs(T start){
        // Provided the starting point
        // FIFO technique
        queue<T> q1;
        q1.push(start);
        map<T,bool> visited;
        while(!q1.empty()){
            T frontVertex = q1.front();
            visited[frontVertex] = true;
            q1.pop();
            cout<<frontVertex<<" -> ";
            for(auto i:adjList[frontVertex]){
                if(!visited[i]){
                    q1.push(i);
                    visited[i] = true;
                }
            }
        }

    }

     int s3p(T start, T dest){
        // Single Source Shortest Path ->
        // Undirected unweighted graph -

        queue<T> q1;
        q1.push(start);
        map<T,int> dist;
        // Initialize the path with max Value
        for(int i=0;i<V;i++) dist[i] = INT_MAX;

        dist[start] = 0;
        while(!q1.empty()){
            T frontVertex = q1.front();
            q1.pop();
            cout<<frontVertex<<" -> ";
            for(auto i:adjList[frontVertex]){
                if(dist[i] == INT_MAX){
                    q1.push(i);
                    dist[i] = dist[frontVertex]+1;
                }
            }
        }
        return dist[dest];
    }
    // Snake and Ladder - bfs

    // DFS Helper function
    void dfsHelper(T node,map<T,bool>& visited){
        visited[node] = true;
        cout<<node<<" -> ";
        for(T i: adjList[node]){
            if(!visited[i]){
                dfsHelper(i,visited);
            }
        }
    }

    void dfs(T src){
        map<T,bool> visited;
        dfsHelper(src,visited);
    }

    int ConnectedComponents(){
        int count = 0;
        map<T,bool> visited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                dfsHelper(i,visited);
            }
        }
        cout<<"\n";
        return count;
    }

    // Topological sort for a DAG -
    // Take a Linked List ->

};

int main(){
    // // Section 1 - 
    // Graph<int> g(8);
    // g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,0);
    // g.addEdge(2,0);
    // g.addEdge(3,4);
    // g.addEdge(5,6);
    // g.addEdge(6,7);
    // //g.printGraph();
    // cout<<"BFS of Graph \n";
    // g.bfs(0);
    // // cout<<"\nDistance of node from source "<<g.s3p(0,4);
    // cout<<"\n DFS of Graph\n";
    // g.dfs(0);
    // Take the number of Jumps 
    // Construct the graph -> v = u + dice + board[u+dice];
    // 
    // cout<<"\nConnected Components ";
    // cout<<g.ConnectedComponents();
    
    // Topological Sort -

    Graph<string> g(9);
    g.addEdge("English","PL",false);
    g.addEdge("Maths","PL",false);
    g.addEdge("PL","HTML",false);
    g.addEdge("PL","Python",false);
    g.addEdge("PL","JS",false);
    g.addEdge("PL","Java",false);
    g.addEdge("HTML","CSS",false);
    g.addEdge("CSS","JS",false);
    g.addEdge("JS","Web Dev",false);
    g.addEdge("Python","Web Dev",false);
    g.addEdge("Java","Web Dev",false);

    g.printGraph();
    return 0;
}