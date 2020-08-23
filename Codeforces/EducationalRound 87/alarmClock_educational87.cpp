//codeforce Alarm clock
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,a,b,c,d;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {   ll ans = 0;
        ll timeSleep = 0;
        cin>>a>>b>>c>>d;
        ll i =0;
        ll recoveryTime = d,alarmSnooze = c;
        while(timeSleep < a && i<=100000007)
        {   if(timeSleep >= b)
            {
                // first alarm -
                // recovery time starts
                if(recoveryTime > 0 && alarmSnooze > 0 ) {
                    recoveryTime--;
                    alarmSnooze--;
                    ans++;
                }
                else if(recoveryTime <= 0 && alarmSnooze > 0){
                    alarmSnooze --;
                    timeSleep++;
                    ans++;
                }
                else {
                    recoveryTime = d;
                    alarmSnooze = c;
                }
            }
            else{
                timeSleep++;
                ans++;
            }
            i++;
        }
        if(i == 100000007) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}