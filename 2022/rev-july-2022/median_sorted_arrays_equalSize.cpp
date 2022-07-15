// Median of 2 sorted arrays ->

#include<iostream>
using namespace std;

double medianSorted(int* arr1,int* arr2,int n){

    int low1 = 0, low2= 0,hi1= n-1, hi2 = n-1;

    int m1,m2;
    while(true){
        if(hi1-low1 <= 1){
            // Calculate the median;
            int greaterEle = max(arr1[low1],arr2[low2]);
            int smallerEle = max(arr1[hi1],arr2[hi2]);

            return ((double)(greaterEle) + smallerEle )/2;
        }

        m1 = (hi1-low1)/2;
        m2 = (hi2-low2)/2;

        if(arr1[m1] == arr2[m2]){
            return arr1[m1];
        }

        if(arr1[m1]> arr2[m2]){
            hi1 = m1;
            low2 = m2;
        }
        else{
            hi2 = m2;
            low1 = m1;
        }
    }
}

int main(){

    int arr1[] = {1,5,9,15,20};
    int arr2[] = {2,3,6,7,11};
    int n = 5;

    double medianOfArray = medianSorted(arr1,arr2,n);
    cout<<"Median is -> "<<medianOfArray;
    return 0;
}