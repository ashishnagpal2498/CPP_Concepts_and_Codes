//paper Sheets
#include<iostream>
using namespace std;
int max_div(int n)
{   int p = 1;
    while(p*2<=n)
    {
        p = p+1;
    }
   // cout<<"p is "<<p<<endl;
    p=p-1;
    return p;
// {    int p=1;
//     int ans =1;
//     int num = n;
//     while(n)
//     {
//         if(num&p){
//             ans =p;
//         }
//         p = p<<1;
//         n = n>>1;
//     }
//    return ans; 
}
int fold_count(int h,int w,int h1,int w1)
{
    int diff_h = h-h1;
    int diff_w = w-w1;
    int count =0;
     if(diff_h!=1)
    {    while(diff_h)
    {
        int max_divisibility = max_div(diff_h);
        max_divisibility*=2;
        diff_h-=max_divisibility;
        count++;
        if(diff_h==1)
        {
            count++;
            break;
        }
        } 
    }
    else
    {   //cout<<"Else part of h"<<endl;
      count++;
    }   
    // }
    
    if(diff_w!=1)
     {  while(diff_w)
    {
        int max_divisibility = max_div(diff_w);
        //cout<<"Max max_divisibility  "<<max_divisibility<<endl;
        max_divisibility*=2;
        diff_w -= max_divisibility;
        count++;
        if(diff_w==1)
        {
            count++;
            break;
        }
    }
    }
    else
    {   //cout<<"else part of w"<<endl;
        count++;
    }
    return count;
}

int main()
{
    int h,w,h1,w1;
    cin>>h>>w>>h1>>w1;
    cout<<fold_count(h,w,h1,w1);
    // cout<<max_div(5);
    return 0;
}