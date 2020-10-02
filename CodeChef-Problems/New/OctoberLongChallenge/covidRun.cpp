// Covid Run
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t, n,k,x,y;
bool covidPositive[1005];
int main()
{           ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    while(t--){
        cin>>n>>k>>x>>y;
        bool visited[1005] ={false};
        visited[x] = true;
        bool flag = false;
        while(true){
            x = (x+k)%n;
            if(x == y){
                flag = true;
                break;
            }
            else if(!visited[x]){
                visited[x] = true;
            }
            else{
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}