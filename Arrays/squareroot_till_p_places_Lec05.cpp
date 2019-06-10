//Find sqroot of a number till P places;
#include<iostream>
using namespace std;
int main()
{
    int number;
    cin>>number;
    float sqroot;
    int p;// places
    cin>>p;
    for(int i=0;i*i<=number;i++)
    {
        sqroot = i;
    }
    
    float inc=0.1;
    int times=1;
    while(times<=p)
    {
        while(sqroot*sqroot<=number) sqroot+=inc;
        sqroot=sqroot-inc;
        inc=inc/10;
        times++;
    }
    cout<<sqroot;
    return 0;
}