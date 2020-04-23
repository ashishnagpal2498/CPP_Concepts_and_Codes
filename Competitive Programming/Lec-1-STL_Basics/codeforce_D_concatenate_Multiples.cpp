//Codeforce - D.Concatenated Multiples
// x* 100 = (k - 45%k)%k;
#include<iostream>
#include<map>
#include<list>
#define ll long long int
using namespace std;
ll arr[100005];
int main()
{
    ll n,k;
    // First approach -  storing all the pairs of values - 
    // map<long long int, list<long long int> > val[10];

    // Second approach - storing the number as we need count only-
    map<ll , ll> val[10];
    cin>>n>>k;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
       ll p=10;
        for(ll j=0;j<10;j++,p*=10)
        {   ll v = (arr[i]*p)%k;
            // Approach 1 -
            // val[j][v].push_back(i);

            //Approach 2 -
            val[j][v]++;
            // cout<<v<<" ";
        }
        // cout<<endl;
    }

    // cout<<"Array of val "<<endl;
    // for(int i=0;i<10;i++)
    // {
    //     for(auto v: val[i])
    //     {   for(auto a: v.second)
    //         {cout<<a<<" ";}
    //     }
    //     cout<<endl;
    // }
    
    ll count=0;
    for(ll i=0;i<n;i++)
    {   ll zeros = -1;
        ll a = arr[i];
        // while(a)
        // {
        //     a = a/10;
        //     zeros++;
        // }
        // cout<<"Zeros "<<zeros<<endl;
        while(a,zeros++,a/=10);

        ll findOut = (k - (arr[i]%k))% k;
        // int v = (k - (arr[i]%k))% k;
        //Approach 1- 
        // cout<<"v is "<<v<<endl;
        // auto it = val[zeros].find(v);
        // if(it != val[zeros].end())
        //  {    
        //  for(auto value : (*it).second)
        //     {   if(i!=value)
        //         { 
        //             // cout<<i<<" "<<value<<" ";
        //             count++;
        //     }
        //     }
        // }
        // cout<<endl;

        // Approach 2 -
        //there will be atleast 1 value or it is zero by default
        count += val[zeros][findOut]; 
        //Subtract conditions in which - number is concat with itself
        ll po = 10;
        for(ll i=0;i<zeros;i++) po*=10;
        if((arr[i]*po)%k == findOut) count--;    
    }
    cout<<count<<endl;
    return 0;
}