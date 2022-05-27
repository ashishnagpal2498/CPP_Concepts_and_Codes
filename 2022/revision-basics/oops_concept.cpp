// OOPS concepts -

#include<bits/stdc++.h>
using namespace std;

class Car{
public:
    int price;
    char* name;
    Car(){
        price = 0;
        name = NULL;
    }

    Car(char* n,int p){

        name = new char[strlen(n)];
        strcpy(name,n);
        price = p;
    }

    void print(){
        cout<<"Name - "<<name<<" price "<<price;
    }

};
    ostream operator<<(ostream& ob, Car&C){
    ob<<C.name<<" - ";
    ob<<C.price<<endl;
}
    istream operator>>(istream& ib,Car&C){
        char temp_name[100];
        ib>>temp_name;
        C.name = new char[strlen(temp_name)];
        strcpy(C.name,temp_name);
        ib>>C.price;
    }
int main(){
    int p;
    cin>>p;
    char* arr = new char[100];
    cin>>arr;
    Car* A = new Car(arr,p);
    A -> print();
    cout<<endl;
    cout<<*A;

    Car B;
    cin>>B;
    return 0;
}