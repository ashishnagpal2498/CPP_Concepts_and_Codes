#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
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
        int freq[11]={0};
        ArrIn(n)
        {cin>>arr[i];
            freq[arr[i]]++;
        }
        int index = -1;
        int maxVal = INT_MIN;
        map<int,int> v;
        ArrIn(11){
            if(freq[i] != 0)
            v[freq[i]]++;
        }

        for(auto i:v)
        {  if(i.second>maxVal){
            maxVal = i.second;
            index = i.first;
        } 
    }
    cout<<index<<endl;
    }
    return 0;
}    