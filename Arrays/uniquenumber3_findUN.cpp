//Unique Number 
//Logic behind the code is - add every bit of the number to an array of 32 bits or 64
//Each bit will be in the form 3n or 3n+ something 
//Modulus every bit youll get the ans

#include<iostream>
using namespace std;
int uniquenum(int arr[100],int n)
{   int bitarr[32]={0};
    for(int i=0;i<n;i++)
    {   int num = arr[i];
        int j=0;
        while (num>0)
        {
            int bit=num&1;
            bitarr[j]+=bit; //putting that bit into 0th index 
            num = num>>1; //shift right 
            j++;
        }
    }
    int p=1;
    int ans=0;
    for(int i=0;i<32;i++)
    {
        bitarr[i]=bitarr[i]%3;
        ans= ans+ bitarr[i]*p;
        p=p*2; //p<<1; left shift
    }
    return ans;
}


int main()
{
    int arr[]={7,7,6,6,4,2,6,4,4,7};
    int sz=sizeof(arr)/sizeof(int);
    int ans = uniquenum(arr,sz);
    cout<<ans;
    return 0;
}