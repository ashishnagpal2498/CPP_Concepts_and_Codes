#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<queue>
using namespace std;
class Graph{
public:
    list<string> * adjList;
    int v;
    Graph(int n)
    {
        v= n;
        adjList = new list<string>[n];
    }
    void addEdge(string u,string v,bool bidir = true)
    {
        adjList[u].push_back(v);
       if(bidir) adjList[v].push_back(u);
    }
    void singleSourceShortestPath(string s,string d)
    {
        map<string,int> dist;
        map<string,string> parent;
        for(int i=0;i<v;i++)
        {
            dist[adjList[i]] = INT_MAX;
        }

        queue<string> q;
        q.push(s);
        dist[s] = 0;
        while(!q.empty())
        {
            string f = q.front();
            q.pop();
            for(auto neigh: adjList[f])
            {
                if(dist[neigh] == INT_MAX)
                {
                    dist[neigh] = dist[f] +1;
                    parent[neigh] = f;
                    q.push(neigh);
                }
            }
        }
        cout<<dist[d]<<"\n";

    }
};
bool singleLetterDiff(string A,string B)
{   int count =0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=B[i]) count++;
        if(count>1) return false;
    }
    return true;
}
int main()
{
    string beginWord,endWord,s;
    vector<string> words;
    map<string,bool> wordMap;
    cout<<"Enter begin and endWord";
    cin.get();
    getline(cin,beginWord);
    getline(cin,endWord);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        getline(cin,s);
        words.push_back(s);
        wordMap[s] = true;
    }
    Graph g(n);
    for(int i=0;i<n;i++)
    {
        if(singleLetterDiff(beginWord,words[i]))
        {
            g.addEdge(beginWord,words[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(singleLetterDiff())
        }
    }

}