// Array Cancellation
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
        ArrIn(n) cin>>arr[i];
        int positiveIndex =0,negativeIndex = n-1;
        while(positiveIndex<n && arr[positiveIndex]<=0) positiveIndex++;
        while(negativeIndex>positiveIndex && arr[negativeIndex]>=0) negativeIndex--;    
        while(positiveIndex<negativeIndex)
        {
            // make free move ->
            while(positiveIndex<negativeIndex &&arr[positiveIndex] == 0) positiveIndex++;
            while(negativeIndex>positiveIndex && arr[negativeIndex] == 0) negativeIndex--; 

            ll minVal = min(arr[positiveIndex],-1*arr[negativeIndex]);
            if(minVal>0)
            {   arr[positiveIndex]-=minVal;
                arr[negativeIndex]+=minVal;
            }
            else{
                arr[positiveIndex]+=minVal;
                arr[negativeIndex]-=minVal;
            }
            if(arr[positiveIndex] == 0) positiveIndex++;
            if(arr[negativeIndex] == 0) negativeIndex--;
        }
        ll sum=0;
        ArrIn(n){
            if(arr[i]>0) sum+=arr[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}    