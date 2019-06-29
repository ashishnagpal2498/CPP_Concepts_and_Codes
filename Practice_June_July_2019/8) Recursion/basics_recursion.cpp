//Recursion
#include<iostream>
using namespace std;

int fib(int n)
{
    //base case -
    if(n==0||n==1)
    {
        return n;
    }

    int ans = fib(n-1)+fib(n-2);
    return ans;
}

int fact(int n)
{
    //BAse case -
    if(n==0)
    {
        return 1;
    }
    return n * fact(n-1);
}
bool isSorted(int*arr,int n)
{
    //Base Case -
    if(n==1)
    {
        //1 hi element hai , and that is always sorted
        return true;
    }
    //Self Work
    //Front check - 
    if(arr[0]>arr[1])
    {
        return false;
    }

    //Recursive case
    bool ans = isSorted(arr+1,n-1);
    return ans;
}

bool isSorted_end(int *arr,int n)
{
    if(n==1)
        return true;
    bool ans = isSorted_end(arr+1,n-1);
    if(arr[0]<arr[1]&&ans)
        return true;
    return false;
}
int power_of_n(int x,int y)
{
    if(y==0)
    {
        return 1;
    }
    return x * power_of_n(x,y-1);
}
int fast_power(int x,int y)
{
    if(y==0)
    {
        return 1;
    }
    int halfpower = fast_power(x,y/2);
        halfpower*=halfpower;
    if(y&1)
    {
        halfpower*=x;
    }
    return halfpower;
}
int linear_Search(int *arr,int n,int element)
{
    if(n==0)
    {
        return -1;
    }

    int chotta_array = linear_Search(arr+1,n-1,element);
   
    if(chotta_array==-1)
    {     if(arr[0]==element)
        {
        return 0;
        }
        return -1;
    }
    return 1+ chotta_array;
}
int staircase(int n)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0) return 1;

    int case1 = staircase(n-1);
    int case2 = staircase(n-2);
    int case3 = staircase(n-3);
    return case1+case2+case3;

}
int staircase_prob(int n,int k)
{
    if(n<0) return 0;
    if(n==0) return 1;
    int ans =0;
    for(int i=1;i<=k;i++)
    {
        ans += staircase_prob(n-i,k);
    }
    return ans;
}
int main()
{
    cout<<fact(5)<<endl;
    cout<<fib(6)<<endl;
    int arr[] ={1,2,3,4,5,5,4,3,2,1,7,5};
    int n = sizeof(arr)/sizeof(n);
    cout<<isSorted_end(arr,n-1)<<endl;
    cout<<fast_power(2,9);
    int element;
    cin>>element;
    cout<<linear_Search(arr,n,element)<<endl;
    cout<<staircase(4)<<endl;
    cout<<staircase_prob(4,3)<<endl;
    return 0;
}