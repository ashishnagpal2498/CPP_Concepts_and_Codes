//Chef and Recipe 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
bool isChefsRecipe()
{
    map<ll,ll> element;
    ll prevElement = INT_MIN;
    for(int i=0;i<n;i++)
    {
        auto value = element.find(arr[i]);
        // Vo element phele aaya hi nahi hai
        if(value == element.end())
        {
            element[arr[i]]++;
        }
        else if(arr[i-1] == arr[i])
        {
            element[arr[i]]++;
        }
        else{
            return false;
        }
    }
    map<ll,bool> visited;
    for(auto i:element)
    {
        if(!visited[i.second])
        {
            visited[i.second] = true;
        }
        else{
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        bool ans = isChefsRecipe();
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";    
    }
    return 0;
}    