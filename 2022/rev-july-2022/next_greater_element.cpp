// Next Greater Element
#include<iostream>
#include<stack>
using namespace std;

// To the Right
void ngeToRight(int* arr,int n){
    if(n==0) return;

    stack<int> s;
    s.push(n-1);
    int* nge = new int[n];
    nge[n-1] = -1;

    for(int i=n-2;i>=0;i--){
        while(!s.empty() && arr[i] >= arr[s.top()]) s.pop();

        if(s.empty()){
            nge[i] = -1;
        }
        else{
            nge[i] = arr[s.top()];
        }
        s.push(i);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" -> "<<nge[i]<<"\n";
    }
}

// STOCK SPAN Problem -
void stockSpan(int* arr,int n){
    // Number of days passed between current day and the 1st day before today that the price was higher;

    if( n == 0) return;

    int * ngeLeft = new int[n];
    stack<int> s;
    s.push(0);
    ngeLeft[0] = 1;
    for(int i=1;i<n;i++){
        while(!s.empty() && arr[i] >= arr[s.top()]) s.pop();

        if(s.empty()){
            ngeLeft[i] = i+1;
        }
        else{
            ngeLeft[i] = i - s.top() ;
        }
        s.push(i);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" -> "<<ngeLeft[i]<<endl;
    }
}

int main(){
    int arr[] = {2,5,9,3,1,12,6,8,7};
    int n = sizeof(arr)/sizeof(int);
    stockSpan(arr,n);
    return 0;
}