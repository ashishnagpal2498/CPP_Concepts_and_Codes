//Print all primes between 2 to N;
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=2;i<10005;i++)
    {   bool flag= true;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0){
                flag= false; break;
            }
        }
        if(flag)
        {
            arr.push_back(i);
        }
    }
    int i=0;
    while(arr[i]<=n)
    {
        cout<<arr[i++]<<"  ";
    }
    return 0;
}