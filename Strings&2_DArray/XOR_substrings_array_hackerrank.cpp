//Xor of substrings of an array
#include<iostream>
using namespace std;
int findXor(int array[],int sz)
{       int c=0;
    for(int i=0;i<sz;i++)
    {   c = c^array[i];
    }
    return c;
}
void substrarray(int arr[],int m,int n)
{ //We have to find substrings from m to n
    int xorarray[100]={0},xorarrsize=0;
    for(int i=m;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {   int temp[100]={0},tempsz=0;
            for(int k=i;k<=j;k++)
                { temp[tempsz]=arr[k];
                    tempsz++;}
         int xorval =  findXor(temp,tempsz);
         xorarray[xorarrsize]=xorval; // Xor computed values put here 
         xorarrsize++;
        }
        
    }
    int xorvalue = findXor(xorarray,xorarrsize);
    for(int i=0;i<xorarrsize;i++)
    {
        cout<<xorarray[i]<<"  ";
    }
    cout<<endl<<xorvalue;

}
int main()
{
    int arr[100],n,k,m;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
        cin>>k>>m;
        substrarray(arr,k,m);
    return 0;
}