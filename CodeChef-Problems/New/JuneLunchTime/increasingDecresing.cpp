//Increasing and decreasing ->
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
    while(t--)
    {
        cin>>n;
        vector<ll> arr2,arr3;
        for(int i=0;i<n;i++) cin>>arr[i];    
        sort(arr,arr+n);
        int i=0,j=n-1;
        bool flag= false,ans = true;
        while(i<n)
        {   // Peak point ->
            if(i+1<n && arr[i]==arr[i+1])
            {
                arr2.push_back(arr[i++]);
                arr3.push_back(arr[i++]);
            }
            else if(arr2.size() > 0 && arr[i] == arr2[arr2.size()-1]){
                cout<<"Here\n";
                ans = false;
                break;
            } 
            else{
                arr2.push_back(arr[i]);
                i++;
            }
            //if(arr[i] == arr[i-1]){
           //      swap(arr[i],arr[j]);
           //      j--;
           //  }
           // else if(i+1<n && arr[i]>arr[i+1] && !flag){
           //      swap(arr[i],arr[i+1]);
           //      i++;
           //  }
           //  else if(flag && arr[i]<=arr[i+1]){
           //      ans = false;
           //      break;
           //  }
           //  else{
           //      i++;
           //  }
        }
        if(ans && (arr2[arr2.size()-1] != arr3[arr3.size()-1] || arr3.size()!=0) ){
            // cout<<"Flag "<<flag<<endl;
            cout<<"YES\n";
            for(i=0;i<arr2.size();i++){
                cout<<arr2[i]<<" ";
            }
           
            for(i=arr3.size()-1;i>=0;i--){
                cout<<arr3[i]<<" ";
            }
            cout<<endl;
        }
        else{
            
            cout<<"NO"<<endl;
        }
    }
    return 0;
}    