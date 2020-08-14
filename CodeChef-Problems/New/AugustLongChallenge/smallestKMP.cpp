//Smallest KMP
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        map<char,int> freqInStr,freqRequired;
        string str1,str2;
        // cin.get();
        cin>>str1>>str2;
        sort(str1.begin(),str1.end());
        string ans ="";
        n = str1.length();
        m = str2.length();
        for(int i=0;i<m;i++){
            freqRequired[str2[i]]++;
        }
        for(int i=0;i<n;i++){
            freqInStr[str1[i]]++;
        }
        int i=0;
        for(i;i<n;i++){
            if(str1[i] == str2[0]){
                // Mil gai break the loop ->
                break;
            }
            else if(freqInStr[str1[i]] > freqRequired[str1[i]]){
                ans+=str1[i];
                freqInStr[str1[i]]--;
            }
            // else if(str1[i] == str2[0] && freqInStr[str1[i]] == freqRequired[str1[i]]){
            //     for(int j=0;j<m;j++){
            //        freqInStr[str2[j]]--; 
            //     }
            //     ans+=str2;
            //     break;
            // }
        }
        // makeStrings ->
        string dummy(freqInStr[str1[i]]-freqRequired[str1[i]],str1[i]);
        // cout<<dummy<<endl;
        if(dummy>str2){
            ans+=str2;
            for(int j=0;j<m;j++){
                   freqInStr[str2[j]]--; 
                }
        }
        else{
            ans+=dummy;
            freqInStr[str1[i]]-=dummy.length();
            ans+=str2;
            for(int j=0;j<m;j++){
                   freqInStr[str2[j]]--; 
                }
        }
        // Now Put back characters Lexicographically
        for(int i =0;i<26;i++){
            int f = freqInStr['a'+i];
            if(f > 0){

                for(int l=0;l<f;l++){
                    ans+=('a'+ i);
                }
            }
        }
         // cout<<ans.length()<<" "<<n<<endl;
        cout<<ans<<endl;
    }    
    return 0;
}    