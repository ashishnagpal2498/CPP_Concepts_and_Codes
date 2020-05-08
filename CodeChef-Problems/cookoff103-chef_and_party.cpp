//CookOff103 
//Chef and Party 
// Strictly less members , not join
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int testcase;
   
    cin>>testcase;
  
    while(testcase--)
    {    int n;
        int arr[100005];
          int member_in_party;
          int i;
        member_in_party=0;
        cin>>n;
        for( i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        for(i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                member_in_party++;
            }
            else if(arr[i]<=member_in_party)
            {
                member_in_party++;
            }
            else{
                ;
            }
        }
        cout<<member_in_party<<endl;
    }
    return 0;
}