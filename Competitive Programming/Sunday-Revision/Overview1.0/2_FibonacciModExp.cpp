// Fibonacci using modular exponentiation
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod1 1e9+7
struct mat{
    ll arr[2][2];
};
mat matMul(mat A,mat B)
{
    mat Ans;
    for(ll i=0;i<2;i++)
        for(ll j=0;j<2;j++)
            Ans.arr[i][j]=0;

    for(ll i=0;i<2;i++)
    {
        for(ll j=0;j<2;j++)
        {
            for(ll k=0;k<2;k++)
            {
                Ans.arr[i][j]= (Ans.arr[i][j] + (A.arr[i][k] * B.arr[k][j]));
            }
        }
    } 
    return Ans;    
}
mat fibModExp(mat A,ll n){
    mat Ans;
    for(ll i=0;i<2;i++){
        for(ll j=0;j<2;j++){
            if(i == j) Ans.arr[i][j] = 1;
            else Ans.arr[i][j] = 0;
        }
    }
    while(n){
        if(n&1){
            Ans = matMul(Ans,A);
        }
        A = matMul(A,A);
        n>>=1;
    }
    return Ans;
}
using namespace std;
ll t,n;
ll arr[200005];
ll fib[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    fib[0]= 0; fib[1]=1;
    for(int i=2;i<100000;i++) fib[i] = fib[i-1] + fib[i-2];
    mat A;
    A.arr[1][1] = A.arr[1][0] = A.arr[0][1] = 1;
    A.arr[0][0] = 0;
    A = fibModExp(A,n-1); 
    cout<<"Ans using Matrix -> "<<A.arr[1][1]<<endl;
    cout<<"Ans using DP -> "<<fib[n];   
    return 0;
}    