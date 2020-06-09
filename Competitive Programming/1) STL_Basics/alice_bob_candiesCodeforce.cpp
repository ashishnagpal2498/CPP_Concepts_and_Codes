//Alice Bob and Candies
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
ll arr[10005];
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {   cin>>n;
        ll totalAlice=0,previousAteAlice=0,previousAteBob=0,totalBob=0;
        for(int i=0;i<n;i++) cin>>arr[i];
        int i=0,j=n-1; bool turn=false;
        int rounds = 1;
        while(i<=j)
        {   
            //False turn means Alice turn
            if(!turn)
            {   if(previousAteAlice <= previousAteBob){
                // cout<<"Alice - "<<arr[i]<<endl;
                totalAlice+=arr[i];
                previousAteAlice+=arr[i++];
                }
                else{
                    turn = true;
                    rounds++;
                    previousAteBob =0;
                }
        }
            else{
                if(previousAteBob<=previousAteAlice){
                    // cout<<"Bob "<<arr[j]<<endl;
                    totalBob+=arr[j];
                     previousAteBob+=arr[j--];   
                }
                else{
                    rounds++;
                    turn = false;
                    previousAteAlice=0;
                }
            }
        }
        cout<<rounds<<" "<<totalAlice<<" "<<totalBob<<endl;    
    }
    return 0;
}