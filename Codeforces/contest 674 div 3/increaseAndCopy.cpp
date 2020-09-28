// Increase And Copy
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
        cin>>n;
        ll copies = n;
        ll val = 1;
        ll minVal = INT_MAX;
        while(val*val<=n+1){
            ll divide = n/val;
            if(n%val != 0) divide++;
            minVal = min({minVal,divide+(val-2)});
            val++;
        }
        if(minVal == INT_MAX) minVal = 0;

        cout<<minVal<<endl;
    }
    return 0;
}