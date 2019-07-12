//Advanced Concepts - OOPS
#include<iostream>
#include<cstring>
using namespace std;
class Car{
public:
    char *name;
    int price;
    Car()
    {
        name = NULL;
        price =0;
    }
    Car(char*n,int p)
    {
        name = new char[strlen(n)];
        strcpy(name,n);
        price = p;
    }
    //Deep Copy -
    Car(Car &X)
    {
        name = new char[strlen(X.name)];
        strcpy(name,X.name);
        price = X.price;
    }
    void print()
    {
        cout<<name<<endl<<price<<endl;
    }

    ~Car()
    {
        cout<<"Destroying Car "<<name;
        if(name!=NULL)
        {
            delete [] name;
        }
    }
    void operator+(Car&X)
    {
        char *oldname = name;
        int l1 = strlen(name);
        int l2 = strlen(X.name);
        name = new char[l1+l2+1];
        strcpy(name,oldname);
        strcpy(name+l1,X.name);
        price+=X.price;
        // Freeing the memory
        delete oldname;
    }
};
ostream& operator<<(ostream & ob,Car&X)
{
    ob<<X.name<<endl;
    ob<<X.price<<endl;
}
int main()
{
    Car A("AUDI",100);
    A.print();
    Car B(A);
    B.print();
    B.price =200;
    B.print();
    A+B;
    cout<<A<<endl;
    return 0;
}