// Single Source shortest path -
#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<queue>
using namespace std;
class Graph{
public:
    map<string,list<string> > adjList;
    int V;
    Graph(int n,int m)
    {
        V = n*m;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         string s="";
        //         s+=i;
        //         s+=",";
        //         s+=j;
        //         adjList[s].push_back("NULL");
        //     }
        // }
    }
    void addEdge(string u,string v){
        adjList[u].push_back(v);
    }
    void printGraph(){
        for(auto i: adjList)
        {
            cout<<i.first<<" -> ";
            for(auto s: i.second)
            {
                cout<<s<<" ";
            }
            cout<<endl;
        }
    }
    int shortestPath(string s,char board[11][11])
    {
        map<string,int> dist;
        map<string,string> parent;
        queue<string> q;
        for(auto i : adjList)
        {   
            dist[i.first] = INT_MAX;
        }
        q.push(s);
        dist[s] = 0;
        int minDistance = INT_MAX;
        while(!q.empty())
        {
            string f = q.front();
            q.pop();
            // cout<<f<<" -> "<<endl;
            for(auto neigh: adjList[f])
            {
                if(neigh != "NULL" && dist[neigh] == INT_MAX){
                    // not visited;
                    parent[neigh] = f;
                    dist[neigh] = dist[f] +1;
                    q.push(neigh);
                }
                int index1 = (int) (neigh[0] - '0');
                int index2 = (int)(neigh[2]- '0');
                if(board[index1][index2] == 'B'){
                    minDistance = min(minDistance,dist[neigh]);
                }
            }
        }
        if(minDistance == INT_MAX) return -1;
        return minDistance;
    }
};
int main()
{
    int n,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        char board[11][11];
        int solution[11][11];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>board[i][j];
            }
        }
        // Create Graph -
        Graph g(n,m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 'O' || board[i][j] == 'B')
                {
                    string s ="";
                    s+=(char)(i + '0');
                    s+=",";
                    s+=(char)(j + '0');
                    if(i+1<n && board[i+1][j] != 'W'){
                        string v = "";
                        v+=(char)((i+1)+ '0');
                        v+=",";
                        v+=(char)(j+ '0');
                        g.addEdge(s,v);
                    }
                    if(j+1<m && board[i][j+1] !='W'){
                        string v = "";
                        v+=(char)(i + '0');
                        v+=",";
                        v+=(char)((j+1)+ '0');
                        g.addEdge(s,v);
                    }
                    if((j-1) >= 0 && board[i][j-1] != 'W')
                    {
                        string v = "";
                        v+=(char)(i + '0');
                        v+=",";
                        v+=(char)((j-1)+ '0');
                        g.addEdge(s,v);
                    }
                    if((i-1) >= 0 && board[i-1][j] !='W')
                    {
                        string v = "";
                        v+=(char)((i-1) + '0');
                        v+=",";
                        v+=(char)((j)+ '0');
                        g.addEdge(s,v);
                    }
                }
            }
        }
        // g.printGraph();
        // Graph has been created -
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 'O')
                {
                    string s ="";
                    s+=(char)(i+'0');
                    s+=",";
                    s+=(char)(j+'0');
                    int dist = g.shortestPath(s,board);
                    solution[i][j] = dist;
                }
                else if(board[i][j]== 'W')
                {
                    solution[i][j] = -1;
                }
                else{
                    solution[i][j] = 0;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<solution[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}