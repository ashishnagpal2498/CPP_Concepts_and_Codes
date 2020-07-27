// SubArray sum that is not divisible by x
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t,n,x;
ll arr[200005];
void countSubArrays()
{
    ll count = -1;
    pair<ll,ll> pq = {INT_MIN,INT_MIN};
    vector<ll> subarr(n);
    vector<ll> ans;
     int nsize = 0;
    for(int mask=0; mask < (1<<n) ; mask++)
    {   if(__builtin_popcount(mask)>=2)
        {  
            int i=0;
              nsize = 0;
               ll sum =0;
                ll length=0;
                int prevElement = -1;
                while(i<n)
                {
                    if((1<<i)&mask){
                        subarr[nsize++] = arr[i];
                        if(prevElement != -1) {
                        sum+=(abs(prevElement-arr[i]));
                        prevElement = arr[i];
                        }
                        else{
                            prevElement = arr[i];
                        }
                    }
                    i++;
                }
               if(pq.first == INT_MIN)
               {
                    pq.first = sum;
                    ans = subarr;
                    pq.second = nsize;
               }
               else if(pq.first < sum)
               {
                    pq.first = sum;
                    ans = subarr;
                    pq.second = nsize;
               }
               else if(pq.first == sum && pq.second >= nsize)
               {    ans = subarr;
                    pq.second = nsize;
               } 
            }

    }
    cout<<pq.second<<endl;
    for(int i=0;i<pq.second;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
        countSubArrays();
    }
    return 0;
}    