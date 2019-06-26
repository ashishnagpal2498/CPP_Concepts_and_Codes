//Chocolate Distribution Problem 
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   
    int T;
    cin>>T;

    while(T--)
   { int n;
    cin>>n;
   long long int arr[100005];
   for(int i=0;i<n;i++)
   {
        cin>>arr[i];
   }
   sort(arr,arr+n);
   int m;
   cin>>m;
   long long int min = 100000000;
   long long int smallans;
   for(int i=0;i<=n-m;i++)
    { smallans = arr[m+i-1]-arr[i];
       // cout<<smallans<<endl;
        if(smallans<min)
            min = smallans;

    }
   // cout<<arr[m-1] - arr[0]<<endl;
        cout<<min;
    cout<<endl;
    }
    return 0;
}