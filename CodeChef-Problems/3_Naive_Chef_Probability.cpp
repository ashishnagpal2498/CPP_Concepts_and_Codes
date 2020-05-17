//Naive Chef , Probability
#include<iostream>
using namespace std;
int main()
{
    int n,A,B;
    int testcase;
    cin>>testcase;
    
    while(testcase>0)
    { int ele;
    int frequency[10005]={0};
    float probab[10005];
    cin>>n>>A>>B;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        frequency[ele-1]++;

    }
    for(int i=0;i<n;i++)
    {
        probab[i] = (double) frequency[i] /n;
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<frequency[i]<<"   "<<probab[i]<<endl;
    // }
    double ans;
        ans= (double) probab[A-1] *probab[B-1];
        cout<<ans<<endl; 
        testcase--;
    }
    return 0;
}