//Oops Concept 
//Continued
//Shallow deep Copying
//Using of dynamic data member in classes
#include<iostream>
#include<cstring>
using namespace std;

class Car{
public:
    char *name;
    int price;
public:
    Car()
    {
        name=NULL;
        price =0;

    }
    Car(char *n,int num)
    {
        name = new char[strlen(n+1)];
        strcpy(name,n);
        price = num;
    }
    Car (Car &X)
    {   //Deep Copying here 
        //Shallow copy does this thing - 
        //name = X.name ; 
        //By this both the name pointers point to same array -
        //But we have to create a copy , create a new array and assign that to name
        //now copy the values ;
        name = new char[strlen(X.name)+1];
        strcpy(name,X.name);
        price = X.price;
    }
    void print()
    {
        cout<<name<<endl<<price<<endl;
    }

    //Operator overloading of assignment operator;
    //Deep copying
    void operator=(Car &X)
    {   //Again creating a new array and copying the contents
        name = new char(strlen(X.name)+1);
        strcpy(name,X.name);
        price = X.price;
    }

    //Now Overloading + Operator 
    // void operator+(Car &X)
    // {
    //     char *oldname = name;
    //     int l1 = strlen(name);
    //     int l2= strlen(X.name);

    //     name = new char[l1+l2+1];
    //     strcpy(name,oldname);
    //     strcpy(name+l1,X.name);
    //     price+=X.price;
    // }

Car& operator+(Car &X)
    {   cout<<"Inside + operator"<<endl;
        Car *newcar = new Car;
        int l1= strlen(name);
        int l2 = strlen(X.name);
        newcar->name = new char[l1+l2+1];
        strcpy(newcar->name,name);
        strcpy(newcar->name+l1,X.name);
        newcar->price = price +X.price;
        return *newcar;
    }

    void operator[](char *str)
    {
        cout<<str<<"is driving the car "<<name<<endl;
    }
    void operator!()
    {
        cout<<"The car  "<<name<<"  is out of stock "<<endl;
    }
    //The dynamically created memory is not deleted on its own So ,
    //Destructor used
    ~Car()
    {
        //Delete the memory assigned to the pointer
        cout<<"Destructor "<<name<<endl;
        if(name!=NULL)
        {
            delete [] name;
        }
    }
};
ostream& operator<<(ostream&ob,Car &Ab)
{
    ob<<"Printing By Ob - Name is  "<<Ab.name<<endl;
    ob<<"Printing by ob - price  "<<Ab.price<<endl;
    return ob;
}
int main()
{   
    Car A("Audi",20000);
    cout<<sizeof(A)<<endl;
    A.print();
    cout<<sizeof(A)<<endl;
    
    //Lets make a another car which is copy of car A;
    Car B(A);
    B.name[0]='C';
    A.print();
    B.print();
    Car *ab = new Car("BMW",1233);
    ab->print(); //This is how we access the data members using pointer

    Car C ;
    C = *ab;
    C.name[0] = 'T';
    C.print();
    ab->print();

//Now if i delete ab then we knw that always dynamically allocated memory is deleted;
    //so when C goes out of scope , it does not have any name as it is shallow copying
    //For that we should do deep copying in assignment operator
   delete ab;
   A+B;
   A.print();
   Car Z = A+B;
   Z.print();
   Z["Ashish"];
   //character array passed
   !Z;
   cout<<A<<B; //overloading << operator ; 
     return 0;
}