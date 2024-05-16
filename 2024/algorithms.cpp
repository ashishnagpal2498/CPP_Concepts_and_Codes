// Algorithms

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int main() {
    
    // Initialize Vector
    vector<int> arr{87,3,4,1,6};
    
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(arr.begin(),arr.end());
    cout<<"After Sort - "<<" ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // Array must be sorted
    cout<<binary_search(arr.begin(),arr.end(),2)<<endl;
    
    // Min and Max
    cout<<"Min Value "<<min(2,3)<<" Max Value "<<max(4,1);
    
    string str = "abcsdf";
    
    reverse(str.begin(), str.end());
    return 0;
}