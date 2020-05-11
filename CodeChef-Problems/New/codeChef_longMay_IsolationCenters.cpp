//Codechef -
#include<iostream>
using namespace std;
int main()
{
    int t,n,q;
    cin>>t;
    while(t--)
    {   int freq[26] = {0};
        int ans[100005] = {0};
        int val;
        string s;
        cin>>n>>q;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            
            freq[int(s[i] - 'a')]++;
        }
        int maxVal = INT8_MIN;
        for(int i=0;i<26;i++)
        {   
            ans[freq[i]]++;
            if(maxVal<freq[i]) maxVal = freq[i];
        }
        // for(int i=0;i<26;i++)
        // {
        //     cout<<i<<" "<<ans[i];
        //     cout<<endl;
        // }
        while(q--)
        {  
            cin>>val;
            long long int sum =0;
            for(int i=val+1 ;i <=maxVal;i++)
            {
                sum= sum + ((i - val )* ans[i]);
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}