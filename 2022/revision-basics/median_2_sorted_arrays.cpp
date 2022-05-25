// Median of two Sorted Arrays -
#include<iostream>
using namespace std;
double find_med(int arr1[],int arr2[], int n,int m){
    int low1=0,low2=0,hi1=n-1,hi2=m-1;

    while(hi1 - low1 != 1 || hi2- low2 !=1){
        int m1 = (hi1-low1)/2,m2 = (hi2-low2)/2;
        int median1 = arr1[m1], median2 = arr2[m2];

        if(hi1-low1==1 || hi2-low2 == 1){
            double smallerElement=max(arr1[low1],arr2[low2]);
            double biggerElement=min(arr1[hi1],arr2[hi2]);
            return (double)(smallerElement+biggerElement)/2;
        }

        if(median1 == median2) return median1;

        else if ( median1 < median2){
            low1 = m1;
            hi2 = m2;
        }
        else{
            low2 = m2;
            hi1 = m1;
        }
    }
    // double startEle = max(arr1[low1],arr2[low2]);
    // double endEle = min(arr1[hi1],arr2[hi2]);
    // return (startEle+endEle)/2;
}
int main(){
    int arr1[] = {1,3,5,7,10};
    int arr2[] = {9,12,15,20,22};
    int n = sizeof(arr1)/sizeof(int);
    int m = sizeof(arr2)/sizeof(int);
    double median = find_med(arr1,arr2,n,m);
    cout<<"Median is - "<<median;
    return 0;
}