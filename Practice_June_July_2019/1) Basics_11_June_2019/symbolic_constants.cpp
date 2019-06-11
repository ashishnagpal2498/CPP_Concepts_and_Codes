//Symbolic constant and Number
//Fahrenheit to Celsius conversion
//Type Conversion
#include<iostream>
#define PI 3.14
using namespace std;
int main()
{
   float a = 67ul;
   cout<<a<<endl;
   float b = 8L;
   cout<<b<<endl; 
cout<<sizeof(int)<<endl<<PI;
    float init,step,final;
    cin>>init>>step>>final;
   cout<<"Fahrenheit \t"<<"Celsius\n";
    for(float i=init;i<=final;i = i+ step)
    {   float val = (5*(i-32))/9;
        cout<<i<<"\t"<<val<<endl;
    }
    char y = 'B';
    cout<<endl<<y;
    cout<<endl<<(int)y<<endl;
    y = y+260;
    cout<<y;
    return 0;
}