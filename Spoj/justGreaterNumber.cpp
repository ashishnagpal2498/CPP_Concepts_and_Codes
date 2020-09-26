// Just Greater Number -> 

#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[2000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        bool allSame = true;
        ll prev = -1;
        ll noOfZeros = 0;
        ArrIn(n){
            cin>>arr[i];
            prev == -1 ? arr[i]: prev;
            arr[i] == 0 ? noOfZeros++ : 0;
            allSame = prev != arr[i] ? false: allSame;  
        }
        if(allSame || noOfZeros == n || (noOfZeros == n-1 && arr[0]!=0)) {
            cout<<-1<<endl;
        }
        else if(noOfZeros == n-1){
            int index = -1;
            for(int i=0;i<n;i++){
                if(arr[i]!=0){
                    index = i;
                    break;
                }
            }
            swap(arr[index],arr[index-1]);
            ArrOut(n);
            cout<<endl;
        }
        else{
            // 
            int m=0;
            while(true)
            {int swapVal = 0;
             int i=n-1-m;
                m++;
                while(i<n-1){
                    if(arr[i]<arr[i+1]) {swap(arr[i],arr[i+1]); swapVal++;}
                    i++;
                    }
            if(swapVal) break;
            }
            ArrOut(n);
            cout<<endl;
        }
    }    
    return 0;
}    