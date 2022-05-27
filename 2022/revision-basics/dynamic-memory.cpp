// Dynamic Memory Allocation
#include<iostream>
using namespace std;

int main(){

    int* *arr = NULL;
    int n,m;
    cin>>n>>m;
    arr = new int*[n];

    for(int i=0;i<n;i++){
        arr[i] = new int[m];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    
}