// Generate string till 1000
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n= 1001;
    string s = "";
    for(int i=0;i<n;i++){
        s+=('a'+ (i%26));    
    }
    string str1= "zsoo",str2="zz",str3="mmmmm",str4="mmmmma";
    if(str1 > str2)
    {cout<<str2<<endl;
    }
    else {cout<<str1<<endl;}
    if(str3 > str4) cout<<str4;
    else cout<<str3;
    return 0;
}    