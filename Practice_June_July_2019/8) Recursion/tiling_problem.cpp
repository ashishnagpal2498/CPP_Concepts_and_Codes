//tiling problem 2
#include <iostream>
using namespace std;
int tile(int n,int m)
{
    //basecase
    if(n<0)
    {
        return 0;
    }
    if(n==0||n==1)
    {
            return 1;
    }
    if(m==n)
    {
        return 2;
    }
    int horiz_ans = 0;
     int verti_ans=0;
    if(m<n)
    {
        //vertical bhi place kar sakta hu -
        verti_ans = tile(n-m,m);
    }
    
     horiz_ans = tile(n-1,m); 

    return horiz_ans+verti_ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<tile(n,m)<<endl;
}