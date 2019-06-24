//Fork C++ module 1 basics
//hello world program 
//datatypes
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
namespace myname {
    int val =30;
    class A {
    public:
        int lm;
        A()
        {
            lm =200;
        }
        void display(){cout<<lm<<endl;}
    };
}

int val = 10;
int main()
{   wchar_t a;
    int val =20;
    cout<<sizeof(a);
    long long int b;
    cout<<sizeof(b);
    // cin>>b;
    myname::A obj;
    obj.display();
    cout<< "\nAn error has occurred\n";
    cout<<val<<endl<<myname::val<<endl<<::val;
    int m,n;
    cout<<endl<<"Testing of endl v's ";
    cin>>m;
    cout<<endl;
    cin>>n;
    cout<<m<<"  "<<n<<endl;
    cin>>n;
    cout<<n;
    for(char a=126;;a++)
    {
        if(a>0&&a!=126&&a!=127&&a!=128) {cout<<"Reahed 0"; break;}//cout<<"Reached";
        else{ cout<<a<<"  ";}
    }

    // Preincrement vs post increment
    int lval=10;
    cout<<endl<<lval<<endl;
    lval = 20;
    cout<<lval;
    cout<<endl;
    cout<<"Execute both the if and else statements  ";
    if(1)
    {
        label1 : cout<<"Hello";

        goto label2;
    }
    else
    {
        goto label1;
        
        label2 : cout<<" Geeks ";


    }
    return 0;
}