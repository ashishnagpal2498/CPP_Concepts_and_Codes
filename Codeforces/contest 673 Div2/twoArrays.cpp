//B. Two Arrays
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t, n,k;
ll arr[200005];
int main()
{           ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>k;
        map<ll,ll> values;
        map<int,priority_queue<ll,vector<ll>,greater<ll> > > indexes;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            values[arr[i]]++;
            // Need corresponding Index ->
            indexes[arr[i]].push(i);
        }
        int i=0;
        map<ll,ll> aVals,bVals;
        vector<int> ans(n);
        while(i<n){
            // cout<<arr[i]<<" -> "<<arr[j]<<endl;
            ll val = k - arr[i];
            if(values.find(arr[i]) != values.end() && values[arr[i]]>0 && values.find(val) != values.end() && values[val] >0){
                    // saare arr[i] consume nahi huye and uski counter value present hai;
                // Check konse map mein bhejun ->
                if(aVals[val]<=bVals[val]){
                        aVals[arr[i]]++;
                        ans[i] = 1;
                }
                else{
                    bVals[arr[i]]++;
                    ans[i] = 0;
                }
                if(aVals[arr[i]]<=bVals[arr[i]]){
                   aVals[val]++;
                    //  Index ??
                        ans[indexes[val].top()] = 1;
                }
                else{
                    bVals[val]++;
                    ans[indexes[val].top()] = 0;
                }    
                values[arr[i]]--;
                values[val]--;
                indexes[arr[i]].pop();
                 indexes[val].pop();
                 i++;
            }
            else if(values.find(arr[i]) != values.end() && values[arr[i]]>0 && values.find(val) == values.end()){
                // Check konse map mein bhejun ->
                      
                    if(aVals[val]<=bVals[val]){
                        aVals[arr[i]]++;
                        ans[i] = 1;
                }
                else{
                    bVals[arr[i]]++;
                    ans[i] = 0;
                }
                values[arr[i]]--;
                indexes[arr[i]].pop();
                i++;
            }
            else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/* 
if(arr[i] +arr[j] == k){
                aVals[arr[i]] = true;
                bVals[arr[j]] = true;
                arr[i++] = 1;
                arr[j--] = 0;
            }
            else if(arr[j] <= k){
                // cout<<"Here ->";
                if(aVals.find(k-arr[j]) == aVals.end()){
                        aVals[arr[j]] = true;
                        arr[j--] = 1;
                }
                else{
                    bVals[arr[j]] = true;
                    arr[j--] = 0;
                }
            }
            else if(arr[i]<=k){
                    if(aVals.find(k-arr[i]) == aVals.end()){
                        aVals[arr[i]] = true;
                        arr[i++] = 1;
                }
                else{
                    bVals[arr[i]] = true;
                    arr[i++] = 0;
                }
            }
            else{
             j--;   
            }
        if(n&1 && aVals.find(k-arr[i]) == aVals.end()){
                arr[i] = 1;
        }
        else{
            arr[i] = 0;
        }
*/