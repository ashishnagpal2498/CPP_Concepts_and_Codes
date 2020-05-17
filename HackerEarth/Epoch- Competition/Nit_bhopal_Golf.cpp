//NIT - Bhopal HackerEarth challenge
#include<iostream>
using namespace std;
bool canWin(int *arr,int goal_reached,int cross_mark,int j)
{
    //base case
    if(goal_reached==cross_mark&&j==3)
    {
        return true;
    }
    if(j==3)
    {
        return false;
    }
    for(int i=j;i<3;i++)
    {
        //lets start with positive value first
        goal_reached+=arr[i];
        bool chotaans = canWin(arr,goal_reached,cross_mark,j+1);
        if(chotaans)
        {
            return true;
        }
        else
        {
            goal_reached = goal_reached - 2*arr[i];
            bool smallans = canWin(arr,goal_reached,cross_mark,j+1);
            if(smallans)
            {
                return true;
            }
        }

    }
    return false;
}
int main()
{
    int testcase;
    int cross_mark;
    //int val_hit;
    cin>>testcase;
    while(testcase--)
    {   
        int arr[3];
        cin>>cross_mark;
        cin>>arr[0]>>arr[1]>>arr[2];
        bool ans = canWin(arr,0,cross_mark,0);
        ans ? cout<<"WIN\n":cout<<"LOSE\n";
    // {   int goal_reached=0;
    //     cin>>cross_mark;
    //     for(int i=0;i<3;i++)
    //     {   cin>>val_hit;
    //         if(goal_reached<cross_mark)
    //         {
    //             goal_reached+=val_hit;
    //         }
    //         else
    //         {
    //             goal_reached-=val_hit;
    //         }
    //     }
    //     goal_reached==cross_mark ? cout<<"WIN\n" :cout<<"LOSE\n";
    } 
    return 0;
}