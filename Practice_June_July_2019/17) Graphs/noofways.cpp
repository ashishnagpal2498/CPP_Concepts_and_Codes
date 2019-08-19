#include<iostream>
using namespace std;
int nways(int n)
{
    if(n<0) return 0;
    if(n==1||n==0) return 1 ;

    return nways(n-1)+nways(n-2)+nways(n-3);}
int countP(int n, int k) 
{ 
  // Base cases 
  if (n == 0 || k == 0 || k > n) 
     return 0; 
  if (k == 1 || k == n) 
      return 1; 
  
  // S(n+1, k) = k*S(n, k) + S(n, k-1) 
  return  k*countP(n-1, k) + countP(n-1, k-1); 
} 
int main()
{
    int n;
    // int a = ;
    cout<<a<<endl;
    cout<<countP(7,2)/7;
}