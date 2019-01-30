//Divisible Sub-array
#include<iostream>
using namespace std;
int main()
{   int testcase;
    cin>>testcase;
    while(testcase>0)
   { int n;int l,sumarr[10005]={0},mod[10005]={0};
    cin>>n;
    int sum=0;
    int a=1;
    for(int i=0;i<n;i++)
    {   
        cin>>l;
        sum+=l;
        sumarr[a] = sum;
        mod[a++] = sum%5;

    }
    // for(int i=0;i<=n;i++)
    // {
    //     cout<<"Sum array value "<<sumarr[i]<<"  Corresp mod "<<mod[i]<<endl;
    // }
    int count =0;
    for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(mod[i]==mod[j])
            {
                // for(int a=i;a<=j-1;a++)
                //     {cout<<arr[a]<<" ";}
                // cout<<endl;
                count++;
            }
        }
    }
    cout<<count<<endl;
    testcase--;
}

    return 0;
}