//Best Time to buy and sell stock
#include<iostream>
#include<vector>
using namespace std;
bool isSorted(int i,vector<int> arr)
{
    if(i==1) return true;

    if(arr[i]<arr[i+1] && isSorted(i+1,arr)) return true;

    else return false;
}
int maxProfit(vector<int> arr)
{   int n = arr.size();
    if(isSorted(0,arr)){
        return arr[n-1] - arr[0];
    }
    // O(n^2) check - variable 
    long long int maxVal =0;
    for(int i=0;i<n;i++)
    {
        int j=i,k=i+1;
        long long int sum=0,costP=0,sellP=0;
        // Suppose i selled on day -
        while(j<n && k<n)
        {
            if(arr[j]<arr[k] && k+1<n && arr[k]>arr[k+1])
            {
                //costP - arr[j] sell - arr[k]
                sum+=(arr[k]-arr[j]);
                j+=k; k++;
            }
            else if(k==n-1 && arr[j]<arr[k]){
                sum+=(arr[k]-arr[j]);
                j++;k++;
            }
            else{
                k++;
            }
        }
        cout<<"Sum "<<sum<<endl;
        if(maxVal<sum) maxVal = sum;
    }
    return maxVal;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<maxProfit(arr);    
    
    return 0;
}