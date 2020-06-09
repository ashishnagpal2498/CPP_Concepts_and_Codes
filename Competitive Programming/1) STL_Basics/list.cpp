//List - functions
#include<iostream>
#include<list>
using namespace std;
void print(list<int> ab)
{
    for(auto it= ab.begin();it!=ab.end();it++)
    {
        cout<<*it<<" ";
    }
}
int main()
{   list<int> ab;
    ab.push_back(8);
    ab.push_back(9);
    ab.push_back(10);
    cout<<"List is :- ";
    print(ab);
    ab.reverse();
    cout<<endl<<"Reverse of List is :- ";
    print(ab);
    return 0;
}