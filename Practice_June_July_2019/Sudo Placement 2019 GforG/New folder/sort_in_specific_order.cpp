//Sort in Specific Order
#include<iostream>
#include<bits/stdc++.h>
bool mycompare(int a,int b)
{
    return a>b;
}
using namespace std;
int main()
{   int T;
    cin>>T;
    while(T--)
    {   int n;
        cin>>n;
        long long int data;
    // long long int arr[100005];
    long long int desc[100005] = {0};
    long long int asec[100005];
    int sizeofdesc = 0,sizeofasec = 0;
    // memset(asec,-1,sizeof(asec));
    
    for(int i=0;i<n;i++)
    {
        cin>>data;
        if(data&1)
        {
            //odd
            // sizeofdesc++;
            desc[sizeofdesc++] = data;
        }
        else
        {   //sizeofasec++;
            asec[sizeofasec++] = data;
        }
    }
    sort(desc,desc+sizeofdesc,mycompare);
    sort(asec,asec+sizeofasec);
    // for(int i=0;i<n;i)
    int i=0;
    while(i<sizeofdesc)
    {
        cout<<desc[i++]<<" ";
    }
    i=0;
    while(i<sizeofasec)
    {
        cout<<asec[i++]<<" ";
    }
    // for(int i=0,j=100005;i<100005;i++,j--)
    // {
    //     if(asec[i]!=0)
    //     {

    //     }
    // }
    cout<<endl;
    }
    return 0;
}