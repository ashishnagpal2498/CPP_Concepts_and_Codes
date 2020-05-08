//Maximum distance between two opposite characters
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    char str[10005];
    //char a = 'a';
    //char z = 'z';
   // cout<<(int)z<<endl<<(int) a<<endl<<z-a;
    cin>>str;
    int maxval=0;
    for(int i=0;str[i]!='\0';i++)
    { char currchar = str[i];
        for(int j=i+1;str[j]!='\0';j++)
        {
            if(abs(currchar-str[j])==25)
            {   int ans = (j-i)<0 ? i-j:j-i;
                if(maxval<ans)
                {
                    maxval=ans;
                }
            }
        }
    }
    cout<<maxval;
    return 0;
}