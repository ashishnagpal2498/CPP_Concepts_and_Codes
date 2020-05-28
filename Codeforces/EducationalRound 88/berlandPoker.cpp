// Berland Poker
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t,n,m,k; // k players
// ll arr[200005];
ll maxPoints(){
    if(m==0) return 0;
    ll noOfCards,remainingJoker;
    noOfCards = n/k;
    if(noOfCards>=m) return m;
    //
    ll noOfPoints = noOfCards; // No of points so far by player
    remainingJoker = m - noOfCards;
    // Divide the remaining jokers equally among players;
    ll noOfJokersEqually = (remainingJoker/(k-1));
    remainingJoker -= (noOfJokersEqually*(k-1));
    if(remainingJoker>0){
            noOfPoints = noOfPoints - (noOfJokersEqually+1);
    }
    else noOfPoints-= noOfJokersEqually;
    return noOfPoints;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cout<<maxPoints()<<endl;
    }
    return 0;
}    