//Matrix Search 
#include<iostream>
using namespace std;
int main()
{   //int T;
    // cin>>T;
    // while(T--)
       int arr[35][35];
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }
        int i=0 , j=m-1;
        int key; cin>>key;
        bool flag = false;
        while(i<n&&j>=0)
    {
        if(arr[i][j]==key){
            flag = true;
            cout<<1<<endl;
            break;
        }
        else if(arr[i][j]<key) {    i++ ; }
        else
        {
            j--;
        }
    }
        if(!flag) 
        {
            cout<<0<<endl;
        }
    // }
    return 0;
}