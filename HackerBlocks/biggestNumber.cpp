// Biggest Number
#include<bits/stdc++.h>
using namespace std;
bool myComp(string a,string b){
    int i=0,j=0,n= a.size(),m = b.size();
    while(i<n && j<m){
        if(a[i] > b[j]) return a>b;
        else if(a[i]<b[j]) return a<b;
        i++; j++;
    }
    if(a[i-1]>b[j-1]){
        return a>b;
    }
    else{
        return a<b;
    }
}
int main() {
    int n;
    int t;
    cin>>t;
    while(t--)
    {cin>>n;
    vector<string> v;
    string s;
    cin.get();
    for(int i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),myComp);
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }}
    return 0;
}