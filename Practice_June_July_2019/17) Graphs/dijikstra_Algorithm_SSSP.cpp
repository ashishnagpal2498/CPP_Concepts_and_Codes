//Dijikstra Algorithm - Shortest path from single source in undirected Weighted Graph
#include<iostream>
#include<list>
#include<map>
#include<set>
using namespace std;
template<typename T>
class Graph{
    map<T, list<pair<T,int> > > adjList;
public:
    void addEdge(T u,T v,int dist,bool bidir=true)
    {
        adjList[u].push_back(make_pair(v,dist));
        if(bidir)
        {
        adjList[v].push_back(make_pair(u,dist));

        }
    }
    void printGraph()
    {
        for(auto i:adjList)
        {
            cout<<i.first<<"----> ";
            for(auto p:i.second)
            {
                cout<<p.first<<"- "<<p.second<<" || ";
            }
            cout<<endl;
        }
    }
    void dijikstra_Algo(T src)
    {
        //distance map
        map<T,int> dist;
        //set because value need to update
        set<pair<int,T> > s1;

        //INITIALIZING ALL THE NODES AT INFINITE DISTANCE;
        for(auto i:adjList)
        {
            dist[i.first] = INT_MAX;
        }

        dist[src] = 0;

        s1.insert(make_pair(0,src));
        //Taking - set as dist,T because - sorting -
        while(!s1.empty())
        {
            auto parentNodePair = *(s1.begin());
            s1.erase(parentNodePair);
            T parentNode = parentNodePair.second;
            int pDistance = parentNodePair.first;

            //Relaxing every neighbour of the node
            for(auto neigh:adjList[parentNode])
            {
                int small_Dist = dist[parentNode] + neigh.second;
                if(small_Dist< dist[neigh.first])
                {
                    //Value is smaller - 
                    //Node can be relaxed
                    //creating a pair out of old - Pair
                    pair<int,T > newNode = make_pair(dist[neigh.first],neigh.first);
                    auto findNode = s1.find(newNode);
                    if(findNode!=s1.end())
                    {
                        //Erase the node
                        s1.erase(newNode);
                    }
                    //update the distance -
                    dist[neigh.first] = small_Dist;
                    newNode.first = small_Dist;
                    s1.insert(newNode);
                }
            }

        }
        for(auto i:adjList)
        {
            cout<<src<<" to "<<i.first<<" distance "<<dist[i.first]<<endl;
        }
    }
};
int main(int argc, char const *argv[])
{
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
    india.dijikstra_Algo("Amritsar");
    return 0;
}