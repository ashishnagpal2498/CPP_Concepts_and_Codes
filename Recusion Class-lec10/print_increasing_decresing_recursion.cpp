//Print in increasing or decresing order Recursion
#include<iostream>
using namespace std;
void printIncr(int n)
{   if(n==0){return;}
    printIncr(n-1);
    cout<<n<<"   ";
    return;
}
void printDesc(int n)
{
    if(n==0) return;

     cout<<n<<"   ";
    printDesc(n-1);
}

int main()
{
    printIncr(5);
    cout<<endl;
    printDesc(5);
    return 0;
}