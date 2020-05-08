//circuits - cyclic shift
#include<iostream>
#include<deque>
using namespace std;
int main()
{   int T;
    cin>>T;
    while(T--)
    {char c;
        deque <int> d;
        int str;
        int n;
        cin>>str;
        cin>>n;
        cin>>c;
        long long int num=0,p=1;
        while(str)
        {   int digit = str&1;
            d.push_front(digit);
            p*=10;
            str = str>>1;
        }
        // Make 16 bit -
        // cout<<"Deque created"<<endl;
        while(d.size()!=16) d.push_front(0);
        //Do the operation
        // cout<<"Size created"<<endl;
        int i=0;
        while(i<n)
        {   i++;
            if(c=='L')
            {   long long int v = d.front();
                d.pop_front();
                d.push_back(v);
            }
            else{
                long long int v = d.back();
                d.pop_back();
                d.push_front(v);
            }
        }
        //Make number -
        p=1;
        long long int sum=0;
        while(!d.empty())
        {
            sum+= d.back()*p;
            d.pop_back();
            p*=2;
        }
        cout<<sum<<endl;
        }
        return 0;
}