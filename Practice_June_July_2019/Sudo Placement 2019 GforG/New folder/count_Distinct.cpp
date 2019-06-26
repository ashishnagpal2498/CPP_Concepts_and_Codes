//CountDistinct elements
#include<iostream>
using namespace std;
void countDistinct(int A[], int k, int n)
{
    //Your code here
    int freq_ans[102] = {0};
    bool initial_freq[102] = {0};
    // k tak 
    // for(int i=0;i<k;i++)
    // {
    //     initial_freq[arr[i]]++;
    //     // freq_ans[arr[i]]++;
    // }
    for(int i=0;i<=n-k;i++)
    {   bool initial_freq[102] = {0};
        // Window mein check -
        for(int j=i;j<k+i;j++)
        {   if(initial_freq[A[j]]==false)
                {
                    freq_ans[A[j]]++;
                    initial_freq[A[j]] = true;
                }
        }
    }
    for(int i=1;i<=100;i++)
    {
        if(freq_ans[i]!=0)
        {
            cout<<freq_ans[i]<<" ";
        }
    }
    // return 0;
}

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[105] = {0};
    for(int i=0;i<n;i++) cin>>arr[i];
    countDistinct(arr,k,n);    

    return 0;
}