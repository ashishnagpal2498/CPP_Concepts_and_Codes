//Count-subarrays-
#include<iostream>
using namespace std;
bool isPrime(int n)
{   bool arr[100005] ={false};
    arr[2] = true;
    arr[3] = true; 
    for(int i=5;i<100005;i=i+2)
    {   bool flag = false;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            arr[i] = false;
        }
        else
        {
            arr[i] = true;
        }
    }
    return arr[n];
}
int gcd(int a,int b)
{
    while(a%b!=1)
    {   int temp = a%b;
        if(temp==0)
        {
            return b;
        }

        a = b;
        b = temp;
    }
    return 1;
}
int countSubarray(int *arr,int n)
{
    int i=0,j=1;
    int count = 0;
    while(i<n)
    { bool flag = false;
        j=i;
        for(int k=n-1;k>=j;k--)
        {
            if(gcd(arr[i],arr[k])>1)
            {
               count++; 
                i =k+1;
                // cout<<"True  "<<i<<"  "<<endl;
                flag = true;
                break;   // cout<<"Inside isprime"<<endl;
            }
        }
        if(!flag)
        {
            ++i;
            //Number itself is the gcd 
            count++;
        }
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    int arr[100005];
    for(int i=0;i<n;i++) cin>>arr[i];    
    // isPrime(2);
    cout<<countSubarray(arr,n);
     // cout<<gcd(3,7);
    return 0;
}