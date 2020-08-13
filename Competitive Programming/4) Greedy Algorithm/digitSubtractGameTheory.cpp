// Given a number -> calculate if digit of that number is subtracted ->
// GAME Theory
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
void setOfDigits(bool* a,int num){
    for(int i=1;i<=9;i++) a[i] = 0;
    while(num)
    {
        int d = num%10;
        num/=10;
        a[d] = true;
    }
}
using namespace std;
ll t,n;
ll arr[200005] ={0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    bool a[10] = {0};
    for(int i=1;i<=n;i++){
        setOfDigits(a,i);
        for(int j=1;j<=9;j++){
            if(a[j] && j<=i && arr[i-j] == 0){
                arr[i] = 1;
                break;
            }
        }
    }
    cout<<arr[n]<<endl;    
    return 0;
}    