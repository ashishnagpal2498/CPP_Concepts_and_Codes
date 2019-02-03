#include<iostream>
#include<queue>
#include<math.h>
#include<string>
using namespace std;
string yala_numbers(queue<int>q1)
{   int val;
    string ans ="";
    while(!q1.empty())
    {
        val = q1.front();
        char ch = '0' + val;
        // cout<<ch<<endl;
        ans = ans + ch;
        q1.pop();
    }
    return ans;
}
string numbercat(int num)
{
    queue<int> q1;
    string a="";
    int digit;
    int noofdigits=0;
    while(num)
    {
        digit = num %10;
        num = num /10;
        q1.push(digit);
        noofdigits++;
    }
    int frntval;
    for(int i=0;i<noofdigits;i++)
    {
        string val = yala_numbers(q1);
        a+=val;
        frntval = q1.front();
        q1.pop();
        q1.push(frntval);

    }
    return a;
}
int main()
{
    
    int testcase;
    cin>>testcase;
    while(testcase)
    { int n;
        cin>>n;

     int newnum=0;
        while(n)
        {
            newnum = newnum*10 + n%10;
            n = n/10; 
        }
    // cout<<newnum<<endl;
    string ans = numbercat(newnum);
    // cout<<ans<<endl;
    int val;
    long long int numberformed = 0 ;
    long int powerval = pow(10,9) + 7;
    // numberformed = stoi(ans) % powerval;
   int i=0;
   // cout<<ans<<endl;
   int len= ans.length();
   // cout<<numberformed<<endl;
    while(i<len)
    {   val = ans[i]-'0';
        // cout<<val<<" ";
        numberformed = numberformed*10 + val;
        // cout<<numberformed<<"  ";
        i++;
    }
    // cout<<endl<<numberformed<<endl;
    numberformed = numberformed % powerval;
    cout<<numberformed<<endl;
    // char value;
    // for(int i=0;ans[i]!='\0';i++)
    // {

    // }
    testcase--;
    }
    return 0;
}