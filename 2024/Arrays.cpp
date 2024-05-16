// Arrays

#include<bits/stdc++.h>
using namespace std;

int findUnique(vector<int> arr)
{
    //Write your code here
    int size = arr.size();
    int ans = 0;
    for(int i=0;i<size;i++){
        ans^=arr[i];
    }
    return ans;
}

int main(){

    
    vector<int> arr{1,4,5,6,9};
    vector<int> uniqueNo{1,2,3,4,4,1,2,5,3};

    return 0;
}