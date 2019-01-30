#include<iostream>
using namespace std;
bool isSorted(int *a , int n)
{
    if(n==1)
    {
        return true;
    }

    if(a[0]<a[1])
    {
        bool smallarray = isSorted(a+1,n-1);
        if(smallarray)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int a[]={2 ,9 ,4 ,6 ,8};
    bool flag = isSorted(a,5);
    if(flag) cout<<"Sorted";
    else cout<<"Not sorted";
    return 0;
}