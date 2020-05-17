//Attendance CodeChef
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(int argc, char const *argv[])
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {   
        int n;
        cin>>n;
        map<string,int> mymap;
        string first_name[101];
        string last_name[101];
        for(int i=0;i<n;i++)
        {
            cin>>first_name[i];
            cin>>last_name[i];
            mymap[first_name[i]]++;
        }
        for (int i = 0; i < n; ++i)
        {
            /* code */
            cout<<first_name[i]<<" ";
            if(mymap[first_name[i]]>1)
            {
                cout<<last_name[i];
            }
            cout<<endl;
        }
    }
    return 0;
}