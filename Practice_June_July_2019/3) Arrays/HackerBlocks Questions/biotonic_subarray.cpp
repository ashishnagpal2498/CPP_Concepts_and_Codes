///Biotonic Subarray
#include<iostream>
using namespace std;
int main()
{   int T;
    cin>>T;
    while(T--)
    {   int n;
        cin>>n;
        int arr[100005];
        for(int i=0;i<n;i++) cin>>arr[i];
        int prev,next;
        int max_val =0;
        for(int i=0;i<n;i++)
        {   int k=i;
            prev = i-1; next = i+1;
            int len =1; //Minimum length will be 1
            int prev_ele = arr[i-1];
            int cur_ele = arr[i];
            // Checking for previous Element- Sequence should be increasing
            while(prev>=0)
            {
                if(prev_ele<cur_ele)
                {
                len++;
                cur_ele = prev_ele;
                prev_ele = arr[prev-1];
                prev--;
                }
            else{
                break;
                }
            }
            int next_ele = arr[i+1];
            cur_ele = arr[i];
            while(next<n)
            {
                if(next_ele<cur_ele)
                {
                    len++;
                    cur_ele = next_ele;
                    next++;
                    next_ele = arr[next];
                }
                else
                {
                    break;
                }
            }
            if(max_val<len) max_val = len;
        }
    cout<<max_val<<endl;
    }
    return 0;
}