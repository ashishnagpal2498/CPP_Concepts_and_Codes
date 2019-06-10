//Pair datatypes
#include<iostream>
#include<cstring>
using namespace std;
int main()
{    //Pair is a box which stores two elements

    pair<int,string> P1;
        pair<int,string> P2(76,"ale"); //Way to initialise value

    P1.first=100;
    P1.second="ashish";
    cout<<sizeof(P1);
    cout<<endl<<P1.first<<P1.second;
    return 0;
}