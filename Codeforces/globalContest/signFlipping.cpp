// sign flipping 
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++) cin>>arr[i]
#define ArrOut for(int i=0;i<n;i++) 
{
    cout<<arr[i]<<" "; 
}
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        ArrIn(n);
        vector<pair<int,int> > neg,pos,zeros;
        for(int i=1;i<n;i++){
            int val = arr[i] - arr[i-1];
            if(val>0){
                pos.push_back(make_pair(i,i-1));
            }
            else if(val<0){
                neg.push_back(make_pair(i,i-1));
            }
            else{
                zeros.push_back(make_pair(i,i-1));
            }
        }
        int negSize = neg.size(), zerosSize = zeros.size(),posSize = pos.size();
        if(negSize == 0 && posSize == 0 ){
            ArrOut;
            cout<<endl;
        }
        else if(zerosSize == 0 &&  negSize == posSize){
            //same array print-
            ArrOut;
            cout<<endl;
        }
        else if(negSize>posSize){
            if(posSize+zerosSize == negSize){
                ArrOut;
            }
            // Negative values are more ->>
            // Change no. of values from negative to positive ->
            int valChange = negSize - (posSize+zerosSize);
            
        }
        else {
            if(posSize == negSize + zerosSize){
                ArrOut;
                cout<<endl;
            }
            
        }
    }    
    return 0;
}    