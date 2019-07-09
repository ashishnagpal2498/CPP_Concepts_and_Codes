//All indices
#include<iostream>
using namespace std;
void indices(int*arr,int*sol,int n,int i,int &j,int key)
{
    //Base case - 
    if(n==0)
    {
        //whole array is traversed ,
        return;
    }
    if(key ==arr[i])
    {
        sol[j++] = i;
    }
    indices(arr,sol,n-1,i+1,j,key);
}
int main()
{
    int n;
    cin>>n;
    int arr[100005];
    for(int i=0;i<n;i++) cin>>arr[i];
    int sol[100005];
    int j=0;
    int key;
    cin>>key;
    indices(arr,sol,n,0,j,key);
    for(int i=0;i<j;i++)
    {
        cout<<sol[i]<<" ";
    }    
}