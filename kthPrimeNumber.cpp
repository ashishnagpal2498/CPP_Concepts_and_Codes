//Kth Prime number -
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
ll arr[5000005];
void primeCal()
{   arr[1] = 2;
    arr[2] =3;
    ll m=3;
    for(ll i=5;i<5000005;i+=2)
    {   bool isPrime = true;
        for(ll j=2; j*j<=i;j++)
        {
            if(i%j==0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime) arr[m++] = i;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    primeCal();
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<arr[n]<<endl;
    }
    return 0;
}    