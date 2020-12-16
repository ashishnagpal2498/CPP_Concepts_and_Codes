// Graph Implementation
#include<bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    list<int>*adjList;
public:
    Graph(int v) {
        V = v;
        adjList = new list<int>[v];
    }
    void addEdge(int u, int v, bool bidir = false) {
        if (bidir) {
            adjList[v].push_back(u);
        }
        adjList[u].push_back(v);
    }
    void countPathsUtil(int u, int d, int &count) {

        if (u == d) {
            count++;
            return;
        }

        for (auto neigh : adjList[u]) {
            countPathsUtil(neigh, d, count);
        }
    }
    int countPaths(int s, int d) {
        int count = 0;
        countPathsUtil(s, d, count);
        return count;
    }
    int bfsPrimes(int in1, int in2) {
        map<int, int> visited;
        queue<int> q1;
        visited[in1] = 1;
        q1.push(in1);
        visited[in1] = true;
        while (!q1.empty()) {
            int firstIndex = q1.front();
            q1.pop();
            for (auto neigh : adjList[firstIndex]) {
                if (!visited[neigh]) {
                    visited[neigh] = visited[firstIndex] + 1;
                    q1.push(neigh);
                }
                if (neigh == in2) {
                    return visited[neigh] - 1;
                }
            }
        }
    }
    void printGraph(vector<int> primes) {
        for (int i = 0; i < V; i++) {
            cout << primes[i] << " ";
            for (int j = 0; j < adjList[i].size(); j++) {
                cout << primes[j] << " -> ";
            }
            cout << endl;
        }
    }

    void dfsHelperTopologicalSort(int i, map<int, bool> visited, list<int> ordering) {
        visited[i] = true;

        for (auto neigh : adjList[i]) {
            if (!visited[neigh]) {

            }
        }
        ordering.push_front(i);
    }
    // Topological Sort ->
    void dfsTopologicalSort(int start) {

        map<int, bool> visited;
        list<int> ordering;
        for (int i=0;i<V;i++) {
            if (!visited[i]) {
                dfsHelperTopologicalSort(i, visited, ordering);
            }
        }
        //Print ordering
    }

    // BFS Topological Sort (Kahn's Algorithm)

    // Cycle Detection using BFS
    bool cycleBFS(int src) {
        map<int, bool> visited;
        map<int, int> parent;
        parent[src] = src;
        visited[src] = true;

        queue<int> q1;
        q1.push(src);
        while (!q1.empty()) {
            int node = q1.front();
            q1.pop();
            for (auto neigh : adjList[node]) {
                if (visited[neigh] == true && parent[node] != neigh) {
                    return true;
                }
                else if (!visited[neigh]) {
                    visited[neigh] = true;
                    parent[neigh] = node;
                }
            }
        }


    }

    void sumMinHelper(int i, map<int, bool>&visited, int &minEle) {
        visited[i] = true;
        minEle = min(minEle, i);
        for (auto neigh : adjList[i]) {
            sumMinHelper(neigh, visited, minEle);
        }
    }

    int sumMinElements() {
        int sum = 0;
        map<int, bool> visited;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                int minEle = INT_MAX;
                sumMinHelper(i, visited, minEle);
                sum += minEle;
            }
        }
        return sum;
    }
    // Min no of moves required by the horse to reach the state ->
    int minMovesHorse(int start, int target) {
        // Take a class -> cell -> x,y and dist ->
        int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
        // queue<cell> q1;
        // q1.push({0,1,0});
        // map<pair<int,int>,bool > visited;
        // while(!q1.empty()){
        //     // Pull out of queue

        //     // Check if the node is target


        //     // For neighbours ->
        //     for(int i=0;i<8;i++){
        //         // Positions horse can take

        //         // If those positions are valid -> Inside Board and visited nahi hai , go on that->
        //         // push that to queue -> dist +1;
        //     }
        // }
    }
    bool dfsCycleUtil(int v, map<int, bool> &visited, map<int, bool> &inStack) {

        visited[v] = true;
        inStack[v] = true;

        for (auto neigh : adjList[v]) {
            if ((!visited[neigh] && dfsCycleUtil(neigh, visited, inStack)) || inStack[neigh]) return true;
        }
        inStack[v] = false;
        return false;
    }
};

