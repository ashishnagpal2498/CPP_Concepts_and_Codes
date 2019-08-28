//Rearranging array Such that
//arr[i]>= arr[j] i 
//arr[i]<= arr[j]
#include<iostream>
#include<algorithm>
using namespace std;
void fixArray(int*arr,int n)
{   int *newArray = new int[n];
    int nOddpositions = n/2;
    int evenPositions = (n&1) ? nOddpositions+1 : nOddpositions;
    sort(arr,arr+n);

    for(int i=0,m=0;m<evenPositions;i+=2,m++)
    {
        newArray[i] = arr[nOddpositions+i];
    }
    for(int i=1,m=0;m<nOddpositions;i+=2,m++)
    {
        newArray[i] = arr[nOddpositions-i];
    }

    for(int i=0;i<n;i++)
    {
        cout<<newArray[i]<<" ";
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(int);
    fixArray(arr,n);
    return 0;
}