//No of set bits - Optimised
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count =0;
    while(n) {n=(n&(n-1));cout<<n<<endl;count++;}
    cout<<count<<endl;
    return 0;
}