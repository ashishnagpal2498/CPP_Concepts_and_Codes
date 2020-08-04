// Perfect Array 
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,m;
bool solve(vector<int> firstArray,vector<int> secondArray){
   int i=0,j=0,n = firstArray.size(),m = secondArray.size(); // i = first array index j = second Array index
   while(i<n &&)
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    vector<int> firstArray,secondArray;
    int a;
    ArrIn(n) {
        cin>>a;
        firstArray.push_back(a);
    }    
    ArrIn(m){
        cin>>a;
        secondArray.push_back(a);
    }
    bool ans = solve(firstArray,secondArray);
    cout<< ans ? "YES\n" : "NO\n";
    return 0;
}    