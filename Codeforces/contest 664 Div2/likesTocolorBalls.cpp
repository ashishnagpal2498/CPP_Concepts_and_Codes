// Codeforces contest 664 Div 2
//Binoui likes to color balls
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,m,o,p;
ll arr[200005];
bool canPlace(){
        int oddVal = 1;
        if(arr[0]&1) oddVal--;
        if(arr[1]&1) oddVal--;
        if(arr[2]&1) oddVal--;
        if(arr[3]&1) oddVal--;

        // cout<<oddVal<<" -> ";
        return oddVal>=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        ll minVal = INT_MAX;
        cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
        minVal = min(arr[0],min(arr[1],arr[2]));
        bool flag = false;
        bool isOdd1 = arr[0]&1, isOdd2 = arr[1]&1, isOdd3= arr[2]&1, isOdd4 = arr[3]&1;
        if((isOdd1)&&(isOdd2) && (isOdd3) && (isOdd4)){
            flag = false;
            // all numbers odd
        }
        else if((!isOdd1) && !isOdd2 && !isOdd3 && !isOdd4) flag = true;
        else if((arr[0] != 0 && arr[1] !=0 && arr[3] !=0) && ((isOdd1 && isOdd2 && !isOdd3 && isOdd4) || (isOdd1 && isOdd3 && !isOdd2 && isOdd4)
            || (isOdd2 && isOdd3 && !isOdd1 && isOdd4))) flag = true;
        else flag = false;
        // for(int i=1;i<=minVal;i++){
        //     for(int j=0;j<4;j++){
        //         if(arr[j]!=3) arr[j]--;
        //         else arr[j]+=3;
        //     }
        //     if(canPlace()){
        //         flag = true;
        //         break;
        //     }
        // }
        // cout<<flag<<" ->"<<endl;
        if(flag){

            cout<<"Yes"<<endl;
        }
        else {cout<<"No"<<endl;}
    }
    return 0;
}    