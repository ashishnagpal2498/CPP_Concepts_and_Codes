//Spiral Print Anti-clock wise
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[105][105];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }
    
    //Spiral Print
     int top=0 , left=0,right = m-1,bottom = n-1;
     int cnt=0;
     while(top<=bottom&&left<=right)
     {
            for(int i=top;i<=bottom;i++,cnt++)
            {
                cout<<arr[i][left]<<", ";

            }
            left++;
            for(int i=left;i<=right;i++,cnt++)
            {
                cout<<arr[bottom][i]<<", ";
            }
            bottom--;
            if(cnt == n*m ){break;}
            for(int i=bottom;i>=top;i--,cnt++)
            {
                cout<<arr[i][right]<<", ";
            }
            right--;
            if(cnt == n*m ){break;}
            for(int i=right;i>=left;i--,cnt++)
            {
                cout<<arr[top][i]<<", ";
            }
            top++;
     }
     cout<<"END";
    return 0;
}