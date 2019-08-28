//Print unique Elements in right rotated array
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int arr[] = {7, 7, 8, 8, 9, 1, 1, 4, 4, 2} , i=1,m=10;
    if(arr[0]==arr[m-1])
    {
        i=2;
        m=m-1;
    }
     else cout<<arr[m-1]<<" ";
    for(;i<m;i++)
    {
        if(arr[i-1]==arr[i]) i++;
        else cout<<arr[i-1]<<" ";
    }
    return 0;
}