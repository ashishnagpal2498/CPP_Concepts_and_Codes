// Recursion Basics 

#include<iostream>
using namespace std;

int fib(int n){
    if(n == 0 || n == 1) return n;

    return fib(n-1) + fib(n-2);
}

int fact(int n){
    // Base case -
    if(n==0 || n==1) return 1;

    return n* fact(n-1);
}

// Is Sorted Array -

int isSorted(int arr[],int n){
    // Base case -
    if(n == 1) return true;
    
    if(arr[0]<arr[1] && isSorted(arr+1,n-1)) return true;
    
    return false;
}

int xPowery(int x,int y){
    // base case 
    if(y== 0) return 1;
    if(y==1) return x;

    int ans = xPowery(x,y/2);
    ans*=ans;
    if(y&1){
        ans*=x;
    }
    return ans;
}

int linear_search(int arr[],int n,int key){
    if(n == 0) return -1;

    if(arr[0] == key) {
      //  cout<<" Element found - "<<endl;
        return 0;
    }
    //cout<<"Element not found checking further array - "<<endl;
    int chhotaArray = linear_search(arr+1,n-1,key);
    //cout<<"Chhota array value - "<<chhotaArray<<endl;
    if( chhotaArray == -1) return -1;
    else return chhotaArray+1; 
}



int main(){
    int n;
    // cin>>n;
    // cout<<"Factorial of n "<<fact(n);
    // cout<<"\n Fibonacci nth number "<<fib(n);
    int arr[] = {1,3,4,5,7,9};
    n = sizeof(arr)/sizeof(int);
    isSorted(arr,n) ? cout<<"\n Sorted array " : cout<<"\n Not Sorted";
    int x = 4,y=3;
    cout<<"\n x Power y"<<xPowery(x,y)<<"\n";
    cout<<"Linear Search "<<linear_search(arr,n,8);
    return 0;
}