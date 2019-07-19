//Maximum Hamming Distance Between two Strings
#include <iostream>
using namespace std;
int MaxHamVal(int*arr,int n)
{
    int *arr2 = new int[2*n+1];
    for(int i=0;i<n;i++)
        arr2[i] = arr[i];
    for(int i=0;i<n;i++)
        arr2[i+n]= arr[i];
    // MaxHam
    int maxHam = 0;
    for(int i=1;i<n;i++)
    {
        int CurHam = 0;
        for(int j=i,k=0;j<i+n;j++, k++)
            if(arr[k]!=arr2[j]) CurHam++;
        
        if(CurHam>=maxHam) maxHam = CurHam;
    }
    return maxHam;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[10005];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<MaxHamVal(arr,n);    
    return 0;
}