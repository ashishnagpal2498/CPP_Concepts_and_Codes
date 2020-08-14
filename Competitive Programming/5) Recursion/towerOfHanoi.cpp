// tower of hanoi
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
void towerOfHanoi(int n,char start, char helper,char destination)
{   
    if(n==1){
        cout<<"Moving disk 1 from "<<start<<" to "<<destination<<endl;
        return;
    }

    towerOfHanoi(n-1,start,destination,helper);
    cout<<"Move disk "<<n<<" from "<<start<< " to "<<destination<<endl;
    towerOfHanoi(n-1,helper,start,destination);
}
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    towerOfHanoi(n,'A','B','C');

    return 0;
}    