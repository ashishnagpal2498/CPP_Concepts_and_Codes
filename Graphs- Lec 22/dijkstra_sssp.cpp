//Dijkstra Algorithm Single source shortest path - Directed Graph
#include<iostream>
#include<map>
#include<set>
#include<list>
using namespace std;
template<typename T>
class Graph{
    map<T,list<pair<T,int> > > adjList;
public:
    Graph()
    {

    }
    void addEdge(T u,T v,int dist,bool bidir=true)
    {
        // The source node - and the destination node with the given dis-
        //As it is a weighted graph
        adjList[u].push_back(make_pair(v,dist));
        if(bidir)
        {
            adjList[v].push_back(make_pair(u,dist));
        }
    }
    void printAdjList()
    {
        //Iterate over all the keys in the graph
        for(auto i:adjList)
        {
            // Iterator-
            cout<<i.first<<" -> ";
            for(auto neighbour:i.second)
            {
                cout<<neighbour.first<<" "<<neighbour.second<<" , ";
            }
            cout<<endl;
        }
    }
    void dijkstra_SSSP(T src)
    {
        // Need to maintain a distance map - and set all the other distance as infi
        map<T,int> dist;
        for(auto i:adjList)
        {
            dist[i.first] = INT_MAX;
        }

        // Maintain a set 
        set<pair<int, T> > s;
        dist[src] =0;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {

            // Take the top value of the set
            auto p = *(s.begin()); //s.begin gives an iterator -
            s.erase(s.begin());
            T node = p.second;
            int node_dis = p.first;

            // Iteration on neighbouring nodes of the current node
            for(auto neigh:adjList[node])
            {   //neigh - its a pair of T and distance - 
                //Check for the distance
                    int smalldist = node_dis + neigh.second;
                if(smalldist < dist[neigh.first])
                {
                    //Need to make a replacement in the set if the value exist
                    //Neigh . second - distance , first - City
                    auto npair_exist_find = make_pair(neigh.second,neigh.first);
                    auto neighbour_pair = s.find(npair_exist_find);
                    if(neighbour_pair!=s.end())
                    {
                        s.erase(npair_exist_find);
                    }
                    npair_exist_find.first = smalldist;
                    s.insert(npair_exist_find);
                    dist[neigh.first] = smalldist; 
                }
            }
        }
        for(auto i:dist)
        {
            cout<<i.first<<" dist is "<<i.second<<endl;
        }
    }

};
int main()
{
    Graph<string> india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Bhopal","Mumbai",3);
    india.addEdge("Delhi","Agra",1);

    india.printAdjList();
    cout<<endl;
    india.dijkstra_SSSP("Amritsar");
    return 0;
}