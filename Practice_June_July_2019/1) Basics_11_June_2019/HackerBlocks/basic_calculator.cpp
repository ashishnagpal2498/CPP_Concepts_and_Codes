//Basic Calculator 
#include<iostream>
using namespace std;
int main()
{
    char ch;
    cin>>ch;
    while(ch!='X'&&ch!='x')
    {   int n1,n2;
        switch(ch)
        {
            case '+' : cin>>n1>>n2;
                        cout<<n1+n2<<endl;
                        break;
            case '-' : cin>>n1>>n2;
                        cout<<n1-n2<<endl;
                        break;
            case '*' : cin>>n1>>n2;
                        cout<<n1*n2<<endl;
                        break;
            case '/' : cin>>n1>>n2;
                        cout<<n1/n2<<endl; 
                        break;
            case '%' : cin>>n1>>n2;
                        cout<<n1%n2<<endl;
                        break;
            default : cout<<"Invalid operation. Try again.\n";
        }
        cin>>ch;
    }
    return 0;
}