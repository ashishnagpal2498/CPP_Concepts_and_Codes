//Arrays
#include<iostream>
using namespace std;
//Rotate an array -
//Juggling Algorithm -
int gcd(int a,int b)
{
    if(a%b==0)
    {
        return b;
    }
    int temp = a%b;
    a = b;
    b= temp;
    gcd(a,b);
}
void move_correct(int*arr,int i,int n,int j,int d ,int g,int temp)
{
    while(1)
    {
        int k = j+d;
        if(k>=n)
        {
            k=k-n;
        }
        if(k==i) break;
        arr[j] = arr[k];
        j=k;
    }
    arr[j] = temp;
}
void mycorrect(int *arr,int i,int n,int j,int d,int temp)
{   int a;
    for( a=j+d;a<n;a=a+d)
    {
        swap(arr[i],arr[a]);
        i =i +d;
    }
    arr[a-d] = temp;
}
//Reversal Algorithm
void reverse(int *arr,int start,int end)
{
    int i=start,j=end;
    while(i<j)
    {
        swap(arr[i++],arr[j--]);
    }
}
void leftRotate(int *arr,int d,int n)
{
    if(n==1) return;

    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}
int main()
{   
    int n;
    cin>>n;
    int arr[10005];
    int d;
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>d;
    int gcd_n_and_d = gcd(n,d);    
    
    cout<<gcd_n_and_d;
    // for(int i=0;i<gcd_n_and_d;i++)
    // {   //
    //     int temp = arr[i];
    //     int j = i;


    //     mycorrect(arr,i,n,j,d,temp);
    // }
    leftRotate(arr,d,n);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    return 0;
}