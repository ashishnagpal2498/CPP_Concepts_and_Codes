#include<iostream>
using namespace std;
int power(int x,int y)
{
    if(y==0)
    {
        return 1;
    }
    return x*power(x,y-1);
}
int fastpower(int x,int y)
{
    //base case
    if(y==0) return 1;

    //recursive case
    int halfpower = fastpower(x,y/2);
    halfpower *=halfpower;
    if(y&1){
        return halfpower*x;
    }
    else {
        return halfpower;
    }
}

int main()
{
    int x,y;
    cin>>x>>y;
    cout<<fastpower(x,y);
    return 0;
}