//Flyod Warshal's Algorithm
#include <iostream>
#include<list>
#include<vector>
using namespace std;
#define V 4
#define INF 99999
void printGraph(int graph[V][V])
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {   if(graph[i][j]==INF) 
            {
            cout<<"INF ";
            }
            else {cout<<graph[i][j]<<" ";}
        }
        cout<<endl;
    }
}
void floyd_Warshal_Algo(int graph[V][V])
{
        //order of (v)3
    //Intermediate node -
    int dist[V][V] ,i,j,k;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++) dist[i][j]=graph[i][j];
    }
    for(k=0;k<V;k++)
    {
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
    printGraph(dist);
}
int main(int argc, char const *argv[])
{
    /* code */
      int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
  
    // Print the solution  
    floyd_Warshal_Algo(graph);  
    return 0;
}