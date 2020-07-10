//Chefina and Swaps
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr1,arr2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        // Declarations ->
        map<ll,ll> A,B; 
        cin>>n;
        vector<ll> valuesSwapA,valuesSwapB;
        map<ll,bool> visited;
        bool flag = true; 

        ArrIn(n) {
            cin>>arr1;
            A[arr1]++;
        }
        ArrIn(n) {
            cin>>arr2;
            B[arr2]++;
        }

        // cout<<"Print map"<<endl;
        // for(auto i:A){
        //     cout<<i.first<<" -> "<<i.second<<endl;
        // }
        // for(auto i:B){
        //     cout<<i.first<<" -> "<<i.second<<endl;
        // }
        for (auto i: A)
        {
            /* code */
            ll val = i.first;
            ll valueFreqInA = i.second;
            ll valueFreqInB = B.find(val) != B.end() ? B[val]: 0; // Avoid Value Create in Map
            // cout<<valueFreqInB<<"  ->  ";
            visited[val] = true;
            ll sumVal = valueFreqInA+valueFreqInB;
            if((sumVal)&1){
                // cout<<"Freq -> "<<valueFreqInA<<" "<<valueFreqInB<<val<<endl;
                flag = false;
                break;
            }
            else if(valueFreqInA == valueFreqInB) continue;
            else if(valueFreqInA>valueFreqInB){
                ll diff = valueFreqInA - valueFreqInB;
                valuesSwapA.insert(valuesSwapA.begin(),(diff/2),val);
            }
            else{
                ll diff = valueFreqInB - valueFreqInA;
                valuesSwapB.insert(valuesSwapB.begin(),(diff/2),val);
            }
        }
        if(!flag){
            // cout<<"Freq odd A"<<endl;
            cout<<-1<<endl;
            continue;
        }
        else{
            for(auto i: B){
                int val = i.first;
                if(visited[val]) {
                    // cout<<"visited ->>"<<val<<endl;
                    continue;
                }
                ll valueFreqInB = i.second;
                // cout<<"val B -> "<<val<<endl;
                ll valueFreqInA = A.find(val) != A.end() ? A[val]: 0; // Avoid Value Create in Map
                visited[val] = true;
                ll sumVal = valueFreqInA+valueFreqInB;
                if((sumVal)&1){
                // cout<<val<<endl;
                flag = false;
                break;
                }
            else if(valueFreqInA == valueFreqInB) continue;
            else if(valueFreqInA>valueFreqInB){
                ll diff = valueFreqInA - valueFreqInB;
                valuesSwapA.insert(valuesSwapA.begin(),(diff/2),val);
            }
            else{
                ll diff = valueFreqInB - valueFreqInA;
                valuesSwapB.insert(valuesSwapB.begin(),(diff/2),val);
            }
            }
        }
         if(!flag){
            // cout<<"Freq Odd B"<<endl;
            cout<<-1<<endl;
            continue;
        }
        else if(valuesSwapA.size() != valuesSwapB.size()) {
            // cout<<"Size mismatch"<<endl;
            cout<<-1<<endl;
            continue;
        }
        else if(valuesSwapA.size() == 0) {
            cout<<0<<endl;
        }
        else
        {
        //Print Vectors formed ->  ->
        // cout<<"Ans -> Compute\n";
        // for(int i=0;i<valuesSwapA.size();i++){cout<<valuesSwapA[i]<<" ";}
        //     cout<<endl;
        // for(int i=0;i<valuesSwapB.size();i++){cout<<valuesSwapB[i]<<" ";}
        //     cout<<endl;

        int i=0,
            j=0,
            exchangeVal = 0,
            arrSize = valuesSwapA.size();
        ll ans = 0;
        sort(valuesSwapA.begin(),valuesSwapA.end());
        sort(valuesSwapB.begin(),valuesSwapB.end());
        while(exchangeVal<arrSize)
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