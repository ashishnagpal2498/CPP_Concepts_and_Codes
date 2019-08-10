//Hashing - 
//Hash functions - help in mapping of key value - to corresponding pair -
// Collisions 
//hash function computing by taking a prime number and multiplying with its ascii
// Collision handling - Separate Chaining
#include<iostream>
#include "hashtable.h"
using namespace std;
int main(int argc, char const *argv[])
{
    hashtable<int> h1(11);
    h1.insert("Mango",100);
    h1.insert("Apple",910);
    h1.insert("Banana",700);
    h1.insert("Guava",400);
    h1.insert("Orange",200);
    h1.print();
    cout<<"ENTER ELEMENT TO BE SEARCHED "<<endl;
    string s;
    cin>>s;
    auto val = h1.search(s);
    if(val)
    {
        cout<<*val<<endl;
    }
    else
    {
        cout<<"NOT FOUND"<<endl;
    }
    return 0;
}