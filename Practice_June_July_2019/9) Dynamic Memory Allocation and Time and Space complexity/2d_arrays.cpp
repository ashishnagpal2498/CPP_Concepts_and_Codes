//2-D array using dynamic memory allocation
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int* *arr;
    int n;
    cin>>n;
    arr = new int*[n];
    int m;
    cin>>m;
    cout<<"Value of a "<<arr<<endl;
    cout<<"Address of a"<<&arr<<endl;
    for(int i=0;i<m;i++)
    {   cout<<"Address of "<<i<<" Row  "<<&arr[i]<<endl;
        arr[i] = new int[m];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    //print the 2-d array
    cout<<endl; 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) {cout<<arr[i][j]<<"  ";}
            cout<<endl;
    }

    //free the memory
    for(int i=0;i<n;i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
    return 0;
}