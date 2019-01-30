//Factorial Using recursion
#include<iostream>
using namespace std;
int fact(int n)
{
    //Base case 
if(n==0) return 1;    

    //recursive call
    int ans = n * fact(n-1);
    return ans;
}
int fib(int n)
{
if(n==0||n==1){return n;}

    //recursive call;
 int f1 = fib(n-1);
 int f2 = fib (n-2);
 return f1+f2;
}
int main()
{
    cout<<fact(6)<<endl;
    cout<<fib(7)<<endl;
    return 0;
}