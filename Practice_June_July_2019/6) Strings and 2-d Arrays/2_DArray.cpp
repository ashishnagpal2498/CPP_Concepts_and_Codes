//2-D array 
#include<iostream>
using namespace std;
int main()
{
    char array[][3] = {{'A','B','\0'},{'C','D'},{'E','F'}};
    cout<<array<<endl;
    cout<<array[0]<<endl;
    cout<<array[0][0]<<endl;
    cout<<(&(array[0][0]))<<endl;
    int arr[][4] = {
        {1,3,5,7},
        {2,8,10,12},
        {4,9,11,16},
        {6,13,15,18}
    };
    int element;
    int n =4;
    int i=0,j=n-1;
    cout<<"Enter element to be searched  "; cin>>element;
    bool flag =false;
    while(i<n&&j!=0)
    {
        if(arr[i][j]==element) {    cout<<"Found at "<<i<<"  "<<j; flag =true; break;}
        else if(arr[i][j]>element) j--;
        else i++;
    }
    if(!flag) cout<<"element not found";
    return 0;
}