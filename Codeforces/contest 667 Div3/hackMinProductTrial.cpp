#include <bits/stdc++.h>
 
#define pii pair<int,int>
#define pdi pair<double,int>
#define ppi pair<pair<int,int>,int>
#define pipi pair<pair<int,int>,pair<int,int> >
#define fs first
#define sc second
 
#define sorta(a) sort(a.begin(),a.end());
#define rsorta(a) sort(a.rbegin(),a.rend());
#define sorta2(a,n) sort(a,a+n);
#define debug(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define debug2(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";
 
#define all(v) (v).begin(), (v).end()
#define lb(arr,num) lower_bound(all(arr),num)
 
#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define msi map<string,int>
 
typedef long long ll;
using namespace std;
//typedef vector<vector<int> > matrix;
#define pll pair<ll,ll>
 
int getdiv(int a,int n){
    int ret=1;
    for(int i=1;i<=a && i<=n;i++){
        if(a%i==0) ret=i; 
    }
    return ret;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int Q,n,a,b; cin>>Q;
    while(Q--){
        cin>>n>>a>>b;
        if(n==2){
            cout<<a<<" "<<b<<"\n"; continue;
        }
        int k=getdiv(b-a,n-1),d=(b-a)/k;
        //cout<<k<<" "<<d<<'\n';
        vector<int> ans;
        int i;
        for(i=0;b-d*i>0 && i<n;i++){
            ans.push_back(b-d*i);
        }
        for(int j=1;j<=n-i;j++){
            ans.push_back(b+d*j);
        }
        debug(ans);
    }
}