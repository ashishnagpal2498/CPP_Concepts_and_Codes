//Chef and Icecream
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
int main()
{   // Return maximum value note to the customer 1st ->
    // Small change customer can come later instance-
    // Small change can also sum upto big change
    // Icecream cost RS 5
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        ll coins[3]={0}; //0th - 5 rs coin - 1st - 10 rs and 2nd 15 rs -
        bool flag = true;
        for(int i=0;i<n;i++) cin>>arr[i];
        if(arr[0]!= 5) cout<<"NO"<<endl;
        else{   coins[0]++;
                for(int i=1;i<n;i++){
                    // Customer gives money
                    if(arr[i] == 5){
                        coins[0]++;
                    }
                    else if(arr[i]==10){
                        if(coins[0] == 0){
                            flag = false;
                            break;
                        }
                        else{
                            coins[1]++;
                            coins[0]--;
                        }
                    }
                    else{
                        // CHef was given 15 
                        if((coins[1]>=1 || coins[0]>=2)){
                            // change can be given - 
                            coins[2]++;
                            if(coins[1]>=1) coins[1]--;
                            else coins[0]-=2;
                        }
                        else {
                            flag = false;
                            break;
                        }
                    }
                }
                if(!flag) cout<<"NO\n";
                else cout<<"YES\n";
        }
    }
    return 0;
}    