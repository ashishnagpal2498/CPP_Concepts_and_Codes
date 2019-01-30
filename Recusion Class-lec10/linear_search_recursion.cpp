//linear search using recursion
#include<iostream>
using namespace std;
int lsearch(int *a , int n,int ele)
{
    if(a[n-1]==ele)
    {
        return n-1; 
    }
    else{
    lsearch(a,n-1,ele);
}
}
int linearsearchBettermethod(int *a , int n,int ele)
{
    //Base case
    if(n==0)
    {
        return -1;
    }

    //Recursive call
    if(a[0]==ele)
    {
        return 0;
    }
    int smallerarr = linearsearchBettermethod(a+1,n-1,ele);
    if(smallerarr==-1)
    {
        return -1;
    }
    else
    {
        return 1 + smallerarr;
    }
}
int lastoccurence(int *a , int n,int ele)
{
    if(n==0)
    {
        return -1;
    }

    int chotaarray = lastoccurence(a+1,n-1,ele);
    if(chotaarray==-1)
    {
        if(a[0]==ele)
        {
            return 0;
        }
        else return -1;
    }
    return 1 + chotaarray;
}
int main()
{
    int arr[]={1,9,4,5,2,9};
    int n=6;
    cout<<"Element found at position "<<lsearch(arr,n,12);
    cout<<endl;
    cout<<"Better way"<<linearsearchBettermethod(arr,n,12);
cout<<endl<<"Last occ"<<lastoccurence(arr,n,9);
return 0;
}