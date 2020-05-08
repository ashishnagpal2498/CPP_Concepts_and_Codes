//Sequence 
#include<iostream>
using namespace std;
int main()
{       int testcase;
cin>>testcase;   
    while(testcase--)
        {int n,k,v;
        cin>>n>>k>>v;
        int sum=0;
        int a;
        for(int i=0;i<n;i++) {
            cin>>a;
            sum+=a;
        }
        int total_ele = n + k;
        int val = v*total_ele;
        int sumof_elements = val - sum;
        int ans ;
        if(sumof_elements<0) ans = -1;
        //element should be unique also;

     else {ans = sumof_elements/k;
        if(sum^ans!=sum) ans = -1;
     }
        cout<<ans<<endl;
    }
    return 0;
}