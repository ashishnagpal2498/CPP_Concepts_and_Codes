// Happy numbers -
// Represent a number in terms of digit squres till value becomes 1
#include<iostream>
using namespace std;
bool isHappy(int n)
{   int i=0;
    long long int sum =0;
    while(n!=1 && i<100005)
    {
        // Extract digits and make its square sum
        sum =0;
        while(n)
        {
            int digit = n%10;
            sum = sum + (digit*digit);
            n/=10;
        }
        n = sum;
        i++;
    }
    return i != 100005;
}
int main()
{
    int n;
    cin>>n;
    bool ans = isHappy(n);
    if(ans) cout<<"true";
    else cout<<"false";
}