//Linear Search using recursion 
#include<iostream>
using namespace std;

int lsearch(int *a,int n,int ele)
{   //Base Case
    if(n==0)
    {
        return -1;
    }

    //Recursive case
    if(a[0]==ele) return 0;

    int chotaarray = lsearch(a+1,n-1,ele);
    if(chotaarray==-1)
    {
        return -1;

    }
    else
    {
        return 1+chotaarray;
    }
}
//This gives the last occurence of an element
int last_occ(int *a , int n , int ele)
{
    if(n==0) return -1;

    //Recursive case

    int chotaarray = last_occ(a+1,n-1,ele);

    if(chotaarray==-1)
    {
        if(a[0]==ele)
        {
            return 0;
        }
        else{
            return -1;
        }
    }
    
        return 1+chotaarray;

}


int main()
{
    int a[]={
        1,4,6,7,8,6,8,9
    };
    cout<<"Element is at position" <<last_occ(a,8,8);
    return 0;
}