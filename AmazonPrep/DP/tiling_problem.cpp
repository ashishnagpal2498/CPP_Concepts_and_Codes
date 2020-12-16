// Tiling Problem
#include<iostream>
using namespace std;
int countWays(int n){
    if(n==0) return 0;
    if(n==1 || n==2){
        return n;
    }

    return countWays(n-1) + countWays(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<countWays(n);
    return 0;
}