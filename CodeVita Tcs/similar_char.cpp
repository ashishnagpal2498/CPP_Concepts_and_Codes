//Similar Char Tahir and M
#include<iostream>
using namespace std;
int arr[500001][27] ={0};
char str[500001];
int main(int argc, char const *argv[])
{   
    int n;
    cin>>n;
    cin>>str;
    for(int i=0;i<n;i++)
    {
        int index = str[i] - 'a' + 1;
         arr[i][index]= arr[i-1][index] + 1;
         if(i!=0)
         {      for(int j=1;j<27;j++)
            {    if(arr[i][j]!=arr[i][index])
            arr[i][j] = arr[i-1][j];
             }
        }
        // else arr[i][index]++;
    }
    // for(int i=0;i<9;i++)
    // {
    //     for(int j=1;j<27;j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<arr[8][0]<<endl;
    int q;
    cin>>q;
    int val;
    for(int i=0;i<q;i++)
    {   cin>>val;
        char ch = str[val-1];
         // cout<<ch<<endl;
        int index = ch - 'a'+1;
        // cout<<index<<endl;
        cout<<arr[val-1][index]-1<<endl;
    }
    return 0;
}