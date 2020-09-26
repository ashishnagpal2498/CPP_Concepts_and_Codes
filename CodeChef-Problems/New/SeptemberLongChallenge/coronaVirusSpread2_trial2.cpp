// CoronaVirus Spread 2 trial 2
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=1;i<=n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[7];
bool notAll(bool *hasVirus,int n){
    for(int i=1;i<=n;i++){
        if(!hasVirus[i]) return true;
    // Sabko virus nahi hua hai abhi ->
    }
    return false;
    // Sabko virus ho chuka hai ->
}
void dfsHelper(ll node,unordered_map<int,bool>&visited,vector<vector<ll> >&graph,ll &noOfNodes){
    visited[node] = true;
    noOfNodes++;
    for(ll v=1;v<=n;v++){
        if(graph[node][v] == 1 && !visited[v]){
            dfsHelper(v,visited,graph,noOfNodes);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        bool allEq = true;
        ll prevVal = -1;
        cin>>n;
        ArrIn(n) {
            cin>>arr[i];
            if(prevVal == -1) prevVal = arr[i];
            if(prevVal != arr[i]) allEq = false;
        }
        if(allEq){
            // Checked ->
            cout<<1<<" "<<1<<endl;
        }
        else{
                ll minVal = INT_MAX,maxVal = INT_MIN;   
                ll currPosition[7]={0};
                for(int j=1;j<=n;j++) currPosition[j] = j;
                ll timeVal = 1;
                vector<vector<ll> > graph(6,vector<ll>(6,0)); // 6*6 matrix ->
                while(timeVal <=100){
                    // ll localMax= INT_MIN, localMin = INT_MAX;
                        // first gives the positon value , second-> index 1
                    unordered_map<ll,ll> positionIndex;
                    for(int j=1;j<=n;j++){
                        // Time increasing 1 instance at a time ->
                        // THIS ENSURES PEOPLE MEETING AT SAME POSITION ->
                        currPosition[j]+=arr[j];
                        if(positionIndex.find(currPosition[j])!= positionIndex.end()){
                            ll index1st = positionIndex[currPosition[j]];
                            graph[index1st][j] = 1;
                        }
                        positionIndex[currPosition[j]] = j;
                        // localMin = min(localMin,positionFreq[currPosition[j]]);
                        // localMax = max(localMax,positionFreq[currPosition[j]]);
                    }
                    timeVal++;
                  // Check for MIN AND MAX VAL; 
                }
                // for(int a=1;a<=n;a++){
                //     for(int b=1;b<=n;b++){
                //         cout<<graph[a][b]<<" ";
                //     }
                //     cout<<endl;
                // }
                // Connected Component and Nodes in that component
                unordered_map<int,bool> visited;
                for(ll node=1;node<=n;node++){
                    ll noOfNodes = 0;
                    if(!visited[node]){
                        dfsHelper(node,visited,graph,noOfNodes);
                        minVal = min(minVal,noOfNodes);
                        maxVal = max(maxVal,noOfNodes);
                    }
                }
                cout<<minVal<<" "<<maxVal<<endl;
            }
        }
    return 0;
}    