//Snakes and Ladder
//Min- No of Dice Throw - To reach End
#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T> > adjList;
public:
    void addEdge(T u,T v , bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    int bfs(T src,T dest)
    {
        map<T,T> parent;
        map<T,int> dist;
        for(auto i:adjList)
        {
            dist[i.first] = INT_MAX;
        }
        dist[src]  = 0 ; parent[src] = src;
        queue<T> q1;
        q1.push(src);
        while(!q1.empty())
        {
            T node = q1.front();
            q1.pop();
            for(T neighbour:adjList[node])
            {
                if(dist[neighbour]==INT_MAX)
                {
                    q1.push(neighbour);
                    dist[neighbour] = dist[node] +1;
                    parent[neighbour] = node;
                }
            }
        }
        //Print ALL THE PATH
        // for(auto i:adjList)
        // {
        //     cout<<"Dist "<<i.first<<" -> ";
        //     cout<<dist[i.first]<<endl;
        // }
        T temp = dest;
        while(temp!=src)
        {
            cout<<temp<<"->";
            temp = parent[temp];
        }
        cout<<src<<endl;
        return dist[dest];
    }

};
int main(int argc, char const *argv[])
{
    Graph<int> g;
    int board[50] ={0};
    board[2] = 13; board[5] = 2 ; board[9] = 18 ; board[18] = 11 ; board[17] = -13 ;
    board[20] = -14 ; board[24] = -8; board[25] = -10 ; board[32] = -2; board[34] = -22 ;
    for(int i=0;i<=36;i++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int v = i + dice + board[i+dice];
            g.addEdge(i,v,false);
        }
    }
    cout<<g.bfs(0,36);
    return 0;
}