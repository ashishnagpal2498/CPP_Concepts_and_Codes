//Print Series 
#include<iostream>
using namespace std;

void print_series(int n1,int n2)
{   int count =0;
    int ans;
    for(int i=1;count<n1;i++)
    {
        ans = 3*i +2;
        if(ans%n2!=0)
        {
            cout<<ans<<endl;
            count++;
        }
    }
}

int main()
{   int n1,n2;
    cin>>n1>>n2;
    print_series(n1,n2);

    return 0;
}