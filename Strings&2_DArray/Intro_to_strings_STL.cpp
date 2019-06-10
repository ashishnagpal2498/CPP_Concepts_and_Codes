//Introduction to strings
#include<cstring>
#include<iostream>
using namespace std;
int main()
{   
    // string s;
    // // cin>>s;
    // getline(cin,s);
    // cout<<s;
    string a[10];
    int n;
    cin>>n;
    cin.get(); //this will eat a new line character when we press enter after n 
    for(int i=0;i<n;i++) {getline(cin,a[i]);

    }
    int largestlen=a[0].length();
    string largeststr=a[0];
    for(int i=1;i<n;i++) 
        { cout<<a[i];
            if(a[i].length()>largestlen)
            {   largestlen=a[i].length();
                largeststr=a[i];
            }
//largetest string 
        }
        cout<<"\n Largest String is "<<largeststr;
    return 0;
}