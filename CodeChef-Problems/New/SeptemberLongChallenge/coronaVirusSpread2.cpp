// CoronaVirus spread 2
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
                ArrIn(n){
                    // Suppose ith person was affected ->
                    bool hasVirus[7] = {false};
                    hasVirus[i] = true;
                    ll currPosition[7]={0};
                    for(int j=1;j<=n;j++) currPosition[j] = j;
                    ll timeVal = 1;
                    while(timeVal <=100 && notAll(hasVirus,n)){
                        // Increase the position of each player

                        // 1st bool value tells if position visited or not
                        // Second bool -> visited by person was infected or not ->
                        // How many people have visited same position so far ->
                        unordered_map<int,pair<bool,vector<int> > > positionVisited;
                        for(int j=1;j<=n;j++){
                            // Time increasing 1 instance at a time ->
                            currPosition[j]+=arr[j];
                            if(positionVisited.find(currPosition[j]) != positionVisited.end()){
                                // There has been someOne at the position ->
                                auto p = positionVisited[currPosition[j]];
                                if(p.first || hasVirus[j]){
                                    // If virus at the position or person which has come there is infected;
                                    // cout<<"i -> "<<i<<"Here -"<<currPosition[j]<<" -> "<<time<<endl;
                                    hasVirus[j] = true;
                                    // cout<<"Positions -> ";
                                    for(int pos: p.second){
                                        // cout<<pos<<" ";
                                        hasVirus[pos] = true;
                                    }
                                    // cout<<endl;
                                    p.second.push_back(j);
                                    p.first = true;
                                    // Change value in MAP
                                    positionVisited[currPosition[j]] = p;
                                }
                                else{
                                    // cout<<j<<"  Element Pushed -> size ->"<<p.second.size()<<endl;
                                    p.second.push_back(j);
                                    positionVisited[currPosition[j]] = p;
                                }
                                // hasVirus[j] = true;
                            }
                            // Create a vector -> with value of index -> j -> new val
                            else 
                            {  // cout<<"\nnew vector created\n";
                                vector<int> z; z.push_back(j); 
                                positionVisited[currPosition[j]] = {hasVirus[j],z};
                            }
                        }
                        timeVal++;
                    }
                    ll infectedPeople = 0;
                    for(int val=1;val<=n;val++){
                        //cout<<val<<" infected -> "<<hasVirus[val];
                        if(hasVirus[val]) infectedPeople++;
                    }
                    //cout<<endl;
                      // Check for MIN AND MAX VAL;
                      minVal = min(minVal,infectedPeople);
                      maxVal = max(maxVal,infectedPeople); 
                }
                cout<<minVal<<" "<<maxVal<<endl;}
    }
    return 0;
}    