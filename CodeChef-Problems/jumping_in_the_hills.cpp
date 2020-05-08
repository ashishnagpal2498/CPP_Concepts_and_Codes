//Jumping in the hills
#include<iostream>
using namespace std;
int main()
{
    int n,u,d;
   
    int testcase;
    cin>>testcase;
    while(testcase>0)
    {  int parachute=1,position=1;
        int arr[105];
        cin>>n>>u>>d;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++)
        {
            if(arr[i]==arr[i+1])
            {
            //Height of previous hill same as next hill;
            position++;
            }
            else if(arr[i]<arr[i+1])
            {
                //next hill is taller than previous hill
                if(arr[i+1]-arr[i]<=u)
                    {
                        position++;
                    }
                else{
                //Condition failed abort= 
                    break;
                    }
            }
        else if(arr[i]>arr[i+1])
        {
            if(arr[i]-arr[i-1]<=d)
            {
                //Condition passed 
                position++;
            }
            else if(parachute==1)
            {
                //parachute used for lower building
                parachute--;
                position++;
            }
            else{
                //abort
                break;
            }
        }
    }
    if(position==n+1)
        {cout<<position-1<<endl;}
    else{cout<<position<<endl;}

    testcase--;
    }
    return 0;
}