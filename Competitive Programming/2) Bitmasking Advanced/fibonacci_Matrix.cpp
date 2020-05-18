//Nth fibonacci number using matrix exponentiation
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
ll t,n;
ll arr[200005];
struct mat
{
    ll arr[2][2];
};
mat multi(mat AB,mat CD)
{
    mat ans;
    // Initialization
    for(ll i=0;i<2;i++)
        for(int j=0;j<2;j++)
            ans.arr[i][j] = 0;

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                ans.arr[i][j] = (ans.arr[i][j] + AB.arr[i][k]*CD.arr[k][j]) % mod;
            }
        }
    }
    return ans;    
}
mat fibonacci(mat a,ll n)
{   mat ans;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(i==j) ans.arr[i][j] = 1;
            else ans.arr[i][j] = 0;
        }
    }
    cout<<"Func "<<endl;
    while(n)
    {   
        if(n&1){
            ans= multi(ans,a);
        }
        a = multi(a,a);
        n>>=1;
    }
    return ans;
}
    ll fib[100005] = {0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mat a,ans;
    cin>>n;
    a.arr[0][1] = a.arr[1][0] = a.arr[1][1] = 1;
    a.arr[0][0] = 0;
    ans = fibonacci(a,n-1);
    cout<<"Ans "<<ans.arr[1][1]<<endl;
    fib[1] = 1;
    for(int i=2;i<=n;i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    for(int i=0;i<2;i++){for(int j=0;j<2;j++) {cout<<ans.arr[i][j]<<" ";}cout<<endl;}
    cout<<"Fibonacci linear "<<fib[n]<<endl;
    return 0;
}    