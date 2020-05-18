//Birthday Paradox - Probability
#include<iostream>
#define ll long long int
using namespace std;
int main()
{   float prob = 1.0;
    int n=1,day=365;
    while(prob > 0.5 );
    {
        n++;
        prob = prob * (float)(day/float(365));
        cout<<prob<<endl;
        day--;
    }
    cout<<n<<endl;
    return 0;
}