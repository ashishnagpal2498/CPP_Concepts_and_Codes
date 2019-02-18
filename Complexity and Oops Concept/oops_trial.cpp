//ObjectOriented Programming
#include<iostream>
#include<cstring>
using namespace std;
class Car{
    //access specifier
    private:
    int number; //Here when number is defined as integer ,So 
    //Class object takes maximum of the datatype and divide accordingly
    //If int is not defined hence the size will be according to 1 byte
    //hence - 13 will be the size of object
    int trial;
    char name[13];
public:
    //Constructor called automatically when object created
    Car()
    {
        cout<<"Constructor called by object \n";
    }
    Car(char a[13],int n)
    {
        strcpy(name,a);
        number = n;
    }

    Car(Car &X)
    {
        //Copy constuctor are always passed by reference 
        //Becoz passing by value needs to create a copy , hence; 
        //That work is done by copy constructor so , its an ambiguity
        //
        strcpy(name,X.name);
        number = X.number;
        
        cout<<"\n Inside My Copy Constructor"<<endl;
    }
    void operator=(Car &X)
    {
        cout<<"In Copy Assignment operator "<<endl;
        strcpy(name,X.name);
        number = X.number;
    }
    
    //Member functions - Methods 
    void print()
    { cout<<endl<<"Print Func"<<endl;
        cout<<name<<endl<<number;
    }
    void addname(char *a)
    {
        strcpy(name,a);
    }
    void setnum(int n)
    {   //setter funtion
        number = n;
    }
    int getnum()
    { //getter function 

        return number;
    }
    //Destructor Calleda    argcaaaaa
    //when the object of class goes out of scope
    ~Car()
    {
        cout<<"Destructor Called"<<name<<endl;
    }
};
int main(int argc, char const *argv[])
{
    Car A; //Object of a class
    cout<<sizeof(A)<<endl;
    // A.number= 798;
    // A.name[0]='B';A.name[1]='M';A.name[2]='W';A.name[3]='\0'; //This syntax is wrong , we cannot assign the value directly
    //A.name="BMW" //Why it is Wrong ??
    //It is always done character by character hence 
    //either use string cpy or [0] = this and so on.
   char ab[] = "BMW";
    A.addname(ab);
    A.setnum(786);
    //Cannot change the value once set by object A

    // cout<<A.number<<endl<<A.name;
    //A.print();
    //Car B("Audi",798);
    //making object B using constructor;
    //constructor overloading 
    //Different parameters
    
    //B.print();
    //Car C(B); //work of default copy constructor
    //Copy constructor
   // C.print();
    //Copy constructor are called in two ways 
    // Car D = A;
    // cout<<endl;
    // D.print();
//This creates an object using copy contructor 

//but if i do this
    // cout<<endl;
     Car E;
     E=A;
     E.print();
    //now here Contructor with no parameters is taken 
    //E=A shows assignment operator
    //assignment operator ;

   //Car F = A+B;
    //F.print();
    
    //Dynamic created of object of class
    //
    Car *dc = new Car("Mustang",7823);
    //delete dc;
    dc->print();
    cout<<endl;
    //Always the dynamically allocated memory is deleted 1st and then static members;
       // Car ABC(A+B);
    return 0;
}