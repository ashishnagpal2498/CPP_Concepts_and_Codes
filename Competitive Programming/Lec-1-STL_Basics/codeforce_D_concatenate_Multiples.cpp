//Codeforce - D.Concatenated Multiples
// x* 100 = (k - 45%k)%k;
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[200005];
ll n,k;
map<ll , ll> val[10];
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        ll count=0;
    // First approach -  storing all the pairs of values - 
    // map<long long int, list<long long int> > val[10];

    // Second approach - storing the number as we need count only-
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
        // auto it = (val[zeros]).find(findOut);
        // if(it != val[zeros].end())
        // count += (*it).second; 
        count += val[zeros][findOut];
        //Subtract conditions in which - number is concat with itself
        ll po = 10;
        for(ll i=0;i<zeros;i++) po*=10;
        ll ab =  ((arr[i]%k)*(po%k))%k;   
        if( ab == findOut) count--;    
    }
    cout<<count<<endl;
    return 0;
}