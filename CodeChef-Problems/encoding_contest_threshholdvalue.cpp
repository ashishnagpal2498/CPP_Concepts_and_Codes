//Threshhold value and m;
#include<iostream>
#include<algorithm>
using namespace std;
//Binary search se value uthate hai
//Threshold ka function
int threshhold_fun(int *arr,int mid,int n,int m)
{
    //looping till n
    int sum=0;
    int init_sum;
    for(int i=mid;i<=n;i++)
    {
        init_sum = max(arr[i]-m,0);
        sum+=init_sum;
    }
    //cout<<sum<<endl;
    return sum;
}

pair<int,int> B_search(int *arr,int n,int th_val)
{   pair<int,int> p;
    p.first =0;
    p.second = 0;
    int beg =1,end = n;
    while(beg<=end)
    {
        int mid = (beg+end)/2;
      //  cout<<"mid is  "<<mid<<endl;
        int ans = threshhold_fun(arr,mid,n,arr[mid]);
        // if(ans==th_val)
        // {
        //     p.first = arr[mid];
        //     p.second = ans;
        //     beg=mid+1;
            
        // }
        if(ans>=th_val){
            if(arr[mid]>p.first)
            {p.first = arr[mid];
            p.second = ans;
                    } 
            beg = mid+1;
        }
       else
        {   

            end=mid-1;

        }
    }
    return p;
}

int main()
{   
    int testcase;
    cin>>testcase;
    while(testcase--)
    {   int n;
    int threshhold_val;
    cin>>n>>threshhold_val;
    int arr[100005];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    pair<int,int> ans = B_search(arr,n,threshhold_val);
    if(ans.first!=0||ans.second!=0)
    cout<<ans.first<<" "<<ans.second<<endl;
    }
    return 0;
}