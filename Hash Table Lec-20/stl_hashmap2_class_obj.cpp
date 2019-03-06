//Hash-Maps of Class objects
#include<iostream>
#include<unordered_map>
using namespace std;
class Fruit{
public:
    string name;
    int price;
    string city;
    Fruit()
    {

    }
    Fruit(string n,int a,string c)
    {
        name = n;
        price = a;
        city = c;
    }
};
int main()
{
    unordered_map<string,Fruit> myMap;
  
    Fruit f("Mango",89,"Delhi");
     Fruit f1("Apple",100,"Abc");
    // Default constructor necessary to create an empty object
    // Garbage value
    myMap["Mango"] = f;
    myMap["Apple"] = f1;

    Fruit f2 = myMap["Mango"];
    cout<<f2.city<<endl;
    if(myMap.count("Apple"))
    {
        cout<<"Found"<<endl;
    }
    myMap.erase("Mango");
    cout<<myMap.count("Mango");

    return 0;
}
