//Reaching 1 number to another - Prime-
#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int> > adjList;
public:
    void addEdge(int u,int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void print()
    {
        for(auto i:adjList)
        {
            cout<<i.first<<"=>";
            for(auto neigh:i.second)
            {
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
void primeSeive(vector<int>&v)
{
    int n = 9999;
    bool pset[10000];
    memset(pset,true,sizeof(pset));

    for(int p=2;p<=n;p++)
    {
        if(pset[p]==true)
        {
            //mark all its multiple as false
            for(int i=p*p;i<=n;i+=p)
                pset[i] = false;
        }
    }
    for(int i=1000;i<=9999;i++)
    {
        if(pset[i])
        {
            v.push_back(i);
        }
    }
}
int bfs(int start,int des)
{
    queue<int> q1;
    q1.push(start);
    map<int,int> visited;
    for(auto i:adjList)
    {
        visited[i.first] = 0;
    }
    visited[start]= true;
    while(!q1.empty())
    {
        int tp = q1.front();
        q1.pop();
        for(auto neigh:adjList[tp])
        {
            if(visited[neigh]==0)
            {
                visited[neigh] = visited[tp]+1;
                q1.push(neigh);
            }
            if(neigh==des) return visited[neigh]-1;
        }
    }
}
bool compare(int n1,int n2)
{
    string s1= to_string(n1);
    string s2 = to_string(n2);
    int count=0;
    if(s1[0]!=s2[0]) count++;
    if(s1[1]!=s2[1]) count++;
    if(s1[2]!=s2[2]) count++;
    if(s1[3]!=s2[3]) count++;
    return count<=1;
}
int shortestPath(int start,int end)
{
    vector<int> primes;
    primeSeive(primes);
    //No need to make Adj of vector size-
    // for(int i=0;i<primes.size();i++)
    // {
    //     cout<<primes[i]<<" ";
    // }
    for(int i=0;i<primes.size();i++)
    {
        for(int j=i+1;j<primes.size();j++)
        {
            if(compare(primes[i],primes[j]))
            {
                addEdge(primes[i],primes[j]);
            }
        }
    }
    return bfs(start,end);
}

};
int main(int argc, char const *argv[])
{
    int n1 = 1033 , n2 = 8179;
    Graph g;
    cout<<g.shortestPath(n1,n2);
    // g.print();
    return 0;
}