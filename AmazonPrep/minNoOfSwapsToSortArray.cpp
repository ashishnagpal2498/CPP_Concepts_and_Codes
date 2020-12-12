// Min No. of Swaps to sort an Array
#include<bits/stdc++.h>
using namespace std;
int minSwaps(int* arr,int n){
    int ans = 0;
    pair<int,int> ArrPair[n];
    for(int i=0;i<n;i++){
        ArrPair[i].first = arr[i];
        ArrPair[i].second = i; // Curr position
    }
    sort(ArrPair,ArrPair+n);

    vector<bool> visisted(n,false);

    for(int i=0;i<n;i++){

        if(visisted[i] || ArrPair[i].second == i) continue;

        int cycle_size = 0;
        int j=i;
        while(!visisted[j]){
            visisted[j] = true;

            j = ArrPair[j].second;
            cycle_size++;
        }
        if(cycle_size>0){
            ans+= (cycle_size - 1);
        }
    }
    return ans;
}
int main(){
    int arr[] = {4,3,2,1};
    cout<<" Min no. of swaps req "<<minSwaps(arr,sizeof(arr)/sizeof(arr[0]));

    return 0;
}