//Creating an array using dynamic memory allocation
#include<iostream>
using namespace std;

int * Createarr(int n)
{
    // int arr[n]; this is wrong , we need to create array dynmically
    int *a = new int[n]; //creates an array of size n
    for(int i=0;i<n;i++)
    {
        a[i]=i*i;
        cout<<a[i]<<"  ";
    }
    cout<<endl;
    return a;
}

int main()
{   
    //creating an array of size dynamically
    int n;
    cin>>n;
    int * ptr = Createarr(n);
    for(int i=0;i<n;i++)
    {
        cout<<ptr[i]<<"  ";
    }
    //here array exist in memory until and unless i delete it
    delete [] ptr; //this deletes only the array in the heap

    //Creating a 2-D array by dynamic memory allocation

    

    return 0;
}