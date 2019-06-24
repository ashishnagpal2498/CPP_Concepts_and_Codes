//Broken Calculator
#include<iostream>
using namespace std;
int main()
{
   unsigned long long int arr[100005];
    // int cnt =0;
    // int carry =0;
    int n;
    cin>>n;
    int i=1;
    arr[0]=1;
    unsigned long long int size_of_array =1;
    while(i<=n)
    {  unsigned long long int cur_size = size_of_array;
        size_of_array = 0;
       unsigned long long int carry =0;

        for(unsigned long long int j=0;j<cur_size;j++)
        {   unsigned long long int mul = (arr[j]*i);
            //size -

            arr[j] = (mul+carry)%10;
            carry = (mul+carry)/10;
            size_of_array++;
        }
        if(carry!=0)
        {
            arr[size_of_array++] = carry;
        }
        // cout<<"After ith iteration"<<i<<"       " ;
        // for(int m=size_of_array-1;m>=0;m--){cout<<arr[m];}
        //  cout<<endl;   
        i++;

    }
    for(long long int i=size_of_array-1;i>=0;i--)cout<<arr[i];
    return 0;
}