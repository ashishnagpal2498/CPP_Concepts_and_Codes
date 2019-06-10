//To find out substrings of a given string
#include<iostream>
using namespace std;
void substrarray(int arr[],int m,int n)
{ //We have to find substrings from m to n
    for(int i=m;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int k=i;k<=j;k++)
                {cout<<arr[k]<<",";}
            cout<<endl;
        }
        
    }

}
void substrings(char str1[])
{
    for(int i=0;str1[i]!='\0';i++)
    {
        for(int j=i;str1[j]!='\0';j++)
        {
            for(int k=i;k<=j;k++)
            {
                cout<<str1[k];
            }
            cout<<endl;
        }
    }
}
int main()
{   //char str[100];
    //cin.getline(str,100);
    //substrings(str);
    int arr[100],n,k,m;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
        cout<<endl;
    cin>>k>>m;
    substrarray(arr,k,m);
    return 0;
}