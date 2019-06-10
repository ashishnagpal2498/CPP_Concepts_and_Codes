//Optimised Prime Number
#include<iostream>
#include<ctime>
using namespace std;
//Complexity is root of n as we are only taking the smaller divsors
int main()
{   time_t start= time(0);
    int n;
    cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) {cout<<"Notprime"; return 1;} 
    }
    cout<<"Prime"<<endl;
    time_t end = time(0);
    cout<<end-start;
    return 0;
}