//Chefina and Swaps
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr1[200005],arr2[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        map<ll,ll> A,B; 
        cin>>n;
        ArrIn(n) {
            cin>>arr1[i];
            A[arr1[i]]++;
        }
        ArrIn(n) {
            cin>>arr2[i];
            B[arr2[i]]++;
        }
        vector<ll> valuesSwapA,valuesSwapB;
        map<ll,bool> visited;
        bool flag = true; 
        for (auto i: A)
        {
            /* code */
            ll val = i.first;
            ll valueFreqInA = i.second;
            ll valueFreqInB = B[val];
            visited[val] = true;
            if((valueFreqInA+valueFreqInB)&1){
                flag = false;
                break;
            }
            else if(valueFreqInA == valueFreqInB) continue;
            else if(valueFreqInA>valueFreqInB){
                int diff = valueFreqInA - valueFreqInB;
                valuesSwapA.insert(valuesSwapA.begin(),(diff/2),val);
            }
            else{
                int diff = valueFreqInB - valueFreqInA;
                valuesSwapB.insert(valuesSwapB.begin(),(diff/2),val);
            }
        }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }
        else{
            for(auto i: B){
                int val = i.first;
                if(visited[val]) continue;
                ll valueFreqInB = i.second;
            ll valueFreqInA = A[val];
            visited[val] = true;
            if((valueFreqInA+valueFreqInB)&1){
                flag = false;
                break;
            }
            else if(valueFreqInA == valueFreqInB) continue;
            else if(valueFreqInA>valueFreqInB){
                int diff = valueFreqInA - valueFreqInB;
                valuesSwapA.insert(valuesSwapA.begin(),(diff/2),val);
            }
            else{
                int diff = valueFreqInB - valueFreqInA;
                valuesSwapB.insert(valuesSwapB.begin(),(diff/2),val);
            }
            }
        }
         if(!flag){
            cout<<-1<<endl;
            continue;
        }
        else if(valuesSwapA.size()!= valuesSwapB.size()) {cout<<-1<<endl;}
        else if(valuesSwapA.size() == 0) {cout<<0<<endl;}
        else
        {
        cout<<"Ans -> Compute\n";
        for(int i=0;i<valuesSwapA.size();i++){cout<<valuesSwapA[i]<<" ";}
            cout<<endl;
        for(int i=0;i<valuesSwapB.size();i++){cout<<valuesSwapB[i]<<" ";}
            cout<<endl;
        int i=0,j=0;
        int exchangeVal = 0;
        ll ans = 0;
        sort(valuesSwapA.begin(),valuesSwapA.end());
        sort(valuesSwapB.begin(),valuesSwapB.end());
        while(exchangeVal<valuesSwapA.size())
        {   // if array A has smaller element ->
            if(valuesSwapA[i]<valuesSwapB[j]){
                ans+=(valuesSwapA[i]);
                i++;
            }
            else{
                ans+=(valuesSwapB[j]);
                j++;
            }
            exchangeVal++;
        }
        cout<<ans<<endl;
        }
    }
    return 0;
}    