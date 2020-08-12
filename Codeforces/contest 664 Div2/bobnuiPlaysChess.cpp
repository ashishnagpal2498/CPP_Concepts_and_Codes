//Bobnui Plays 
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,m,Sx,Sy;
ll arr[200005];
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cin>>n>>m>>Sx>>Sy;
    ll i=0,size = n*m;
    map<string,bool> visited;
    // Sx--; Sy--;
    // make it reach to corner ->
    // cout<<"Hello \n"<<endl;
    string v = ""; v+=to_string(Sx); v+=to_string(Sy);
    // cout<<v<<endl;
    visited[v] = true;
    cout<<Sx<<" "<<Sy<<endl;
    i++;
    while(Sx-1>=1) Sx--;
       string l = ""; l+=to_string(Sx); l+=to_string(Sy);
    if(!visited[l]){
        // Not same position as above ->
        visited[l] = true;
        cout<<Sx<<" "<<Sy<<endl;
        i++;
    }
    while(Sy-1>=1) Sy--;
      string o = ""; o+=to_string(Sx); o+=to_string(Sy);
    if(!visited[o]){
        visited[o] = true;
        cout<<Sx<<" "<<Sy<<endl;
        i++;   
    }
    bool goRight = true;
    while(i<size){
        int yVal = Sy;
        if(goRight)
        {
            while(yVal <= m){
                      string  v = ""; v+=to_string(Sx); v+=to_string(yVal);
                         // cout<<" ->  "<<v<<endl;
                       if(!visited[v]) {
                        visited[v] = true;
                        Sy = yVal;
                        cout<<Sx<<" "<<Sy<<endl;
                        i++;
                        break;
                    }
                    yVal++;
                if(yVal == m+1) { goRight = false; Sx++; break;}
                }
        }
        else {
            while(yVal >= 1){
                     string  v = ""; v+=to_string(Sx); v+=to_string(yVal);
                     // cout<<" v->"<<v<<endl;
                       if(!visited[v]) {
                        visited[v] = true;
                        Sy = yVal;
                        cout<<Sx<<" "<<Sy<<endl;
                        i++;
                        break;
                    }
                       yVal--;
                if(yVal == 0) {goRight = true; Sx++; break;}
                }
        }

    }
    return 0;
}    