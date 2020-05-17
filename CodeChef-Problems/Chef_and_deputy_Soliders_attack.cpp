//Attack Soliders Defence and Circle
#include<iostream>
using namespace std;
int main()
{   int testcase;
    cin>>testcase;
    while(testcase--)
    {
    //Taking that a soldier can be attacked from both sides
    
    int n;
    int max_val =-1;
    int attack_val[105] = {0};
    int attack_right[105] = {0};
    int defence_val[105] = {0};
    int attack_left[105] = {0};
    cin>>n;
    for(int i=0;i<n;i++) cin>>attack_val[i];
        for(int i=0;i<n;i++) cin>>defence_val[i];
    //worst case - 
    
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            //attack val
            attack_left[i] = attack_val[n-1];

        }
        else 
        {
            attack_left[i]= attack_val[i-1];
        }
        if(i==n-1)
        {
            attack_right[i] = attack_val[0];
        }
        else
        {
            attack_right[i] = attack_val[i+1];
        }
        int newval = defence_val[i] - (attack_right[i]+attack_left[i]);
        if(newval>0)
        {   //cout<<"new value for i  "<<i<<" is  "<<newval<<endl;
           if(max_val<defence_val[i])
            max_val = defence_val[i];
        }
    }
    cout<<max_val<<endl;
    }
    return 0;
}