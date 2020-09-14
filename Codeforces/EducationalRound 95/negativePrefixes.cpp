// Negative Prefixes
#include<bits/stdc++.h>
#define ll long long int
// #define int long long int 
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
int t,n;
int arr[200005];
void maxVal(int*arr,int*positionfixed,int i,int n){
    if(i==n){
        return;
    }
    int j;
    for(j=i+1;j<n;j++) 
        if(!positionfixed)
            break;
    maxVal(arr,positionfixed,j,n);
    // check for correct position of j
    int minVal = INT_MAX;
    for(int m=j;m<n;m++){
        calSum(arr,n);
        while(j+1<n && !positionfixed[j+1]) j++;
        swap(arr[j],arr[j+1]);
        
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        bool positionfixed[102];
        cin>>n;
        map<int,int> freePositions;
        vector<int> values;
        ArrIn(n) cin>>arr[i];
        ArrIn(n) {
            cin>>positionfixed[i];
            if(!positionfixed){
                values.push_back(arr[i]);
                freePositions[arr[i]] = i;
            }
        }
        sort(values.begin(),values.end());
        int m=values.size()-1;
        for(int i=0;i<n;i++){
            if(sum<0 && !positionfixed[i]){
                // If position available ->
            // for(int j=0;j<n;j++){
            //     if(!positionfixed[j]){
            //         swap(arr[i],arr[j]);
            //         ll sum=0;
            //         ll cnt=0;
            //         for(int k=0;k<n;k++){
            //             // SUm of Array ->
            //             sum+=arr[k];
            //             if(sum<0) cnt++;
            //         }
            //         if(maxVal>cnt){
            //             maxVal = cnt;
            //             ans.clear();
            //             for(int l=0;l<n;l++) ans.push_back(arr[l]);
            //         }
            //         swap(arr[i],arr[j]);
            //     }
            // }

            }
            sum+=arr[i];
        }
        if(maxVal != INT_MAX)
        {for(int i=0;i<n;i++){
                    cout<<ans[i]<<" ";
                }
            }
            else{
                ArrOut(n);
            }
        cout<<endl;
    }
    return 0;
}    