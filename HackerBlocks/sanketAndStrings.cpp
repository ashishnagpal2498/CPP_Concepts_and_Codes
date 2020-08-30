// Sanket And Strings
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,k;
ll arr[200005];
int calConsecutive(string s,char ch,int k){
    int ans=0;
    int i=0,j=0,c=0;
    // Precompute values till k 
    // window -> of size k ->
    while(j<s.size() -1 && c<k ){
        if(s[j] != ch){
            c++;
        }
        if(c == k) break;
        j++;
    }
    while(i<=j){
        // This will stop only when next character is opposite of ch
        while(j < s.size() -1 && s[j+1] == ch) j++;
        // Calculate window size

        int window = j+1-i;
        // cout<<ch<<" -> "<<j<<" j -> i -> "<<i<<endl;
        ans = max(ans,window);

        i++;
        if(j<s.size()-1 && s[i-1] != ch) j++;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k;
    string s;
    cin>>s;
    if(k>=s.size())
    {
        cout<<s.size()<<endl;
    }    
    else{
        int maxValA = calConsecutive(s,'a',k);
        int maxValB = calConsecutive(s,'b',k);

        cout<<max(maxValA,maxValB)<<endl;
    }
    return 0;
}    