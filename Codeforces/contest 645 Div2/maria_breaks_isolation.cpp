// Maria breaks the self isolation Codeforce
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        //Create contigous subset -
        ll grannyPresent = 0;
        for(int i=0;i<n;)
        {
            // subset -- grouping
            int j =0; 
           while((i+1<n) && (arr[i+1+j]-arr[i+j]<=1))
           {    //Assume - vo granny aa gai -
                grannyPresent++;
                j++;
           }
           i+=j;
        }
        cout<<grannyPresent<<endl;
    }
    return 0;
}    