#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;

int main()
{   ll arr[5];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {   cin>>n;
        for(int i=0;i<5;i++) arr[i] = -1;
        ll p = 1;
        int lenNum = 0,i=0;
        while(n)
        {   ll digit = n%10;
            if(digit != 0) {lenNum++;arr[i] = digit*p;}
            n/=10;
            p*=10;
            i++;
        }
        cout<<lenNum<<endl;
        for(int i=0;i<5;i++)
        {
            if(arr[i]!= -1) {cout<<arr[i]<<" ";}
        }    
        cout<<endl;
    }
}