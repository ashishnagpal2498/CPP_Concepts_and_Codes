//Searching element in 2-D sorted Array 
#include<iostream>
using namespace std;
int main()
{
    int arr[][4]={
    {1,3,5,7},
    {2,8,10,12},
    {4,9,11,16},
    {6,13,15,18}
    };
    int row=4,col=4;
    //search an element
    int key;
    cin>>key;
    int x=0 , y=col-1;
    while(x<row && y>=0)
    {
        if(arr[x][y]==key) 
        {
            cout<<"element found at position "<<x<<" "<<y;
            return 1;
        }
        if(arr[x][y]>key) y--;
        else x++;
    }
    cout<<"element not found";
    return 0;
}