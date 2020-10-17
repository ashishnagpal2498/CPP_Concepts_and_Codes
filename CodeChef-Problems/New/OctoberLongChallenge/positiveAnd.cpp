// Positive And Codechef 
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t, n,k;
ll arr[200005];
bool isPower2(ll n){
    int i=1;
    while(i<=n){
        if(i == n) return false;
        i<<=1;
    }
    return true;
}
ll msb(ll n){
    n |= n >> 1; 
  
    // This makes sure 4 bits 
    // (From MSB and including MSB) 
    // are set. It does following 
    // 110011001 | 001100110 = 111111111 
    n |= n >> 2; 
  
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
  
    // Increment n by 1 so that 
    // there is only one set bit 
    // which is just before original 
    // MSB. n now becomes 1000000000 
    n = n + 1; 
  
    // Return original MSB after shifting. 
    // n now becomes 100000000 
    return (n >> 1); 
}
int main()
{           
    cin>>t;
    while(t--){
        cin>>n;
        bool ans = isPower2(n);
        if(!ans){
            cout<<-1<<endl;
        }
        else if(n<6){
                cout<<2<<" "<<3<<" "<<1;
            if(n==5){
                cout<<" "<<5<<" "<<4;
            }
            cout<<endl;
        }
        else if(n<=7){
            if(n==7) {cout<<7<<" ";}
            cout<<4<<" "<<5<<" "<<6<<" "<<2<<" "<<3<<" "<<1<<endl;
        }
        else{
            ll num = msb(n);
            // cout<<num<<endl;
            ll i = n;
            int j=0;
            while(i>7){
                ll v = -2;
                while(i&num){
                    if((i&1 ==1 && v == -1 && j!=0) || (i&1&&j==0&&v==-2)){
                        v = i;
                    }
                    else{
                        if(v==-2&&i&1) v++;
                        cout<<i<<" ";
                    }
                    i--;
                }
                j++;
                cout<<v<<" ";
                num>>=1;
            }
             cout<<7<<" "<<4<<" "<<5<<" "<<6<<" "<<2<<" "<<3<<" "<<1<<endl;
        }
    }
}