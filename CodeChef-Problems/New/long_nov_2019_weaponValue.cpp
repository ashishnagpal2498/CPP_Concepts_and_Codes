//codeChef long challenge
#include<iostream>
#define ArrIn for(int i=0;i<n;i++) cin>>arr[i]
using namespace std;
int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    int n;
    int freqarr[10]={0};
    char s;
    while(T--)
    {   cin>>n;
        for(int i=0;i<n;i++)
        {   for(int j=0;j<10;j++)
                {   
                    cin>>s;
                    // cout<<s;
                    freqarr[j] = freqarr[j] ^ int(s-'0');
                }   
                // cout<<endl;
        }
        int count=0;
        for(int i=0;i<10;i++)
            {   cout<<freqarr[i]<<" ";
                if(freqarr[i]) count++;}
        cout<<count<<endl;
    }
    return 0;
}