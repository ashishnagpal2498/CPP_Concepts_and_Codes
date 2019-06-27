//CountDistinct elements
#include<iostream>
#include<set>
using namespace std;
void countDistinct(int A[], int k, int n)
{
    //Your code here
    //int freq_ans[102] = {0};
    //bool initial_freq[102] = {0};
    // k tak 
    //set<int> numbs;
    //for(int i=0;i<k;i++)
    //{
        //initial_freq[arr[i]]++;
        // freq_ans[arr[i]]++;
      //  int s = numbs.size();
       // numbs.insert(A[i]);
       // if(numbs.size()-s>0)
       // {
        //    freq_ans[A[i]]++;
       // }
    //}
    // for(int i=0;i<5;i++)
    // {
    //     cout<<freq_ans[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=k;i<n;i++)
    // {   //bool initial_freq[102] = {0};
        
    //     // Window mein check -
        
    //     numbs.erase(A[i-k]);
    //     int s= numbs.size();
    //     set<int>:: iterator it = numbs.begin();
    //     for(int i=0;i<s;i++,it++)
    //     {
    //         freq_ans[*(it)]++;
    //     }
    //     numbs.insert(A[i]);
    //     if(numbs.size()-s>0){
    //         freq_ans[A[i]]++;

    //     }

    // }
    if(n==1&&k==1)
    {
        cout<<1;
        return;
    }
   for(int i=0;i<=n-k;i++)
        {
            set<int> s(A+i,A+k+i);                                  //copy the array to set
            // for(auto i=s.begin();i!=s.end();i++)
            //     {   cout<<*i<<" ";}
            //     cout<<endl;
                cout<<s.size()<<" ";                               //print the size
 
        }
        cout<<endl;
   
    // for(int i=1;i<=100;i++)
    // {
    //     if(freq_ans[i]!=0)
    //     {
    //         cout<<freq_ans[i]<<" ";
    //     }
    // }
    // return 0;
}

int main()
{   int T;
    cin>>T;
    while(T--)
    {   int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[105] = {0};
    for(int i=0;i<n;i++) cin>>arr[i];
    countDistinct(arr,k,n);    
    }
    return 0;
}