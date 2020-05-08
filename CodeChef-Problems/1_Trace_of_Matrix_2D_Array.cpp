//Trace Of Matrix
//CodeChef-Problem no 1
//2-D Array
//Sub-Matrix of A-
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[105][105];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            
            cin>>arr[i][j];
        }
    }
    int maxsum=0;
    for(int i=1;i<=n;i++)
    {   //Sorted That it controls the rows 
        for(int j=1;j<=n;j++)
        {   int sum=0;
            for(int l=j;l<=j&&l!=n;l++)
            {   
                
                sum += arr[l][l];
            }
            cout<<"Max Array vale"<<maxsum<<endl;
            if(maxsum<sum)
                {maxsum=sum;}

        }
    }
    cout<<maxsum;
    return 0;
}