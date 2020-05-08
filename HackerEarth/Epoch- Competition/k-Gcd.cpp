#include<iostream>
using namespace std;
int k = 0;
int ele;
int gcd (int a, int b) {
   if(k==ele)
   {
    cout<<a<<b;
   }
   if (b == 0)
       return a;
   else{
       ++k;
       return gcd (b, a % b);
    }
}
int main()
{
    cin>>ele;
    cout<<gcd(1,0);
    return 0;
}