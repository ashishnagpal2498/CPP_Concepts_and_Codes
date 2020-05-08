#include<iostream>
#define ArrIn for(int i=0;i<n;i++) cin>>arr[i]
using namespace std;
bool maintainDistance(int* arr,int n)
{
    int i=0,j=0;
    while(i<n&&j<n)
    {
        if(arr[j]==1&&arr[i]==1&&i!=j)
        {
            //check for distance
            if(j-i<6) return false;
            else i = j;
        }
        else if(arr[j]==1 && arr[i]==0)
        {
            i=j;
        }
      j++;      
    }
    return true;
}
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        int n,arr[1005];
        cin>>n;
        ArrIn;
        maintainDistance(arr,n) ? cout<<"YES\n" : cout<<"NO\n";
    }
    return 0;    
}