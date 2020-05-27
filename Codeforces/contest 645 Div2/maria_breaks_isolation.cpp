// Maria breaks the self isolation Codeforce
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
bool isTrue(ll val,ll s,ll e)
{   cout<<"Start value - "<<s<<" End Value "<<e<<" Value "<<val<<endl;
    while(s<e)
    {   
        if(arr[s]>=val) return false;
        s++;
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
        sort(arr,arr+n);
        //Create contigous subset -
        ll grannyPresent = 0;
      
        if(arr[0]!=1 && arr[0] != arr[1]) cout<<1<<endl;
        else
        {   for(int i=0;i<n;i++)
            {   ll localGroupingValue =0;
            // subset -- grouping
            int j =0; 
           while((i+1+j<n) && (arr[i+1+j]-arr[i+j]<=1))
           {    //Assume - vo granny aa gai -
                localGroupingValue++;
                j++;
           }
           if(j!=0 && isTrue((localGroupingValue)+grannyPresent,i,i+j)) 
            {   cout<<"Here"<<endl;
                grannyPresent+=localGroupingValue;

            }
            else break;
           i+=j;
        }
        cout<<grannyPresent+1<<endl;
    }
    }
    return 0;
}    