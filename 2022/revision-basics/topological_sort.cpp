// Topological Sort BFS and DFS
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
    map<T, list<T> > adjList;
public:
    Graph(){

    }
    void addEdge(T u,T v,bool birDir = true){
       // const type_info& t1 = typeid(7);
       //  cout<<t1.name()<<endl;
        adjList[u].push_back(v);
        if(birDir){
            adjList[v].push_back(u);
        }
    }
    void printGraph(){
        for(auto i:adjList){
            cout<<i.first<<" -> ";
            for(auto vertex: i.second){
                cout<<vertex<<",";
            }
            cout<<"\n";
        }
    }
    void dfsHelper(T node,map<T,bool>&visited,list<T> &ans){
        visited[node] = true;
        for(T neighbour:adjList[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited,ans);
            }
        }
        ans.push_front(node);
    }
    // Topological Sort 
    void dfs_topological(){
        list<T> ans;
        map<T,bool> visited;
        // dfsHelper(src,visited,ans);
        for(auto i:adjList){
            if(!visited[i.first]){
                dfsHelper(i.first,visited,ans);
            }
        }
        for(T i: ans){
            cout<<i<<" -> ";
        }
    }

    void bfs_topologicalSort(){
        // Indegree ->

        map<T,int> Indegree;
        queue<T> q1;
        for(auto i:adjList){
            Indegree[i.first] = 0;
        }

        // Calculate inDegree for all the nodes
        for(auto i:adjList){
            for(T neigh: i.second){
                Indegree[neigh]++;
            }
        }

        for(auto i:adjList){
            if(Indegree[i.first] == 0){
                q1.push(i.first);
            }
        }

        // BFS
        while(!q1.empty()){
            T topNode = q1.front();
            q1.pop();
            cout<<topNode<<" -> ";

            for(T neigh:adjList[topNode]){
                Indegree[neigh]--;
                if(Indegree[neigh] == 0) q1.push(neigh);
            }
        }
    }
    bool cycleDetectionBFS(T src){
        queue<T> q1;
        map<T,bool> visited;
        map<T,T> parentNode;
        
        q1.push(src);
        visited[src] = true;
        parentNode[src] = -1;

        while(!q1.empty()){
            T frontNode = q1.front();
            q1.pop();

            for(T neigh: adjList[frontNode]){
                if(!visited[neigh]){
                    q1.push(neigh);
                    visited[neigh] = true;
                    parentNode[neigh] = frontNode;
                }
                else if(visited[neigh] && parentNode[frontNode] != neigh){
                    // There are multiple paths to reach this node 
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){

    // Graph<string> g;
    // g.addEdge("English","PL",false);
    // g.addEdge("Maths","PL",false);
    // g.addEdge("PL","HTML",false);
    // g.addEdge("PL","Python",false);
    // g.addEdge("PL","JS",false);
    // g.addEdge("PL","Java",false);
    // g.addEdge("HTML","CSS",false);
    // g.addEdge("CSS","JS",false);
    // g.addEdge("JS","Web Dev",false);
    // g.addEdge("Python","Web Dev",false);
    // g.addEdge("Java","Web Dev",false);
   // g.printGraph();
    // g.dfs_topological();
    // cout<<"\nBFS topological Sort\n";
    // g.bfs_topologicalSort();

    // Cycle Detection 
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    // g.addEdge(3,0);
   g.addEdge(2,0);
    g.addEdge(3,4);
    g.cycleDetectionBFS(0) ? cout<<"Cycle exist\n" : cout<<"Graph is Acyclic\n";
    return 0;
}