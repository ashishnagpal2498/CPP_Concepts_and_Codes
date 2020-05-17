#include<iostream>
#define ArrIn for(int i=0;i<n;i++) cin>>arr[i];
using namespace std;
int arrSum(int *arr,int n)
{   int sum =0;
    for(int i=0;i<n;i++) {  sum+=arr[i]*(i+1);}
    return sum;
}
int main(int argc, char const *argv[])
{
    int arr[100005];
    int n;
    cin>>n;
    ArrIn;
    int Arrsum = arrSum(arr,n);
    int ms = Arrsum;
    int temp = Arrsum;
    for(int i=0;i<n-1;i++)
    {   //swapping perform -
        
        Arrsum = Arrsum + arr[i] -arr[i+1];
        if(Arrsum>=ms) 
            {   //Swapping Done
                cout<<Arrsum<<endl;
                //swap(arr[i],arr[i+1]);
                ms = Arrsum;  }
        // Restore Value
        Arrsum = temp;
    }
    cout<<ms<<endl;
    return 0;
}