//STL - Heap and Its Implementation
#include<iostream>
#include<vector>
#include<functional>
#include<queue>
#include<cstring>
using namespace std;
class myCompare{
public:
    bool operator()(int a,int b)
    {
        return a>b;
    }
};

//There are some fruits - Heaping them on the basis of 
class Fruits{
public:
    char fruit_name[20];
    int price;
    Fruits(char * n=NULL,int p=0)
    {
        strcpy(fruit_name,n);
        price = p;
    }
};
class Fruit_functor{
public:
    bool operator()(Fruits A,Fruits B)
    {
        if(A.price==B.price)
        {
            return A.fruit_name>B.fruit_name;
        }
        return A.price<B.price;
    }
};
int main()
{
    //By default heap - MAX HEAP -
    //To convert this to min heap we either use - by deafult functions defined 
    //Or create a class comparator;
    //user - defined comparator is created by creating a class and overloading
    // the operator () class serving as function funtor
    priority_queue<int> pmax;
    priority_queue<int,vector<int>,greater<int>> pmin_default;
    priority_queue<int,vector<int>,myCompare> pmin_userdefined;
    for(int i=1;i<6;i++)
    {   pmin_default.push(i*i);
        pmin_userdefined.push(i*i);
        pmax.push(i*i);
    }
    while(!pmax.empty())
    {
        cout<<pmax.top()<<"  ";

        pmax.pop();
    }
    cout<<endl;
     while(!pmin_default.empty())
    {
        cout<<pmin_default.top()<<"  ";
        
        pmin_default.pop();
    }
    cout<<endl;
     while(!pmin_userdefined.empty())
    {
        cout<<pmin_userdefined.top()<<"  ";
        
        pmin_userdefined.pop();
    }
    cout<<endl;
    priority_queue<Fruits,vector<Fruits>,Fruit_functor> f1;
    Fruits A("Mango",80) , B("Apple",73) ,C("Banana",80), D("Grapes",73);
    f1.push(A);
    f1.push(B);
    f1.push(C);
    f1.push(D);
    while(!f1.empty())
    {   Fruits t = f1.top();
        cout<<t.fruit_name<<endl;
        f1.pop();
    }
    return 0;
}