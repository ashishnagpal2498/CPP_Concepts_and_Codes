//Fruits sorting heap
//STL priority Queues - Heap -
#include<iostream>
#include<queue>
#include<cstring>
#include<functional>
#include<vector>
using namespace std;

class Fruit{
public:
    char name[20];
    int price;
    Fruit(char* n,int p)
    {
        strcpy(name,n);
        price = p;
    }
};
//Creating custom class for Comparator
//Overloading () brackets
class myCompare{
public:
    bool operator()(Fruit a, Fruit b)
    {   if(a.price==b.price)
        {
            //lexicographical sorting of strings
           return a.name>b.name;
        }
       // cout<<"In custom operator";
        return a.price>b.price;
    }
};

int main()
{
    Fruit f1("Mango",40);
    Fruit f2("Banana",40);
    Fruit f3("Apple",160);

    priority_queue<Fruit,vector<Fruit>,myCompare> pq;
    pq.push(f1); //Pushing object of type fruit to priority_queue
    pq.push(f2);
    pq.push(f3);
    while(!pq.empty())
    {   Fruit f = pq.top();
        cout<<f.name<<endl;
        cout<<f.price<<endl;
        pq.pop();
    }

    return 0; 
}