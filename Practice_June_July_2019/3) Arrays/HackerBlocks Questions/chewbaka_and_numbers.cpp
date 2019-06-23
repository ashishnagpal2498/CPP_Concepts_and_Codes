//chewbak and numbers
#include<iostream>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int ans =0;
    int p=1;
    while(n)
    {
        int digit = n%10;
        n = n/10;
        if(n==0&&digit==9)
        {
            //1st digit -
            //donot change the digit
            ans = ans + p*digit;
        }
        else
        {   if(digit>4)
            ans = ans + p* (9-digit);
            else
            {
                ans = ans + p*(digit);
            }
        }
        p =p*10;
    }

    cout<<ans<<endl;

    return 0;
}