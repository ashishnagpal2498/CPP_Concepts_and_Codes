//Balls and Pit falling
#include<iostream>
using namespace std;
void position(int*holes,int n,int *arr,int m,int *no_of_balls)
{   int ans[1005];
    for(int i=0;i<m;i++)
    {   //current ball -
        bool flag=false;
        for(int j=0;j<n;j++)
        {
            if(arr[i]<=holes[j]&&no_of_balls[j]!=0)
            {   //position
                ans[i] = j+1;
                flag = true;
                no_of_balls[j]--;
                break;
            }
        }
        if(!flag)
        {   //reached point E
            ans[i] = 0;
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main(int argc, char const *argv[])
{
    int n,holes[55],m,arr[1005];
    //taking input
    cin>>n;
    int no_of_balls[55];
    for(int i=0;i<n;i++) {  cin>>holes[i]; no_of_balls[i] = i+1;}
     cin>>m;
     for(int i=0;i<m;i++) cin>>arr[i];   
    
    position(holes,n,arr,m,no_of_balls);    
    return 0;
}