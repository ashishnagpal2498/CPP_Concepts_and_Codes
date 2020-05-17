//Cook-Off 103 February
#include<iostream>
using namespace std;
int main()
{
    int testcase;
    int n,budget;int wid,height,price;
    int max_area=0;
    cin>>testcase;
    while(testcase--)
    {   max_area=0;
        cin>>n>>budget;
        while(n--)
        {   cin>>wid>>height>>price;
            if(price<=budget)
            {
                max_area = max(max_area,wid*height);
            }
        }
        if(max_area==0)
        {
            cout<<"no tablet"<<endl;
        }
        else
        {
            cout<<max_area<<endl;
        }
    }
    return 0;
}