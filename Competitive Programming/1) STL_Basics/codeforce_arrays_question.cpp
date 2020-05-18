// -
#include<iostream>
using namespace std;
int evenNos[100005],oddNos[100005];
bool findArr(int i,int n,int sum,int &s, int*arr)
{
    if(sum == s)
    {
        for(int j=0;j<i;j++) cout<<arr[j]<<" ";
        return true;
    }
    for(int j=i;j<n;j++)
    {
        if(s+oddNos[j]<=sum)
        {   //cout<<"Current s"<<s<<endl;
            s+= oddNos[j];
            arr[i] = oddNos[j];
            if(findArr(i+1,n,sum,s,arr))
            {
                return true;
            }
            else{
                s-=oddNos[j];
            }
        }

        //Backtrack -
    }
    return false;
}
int main()
{   for(int i=1,m=0;i<2*100005;i+=2,m++)
    {
        oddNos[m] = i;
    }
    int T;
    cin>>T;
    while(T--)
    {
        int n,sum=0,s=0;
        cin>>n;
        if((n/2)&1)
        {
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES\n";
            for(int i=0,m=2;i<(n/2);i++,m+=2)
            {   sum+=m;
                cout<<m<<" ";
            }
           // cout<<"SUm is "<<sum<<endl;
            int arr[100005];
            findArr(0,n,sum,s,arr);
            cout<<endl;
        } 
    }
}