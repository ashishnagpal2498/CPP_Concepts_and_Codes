//Permutation and indices
// Three indices ->
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
        int index1=-1,index2=-1,index3=-1;
        for(int i=0;i<n-1;i++){
            if(arr[i]>=arr[i+1]) continue;
            index1 = i;
            index2 = i+1;
            for(int j=index2+1;j<n;j++){
                if(arr[index2]>arr[j]) {
                    index3 = j;
                    break;
                }
            }
            if(index3 != -1){
                cout<<"YES"<<endl;
                cout<<index1+1<<" "<<index2+1<<" "<<index3+1<<endl;
                break;
            }
        }
        if(index3 == -1){
            cout<<"NO"<<endl;
        }    
    }
    return 0;
}    