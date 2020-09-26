// rating and ranking
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        int initialRating[502],minRankingRound[502],maxRatingRound[502];
        int ratings[501][501];
        cin>>n>>m;
        ArrIn(m) {maxRatingRound[i] = INT_MIN; minRankingRound[i]= INT_MAX;}
        ArrIn(n) cin>>initialRating[i];
        ArrIn(n){
            for(int j=0;j<m;j++){
                cin>>ratings[i][j];
                if(j == 0){
                    ratings[i][j] = initialRating[i] + ratings[i][j];
                }
                else{
                    ratings[i][j] = ratings[i][j-1] + ratings[i][j];
                }
                // Jth round ->>
                if(maxRatingRound[i] == INT_MIN) maxRatingRound[i] = j;
                else {
                    if(ratings[i][maxRatingRound[i]] < ratings[i][j] ) maxRatingRound[i] = j;
                }
            }
        }
        // Max rating for each player
        cout<<"Max Rating for players"<<endl;
        for(int i=0;i<n;i++){
            cout<<"Rating -> "<<ratings[i][maxRatingRound[i]]<<"Round -> "<<maxRatingRound[i]<<"\n";
        }
        cout<<endl;
        // Ith round  -> 
        for(int i=0;i<m;i++){
            priority_queue<pair<int,int> > values;
            for(int j=0;j<n;j++){
                // Player - ith -> Round ->
                // cout<<"Player -> "<<j+1<<" Rating -> "<<ratings[j][i]<<endl;
                values.push(make_pair(ratings[j][i],j));
            }
            int position = 0;
            int prevVal = INT_MIN;
            // rating to ranking ->>>>>>>
            while(!values.empty()){
                auto val = values.top();
                values.pop();
                if(val.first == prevVal){
                    // round -> ith , which person ->
                    ratings[val.second][i] = ratings[val.second-1][i];
                    position++;
                }
                else{
                    position++;
                    ratings[val.second][i] = position;
                    prevVal = val.first; 
                }
                // cout<<"Ranking  -> "<<
            }
            // cout<<endl;

            // ith round ->>>>>>>
            for(int l=0;l<n;l++){
                if(minRankingRound[l] == INT_MAX) minRankingRound[l] = i;
                else{
                    // ranking ->>>>>
                    if(ratings[l][minRankingRound[l]] > ratings[l][i]) minRankingRound[l] = i;
                }
            }
        }
        // cout<<"Min Ranking for players"<<endl;
        for(int i=0;i<n;i++){
            cout<<"Player -> "<<i<<" Round -> "<<minRankingRound[i]<<" "<<ratings[i][minRankingRound[i]]<<"\n";
        }
        cout<<endl;
        int ans =0;
        for(int i=0;i<n;i++){
            if(minRankingRound[i] != maxRatingRound[i]) ans++;
        }
        cout<<ans<<endl;
    }   
    return 0;
}    