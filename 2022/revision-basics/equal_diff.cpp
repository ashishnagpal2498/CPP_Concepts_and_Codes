#include<bits/stdc++.h>
using namespace std;
int removeElements(int arr[],int &n){
    if(n==1 || n==2) return 0;
    sort(arr,arr+n);
    map<int,int> freq;
    int diff = -1;
    int maxVal = 1;
    int maximum = 0;
    for(int i=1;i<n;i++)
    {
        int val = arr[i] - arr[i-1];
        if(diff != -1 && diff != val){
            maximum=max(maximum,maxVal);
            maxVal=2;

        }
        else if(diff !=-1 && diff == val){
            maxVal++;
        }
        else{

                
            diff = val; // diff value
            maxVal++; // 1 consecutive
        }
    }
    maximum=max(maximum,maxVal);
    return n-maximum;
    // int maxVal = INT_MIN; 
    // for(auto i:freq){
    //     maxVal = max(maxVal,i.second);
    // }
    // return maxVal;
}
int main()
{
    int arr[100005],t,n;
    cin>>t;
    while(t){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
        cout<<removeElements(arr,n)<<"\n";
        t--;
    }
    return 0;
}