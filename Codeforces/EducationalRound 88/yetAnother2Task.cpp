// Alice and bob Game
// Not Solved ------ 

#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int j=0;
    ll maxSoFar=0,maxVal=0,maxInSubArray=INT_MIN,minVal = INT_MIN;
    int count =0,m=0;
    priority_queue<ll> ans;
    while(j<n)
    {
        maxSoFar+= arr[j];
        if(maxSoFar<=0)
        {
            maxSoFar = 0;
            // Stopage - check for ans -
            if(j-1 >= 0 && arr[j-1]>0)
            {   ll localMax = INT_MIN,sum=0;
                for(int i=m;i<j;i++){
                // find local max -
                sum+=arr[i];
                localMax = max(localMax,arr[i]);
                }
                ans.push(sum-localMax);
            }
            m=j+1;
            minVal = max(minVal,arr[j]);
            count++;
        }
        if(maxVal<maxSoFar) {
            maxVal = maxSoFar;
            maxInSubArray = max(maxInSubArray,arr[j]);
        }
        j++;
    }
    if(count == n){
        //ALL numbers are negative - 
        cout<<0<<endl;
    }
    else if(count ==0){
        cout<< maxVal- maxInSubArray<<endl; 
    }
    else{
       ll localMax = INT_MIN,sum=0;
            for(int i=m;i<j;i++){
                // find local max -
                sum+=arr[i];
                localMax = max(localMax,arr[i]);
            }
            if(localMax!= INT_MIN) ans.push(sum-localMax);
            cout<<max(ans.top(),maxVal-maxInSubArray)<<endl;
    }
    return 0;
}    