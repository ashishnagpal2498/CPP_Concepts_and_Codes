// Spoj - Game3
#include<bits/stdc++.h>
 #define ll long long int
 #define endl "\n"
 #define ArrIn(n) for(int i=0;i<n;i++)
 #define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
 #define mod 1e9+7

 using namespace std;
 ll t,n;
 ll arr[200005]={0};
 int main()
 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>t;
     while(t--){
        cin>>n;
        arr[n] = 1;
        for(int i=n-1;i>=1;i--){
            ll plus1 = i+1, multi2= i*2;
            if(multi2<=n && arr[multi2] == 1 && arr[plus1] == 1 ) arr[i] = 0;
            else if((multi2<=n && arr[multi2] == 0) || arr[plus1] == 0 ) arr[i] = 1;
            else if(arr[plus1] == 1) arr[i] =0;
        }
        // for(int i=1;i<=n;i++) {
        //     cout<<i<<" state -> "<<arr[i]<<endl;
        // }
        if(arr[1] == 0){
            cout<<"Marica"<<endl;
        }
        else{
            cout<<"Ivica"<<endl;
        }
     }    
     return 0;
 }     