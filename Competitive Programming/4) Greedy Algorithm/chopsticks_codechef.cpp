// Chopsticks - Maximum difference - D
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n,d;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>d;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int i=0,j=1;
    ll count=0;
    map<ll,bool> visited;
    while(i<n && j<n)
    {
        if(arr[j]-arr[i]<=d&&i!=j&&!visited[i])
        {
            count++;
            visited[i] = true;
            visited[j] = true;
            i++;

        }
        else if(i==j){
            j++;
        }
        else{
            i++;
        }
    }
    cout<<count<<endl;
    return 0;
}    