//pattern trial
#include<iostream>
using namespace std;
int main()
{
    int n=5;
    int half_n = n/2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {   int eqi_x ,eqi_y;
            if(i<=half_n) eqi_x=i; else eqi_x = n-i+1;
            if(j<=half_n) eqi_y = j; else eqi_y = n-j+1;
            if(eqi_x==half_n+1||eqi_y==half_n+1) cout<<"*";
        }
        cout<<endl;
    }
return 0;    
}