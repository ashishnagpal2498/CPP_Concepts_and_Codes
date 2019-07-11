//Dynamic Memory allocation
#include<iostream>
using namespace std;
int* CreateArr(int n)
{
    int*a = new int[n];
    for(int i=0;i<n;i++)
    {
        a[i]=i*i;
        cout<<i[a]<<" ";
    }
    // delete [] a;
    return a;
}
int main(int argc, char const *argv[])
{
    int *x = 0;
    x= new int;
    *x = 10;
    cout<<*x;
    int n;
    cin>>n;
    int * arr =CreateArr(n);
    cout<<endl;
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
    delete [] arr;
    return 0;
}