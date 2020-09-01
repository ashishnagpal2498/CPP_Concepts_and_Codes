// Stack ->
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
void insertAtBottom(stack<ll> & s,int topEle){
    stack<ll> temp;
    while(!s.empty()){
        temp.push(s.top());
        s.pop();
    }
    s.push(topEle);
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
}
void reverseStack(stack<ll> &s){
    if(s.empty()){
        return;
    }
    int topEle = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,topEle);
}
void printStack(stack<ll> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll a;
    stack<ll> s;
    ArrIn(n){
        cin>>a;
        s.push(a);
    }
    printStack(s);
    reverseStack(s);
    printStack(s);    
    return 0;
}    