// Dijistra Algorithm ->
template<typename T>
class Graph2 {
    map<T, list<pair<T, int> >> adjList;
public:
    void addEdge(T u, T v, int dist,bool bidir = true) {

        // For topological sort -> and DAG ->values
        adjList[u].push_back({v, 0});
        // if(bidir)
        // {
        // adjList[v].push_back(make_pair(u,dist));

        // }
    }
    void printGraph(){
        for(auto v:adjList){
            cout<<v.first<<"= ";
            for(auto neigh: v.second){
                cout<<neigh.first<<" -> ";
            }
            cout<<endl;
        }
    }
    void dijikstra_Algo(T src) {

        map<T, int> dist;
        for (auto v : adjList) {
            dist[v.first] = INT_MAX;
        }
        dist[src] = 0;
        // 1st index -> dist
        set<pair<int, T> > s1;
        s1.insert({0, src});

        while (!s1.empty()) {
            auto p = *(s1.begin());
            s1.erase(s1.begin());
            T node = p.second;

            for (auto neigh : adjList[node]) {
                int smallerDist = dist[node] + neigh.second; // Weight of edge ->
                if (smallerDist < dist[neigh.first]) {

                    auto newPairNode = make_pair(dist[neigh.first], neigh.first); // Pair of node and dist
                    if (s1.find(newPairNode) != s1.end()) {
                        s1.erase(newPairNode);
                    }
                    newPairNode.first = smallerDist;
                    s1.insert(newPairNode);
                    dist[neigh.first] = smallerDist;
                }
            }
        }
        for (auto v : adjList) {
            cout << "Dist of " << src << " from " << v.first << " -> " << dist[v.first] << endl;
        }
    }
    void dfsHelperTopologicalSort(T i, map<T, bool> &visited, list<T> &ordering) {
        visited[i] = true;

        for (auto neigh : adjList[i]) {
            if (!visited[neigh.first]) {
                dfsHelperTopologicalSort(neigh.first,visited,ordering);
            }
        }
        ordering.push_front(i);
    }
    // Topological Sort ->
    void dfsTopologicalSort(list<T> &ordering) {

        map<T, bool> visited;
        for (auto i: adjList) {
            if (!visited[i.first]) {
                dfsHelperTopologicalSort(i.first, visited, ordering);
            }
        }
        //Print ordering
    }

    int DagAddEdgeRemainsDag(){
        list<T> ordering;
        dfsTopologicalSort(ordering);
        // int count = 0;
        // for(auto i= ordering.begin(); i != ordering.end(); i++){
        //     for(auto j = i;j!=ordering.end();j++){
        //         if(adjList[*i].find({*j,0}) != adjList[*i].end()){
        //             cout<<*i<<" -> "<<*j<<"  ";
        //         }
        //     }
        //     cout<<endl;
        // }
        for(auto node: ordering){
            cout<<node<<" -> ";
        }
    }
};
// END OF GRAPH 2 
// END OF CLASS
bool compare(int num1, int num2)
{
    // To compare the digits
    string s1 = to_string(num1);
    string s2 = to_string(num2);
    int c = 0;
    if (s1[0] != s2[0])
        c++;
    if (s1[1] != s2[1])
        c++;
    if (s1[2] != s2[2])
        c++;
    if (s1[3] != s2[3])
        c++;

    // If the numbers differ only by a single
    // digit return true else false
    return (c == 1);
}
int shortestPathPrime(int prime1, int prime2) {

    // False -> prime ->
    bool primes[10005];
    memset(primes, true, sizeof(primes));
    for (int i = 2; i * i <= 10000; i++) {
        if (primes[i]) {

            for (int p = i * i; p <= 10000; p += i) primes[p] = false;
        }
    }

    // Prime Vector
    vector<int> primeVector;
    for (int i = 1000; i < 10000; i++)
        if (primes[i])
            primeVector.push_back(i);

    int n = primeVector.size();
    Graph g(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (compare(primeVector[i], primeVector[j]))
                g.addEdge(i, j, true);
        }
    }
    // g.printGraph(primeVector);
    // Find indexes of primes1 and primes2
    int in1, in2;
    for (int i = 0; i < n; i++) {
        if (primeVector[i] == prime1) {
            in1 = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (primeVector[i] == prime2) {
            in2 = i;
            break;
        }
    }

    return g.bfsPrimes(in1, in2);

}
int main() {
    // Graph g(5);
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(0, 3);
    // g.addEdge(1, 3);
    // g.addEdge(2, 3);
    // g.addEdge(1, 4);
    // g.addEdge(2, 4);

    // int s = 0, d = 3;
    // cout << g.countPaths(s, d) << endl;
    // int num1 = 1033, num2 = 8179;
    // cout << shortestPathPrime(num1, num2) << endl;
    Graph2<string> india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Bhopal","Mumbai",3);
    india.addEdge("Delhi","Agra",1);
    india.printGraph();
    // cout<<endl<<"DIJIKSTRA \n";
    // india.dijikstra_Algo("Amritsar");
    india.DagAddEdgeRemainsDag();
    return 0;
}