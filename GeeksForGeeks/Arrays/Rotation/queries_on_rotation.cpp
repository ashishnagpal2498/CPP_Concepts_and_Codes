//Queris on rotation
#include <iostream>
#define arrIn for(int i=0;i<n;i++) cin>>arr[i];
#define arrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" ";}
using namespace std;
void query1Rotate(int &toRotate,int times,int n)
{
    toRotate = ((toRotate) - times) %n;
}
void  query2Rotate(int &toRotate, int times ,int n)
{
    toRotate = ((toRotate) + times) %n;
}
void query3(int toRotate,int l,int r,int n,int *prefixSum)
{   cout<<"toRotate - "<<toRotate<<endl;

    l = (l+toRotate+n)%n;
    r = (r+toRotate+n)%n;
    if(l<=r)
    {
        cout<<prefixSum[r+1] - prefixSum[l]<<endl;

    }
    else
    {
        cout<<(prefixSum[n] + prefixSum[r+1] - prefixSum[l]);
    }
}
void wrapper(int*arr,int n)
{
    int *prefixSum = new int[n+1];
    prefixSum[0] = 0;
    for(int i=1;i<=n;i++)
        prefixSum[i] = prefixSum[i-1] + arr[i-1];

    int toRotate = 0;
    query1Rotate(toRotate,3,n);
    query3(toRotate,0,2,n,prefixSum);
    query2Rotate(toRotate,1,n);
    query3(toRotate,1,4,n,prefixSum);
}
int main()
{
    //Prefix Sum
    //keep track of rotation -ve means left rotation has dominance
    int arr[10005];
    int n;
    cin>>n;
    arrIn ;
    arrOut;
    wrapper(arr,n);
    return 0;
}