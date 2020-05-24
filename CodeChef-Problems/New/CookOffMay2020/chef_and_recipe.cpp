// Chef and recipe 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
bool elementsExist(ll*arr,ll*uniqueArr,ll start,ll end)
{   for(int j=0;j<1005;j++)
    {
        if(uniqueArr[j]==1)
        {   //cout<<"j is "<<j<<endl;
            ll s= start,c=0; // c is count;
            while(s<end)
            {   if(arr[s]==j) c++;
                s++;
            }
            if(c==0 || c>1) return false;
        }
    }
    return true;
}
bool findSubArray(ll* arr,ll* uniqueArr,ll uniqueCount)
{
    // for (int startPoint = 0; startPoint <n ; startPoint++) {
    //         //group sizes
    //         for (int grps = startPoint; grps <=n ; grps++) {
    //             if(grps - startPoint == uniqueCount&&elementsExist(startPoint,grps))
    //             {return true;
    //             }

    //         }
    //          cout<<endl;
    //         }
    //     }
    for(int i=0;i < (n-(uniqueCount));i++)
    {   //cout<<"i value - "<<i<<" ";
        // cout<<"value - "<<i<<" "<<(n-(uniqueCount-1));
        if(elementsExist(arr,uniqueArr,i,i+uniqueCount))
        {  
            return true;
        }
    }
    return false;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cin>>t;
    while(t--)
    {   ll uniqueCount = 0;
        ll arr[1005];
    ll uniqueArr[1005]={0};
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(!uniqueArr[arr[i]]){
                uniqueCount++;
                uniqueArr[arr[i]]++;
            }
        }
         // cout<<"Unique elements "<<uniqueCount<<endl;
         // for(int i=0;i<10;i++){cout<<i<<" -> "<<uniqueArr[i]<<"\n";}
        bool ans = findSubArray(arr,uniqueArr,uniqueCount);
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}    