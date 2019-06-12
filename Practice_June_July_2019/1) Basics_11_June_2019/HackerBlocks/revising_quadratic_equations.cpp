//Quadratic Equations -
//Coefficients - given , Nature of roots
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    float d = (b*b) - 4*a*c;
    float ans;
    float fac = 2*a;
    if(d==0)
    {
        cout<<"Real and Equal\n";
        //d = sqrt(d);
        ans = (-b) / fac;
        cout<<ans<<" "<<ans;
        //ans = (-b - d) /fac;
        //cout<<ans<<endl;
    }
    else if(d>=0)
    {
        cout<<"Real and Distinct\n";
        d = sqrt(d);
        ans = (-1*b - d) / fac;
        cout<<ans<<" ";
        ans = (-1*b + d) /fac;
        cout<<ans<<endl;
    }
    else
    {
        cout<<"Imaginary";
    }

    return 0;
}