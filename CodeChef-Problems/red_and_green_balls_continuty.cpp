//Maximum continus length of array
#include<iostream>
using namespace std;
int maxlength(int*arr,int n)
{   int max_so_far =0;
    int max_val = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            max_val++;
            if(max_so_far<max_val)
            {
                max_so_far = max_val;
            }
        }
        else
        {
            max_val = 0;
        }
    }
    return max_so_far;
}

int continus_ones(int*arr,int n)
{   int max_ones =0,ans =0;
    int max_conti;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {   max_ones =0;
            max_conti =0;
            arr[i] = 1;
            ans = maxlength(arr,n);
            arr[i] =0;
        }
        else{
            max_conti++;
        }
        
        if(ans>max_ones){max_ones=ans;}
    }
    return max(max_ones,max_conti);
}
int max_continuous(int*arr,int n)
{
    int start=0,exceeding=0;
    int max_so_far=0,curr_max=0;
    while(start!=n)
    {
        if(arr[start]==1)
        {
            curr_max++;
        }
        else if(arr[start]==0&&start==exceeding)
        {
            exceeding = start;
            curr_max++;

        }
        else if(arr[exceeding]==0)
        {
            
        }
        if(exceeding==n)
        {
            exceeding = start;
            if(curr_max>max_so_far)
            {
                max_so_far = curr_max;
            }
        }
    }

}
int main()
{   
    int testcase;
    cin>>testcase;
     int arr[100005];
    int n;
    while(testcase--)
   {
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<continus_ones(arr,n)<<endl;
    }
    return 0;
}