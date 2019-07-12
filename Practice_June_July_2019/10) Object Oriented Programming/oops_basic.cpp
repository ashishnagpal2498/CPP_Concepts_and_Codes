//Object Oriented Programming
#include<iostream>
#include <cstring>
using namespace std;
class Car{
    // int a;
    char name[20];
    int price;
public:
    Car()
    {

    }
    Car(char *n,int p)
    {
        strcpy(name,n);
        price =p;
    }
    Car(const Car &X)
    { cout<<"Copy Constructor Called"<<endl;

        strcpy(name,X.name);
        price = X.price;
    }
    void operator=(Car&X)
    {
        cout<<"Inside Copy Assignment Operator"<<endl;
        strcpy(name,X.name);
        price = X.price;
    }
    void print()
    {
        cout<<name<<endl<<price;
    }
    ~Car()
    {
        cout<<"Destructor Called  "<<name<<endl;
    }
};
int main()
{
    Car obj("BMW",1000);
    cout<<sizeof(obj);
    obj.print();
    Car B(obj);
    cout<<endl;
    B.print();
    Car C;
    C = B;
    C.print();

    //Creating a Car on heap memory -
    Car *dc = new Car("Audi",1020);
    (*dc).print();

    delete dc;
    return 0;

}