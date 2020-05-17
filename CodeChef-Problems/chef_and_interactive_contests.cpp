//Chef and Interactive contest
#include<iostream>
using namespace std;
int main()
{
    int n,val;
    cin>>n>>val;
    int num;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        num>=val ? cout<<"Good boi"<<endl : cout<<"Bad boi"<<endl;
    }
    return 0;
}