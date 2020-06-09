// Tree Difference
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
class Graph {
    list<int> * adjList;
    int v;
public:
    Graph(int nodes)
    {
        adjList =  new list<int>[nodes+1];
        v = nodes;
    }
    void addEdge(int u,int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void printGraph(){
        for(int i=1;i<=v;i++)
        {
            cout<<i<<"-> ";
            for(auto value : adjList[i])
            {
                cout<<value<<" ";
            }
            cout<<endl;
        }
    }
    vector<int>* nodes(int i,int j)
    {
        // path between - 
        vector<int>* ans = new vector<int>;
        queue<int> q;
        q.push(i);
        map<int,bool> visited;

        while(!q.empty())
        {
            int index = q.front();
            visited[index] = true;
            q.pop();
            ans->push_back(arr[index]);
            if(index == j) break;
            bool flag = false;
            for(int neigh: adjList[index])
                {   if(!visited[neigh])
                     q.push(neigh);
                     if(neigh == j) {
                        flag = true;
                        break;
                     }
                }
         if(flag) {
                ans->push_back(arr[j]);
                return ans;
            }
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {   ll q,u,v;
        cin>>n;
        cin>>q;
        Graph g(n);
        for(int i=1;i<=n;i++) cin>>arr[i];
        for(int i=0;i<n-1;i++)
        {
            cin>>u>>v;
            g.addEdge(u,v);
        }
        // g.printGraph();
        for(int i=0;i<q;i++)
        {
            ll minVal = INT_MAX;
            cin>>u>>v;
            vector<int>* ans = g.nodes(u,v);
            // cout<<"Array - ";
            sort(ans->begin(),ans->end());
            for(int i=0,j=1;j<ans->size();i++,j++)
            {      {ll v = abs((*ans)[i]- (*ans)[j]);
                    minVal = min(minVal,v);}
            }
            // cout<<endl;
            cout<<minVal<<endl;
        }
    }
    return 0;
}    