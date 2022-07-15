// Dijikstra's Algorithm - SSSP
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
        // Node is mapped to a Pair of node and weight
       map<T, list<pair<T,int> > > adjList; // Weighted Graph
public:
    Graph(){

    }
    void addEdge(T u,T v,int dist,bool birDir = true){
       // const type_info& t1 = typeid(7);
       //  cout<<t1.name()<<endl;
        adjList[u].push_back({v,dist});
        if(birDir){
            adjList[v].push_back({u,dist});
        }
    }
    void printGraph(){
        for(auto i:adjList){
            cout<<i.first<<" -> ";
            for(auto vertex: i.second){
                cout<<vertex.first<<"|"<<vertex.second<<" , ";
            }
            cout<<"\n";
        }
    }

    // Dijikstra's Algorithm
    void dijikstra_sssp(T src){

        set<pair<int,T> > s1; // Instead of Queue taking set as we want to remove the value;

        map<T,int> dist;

        for(auto i: adjList){
            dist[i.first] = INT_MAX;
        }

        dist[src] = 0;
        s1.insert({0,src});

        while(!s1.empty()){

            pair<int,T> newNode = *(s1.begin()); // No front or top method
            int nodeDist = newNode.first;
            T nodeVal = newNode.second;

            s1.erase(newNode);

            for(auto neigh: adjList[nodeVal]){

                int smallDist = dist[nodeVal] + neigh.second;
                if(smallDist < dist[neigh.first]){

                    // Check if the node is present in set
                    pair<int,T> neighbourPair = make_pair(dist[neigh.first],neigh.first);
                    if(s1.find(neighbourPair) != s1.end()){
                        s1.erase(neighbourPair);
                    }

                    neighbourPair.first = smallDist;
                    dist[neigh.first] = smallDist;
                    s1.insert(neighbourPair);
                }
            }
        }
        for(auto i: dist){
            cout<<src<<"->"<<i.first<<" | "<<i.second<<endl;
        }
    }
};

int main(){
         Graph<string> india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Bhopal","Mumbai",3);
    india.addEdge("Delhi","Agra",1);
    india.printGraph();
    cout<<endl<<"DIJIKSTRA \n";
    india.dijikstra_sssp("Amritsar");
    return 0;
}
