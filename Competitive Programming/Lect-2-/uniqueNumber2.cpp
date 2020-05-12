// Unique Number 2
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int zorVal = 0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        zorVal^=arr[i];
    }
    //Now I have zor 
    return 0;
}    