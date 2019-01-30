//k-GCD Epoch
#include<iostream>
using namespace std;
int gcd (int a, int b) {
   if (b == 0)
       return a;
   else{
       return gcd (b, a % b);
    }
}

int main()
{
    int testcase;
    cin>>testcase;
    int k;
    while(testcase>0)
    {
        cin>>k;
        int a = gcd(k,k+1);
        int b = a-1;
        cout<<a<<" "<<b<<endl;
        testcase--;
    }
    return 0;
}