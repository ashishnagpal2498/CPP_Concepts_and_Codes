//Chocolate Distribution Problem 
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
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
   for(int i=m-1;i<n;i++)
    { 
        long long int small_ans = arr[i] - arr[i-m];
        min=  small_ans < min ? small_ans : min; }
   // cout<<arr[m-1] - arr[0]<<endl;
        cout<<min;
    return 0;
}