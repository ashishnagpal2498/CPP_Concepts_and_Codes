//CodeChef CodeStumble
#include<iostream>
using namespace std;
int main()
{
    int testcase;
    int lower_limit,upper_limit;
    cin>>testcase;
   
    while(testcase--)
       
        // cin>>lower_limit>>upper_limit;
        // int chocolates_init =1;
        // for(int i=1;i<=upper_limit;i++)
        // {
        //     chocolates_init+=2;

        // }
    {    
        //int choco_in_limit=0;
        cin>>lower_limit;
        cin>>upper_limit;
        int chocolates_init=1+2*(lower_limit-1);
        int increment = 2;
        // for(int i=2;i<=lower_limit;i++)
        // {
        //     chocolates_init = chocolates_init + increment;
        //     //increment = chocolates_init+2;
        // }
        int ans = 0;
        increment = chocolates_init+2;
        int x = upper_limit-lower_limit;
        for(int i=0;i<=x;i++)
        {
             ans = ans+chocolates_init;             
            int temp = increment;
            chocolates_init = increment;
            increment = increment + 2;
             
            
        }
        cout<<ans<<endl;
    }
    return 0;
}