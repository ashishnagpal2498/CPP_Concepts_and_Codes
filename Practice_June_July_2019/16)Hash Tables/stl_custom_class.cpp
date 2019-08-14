//hashMap of Custom class object
#include<iostream>
#include<unordered_map>
using namespace std;
class Fruit{
public:
    string name;
    int qty;
    int price;
    Fruit(){

    }
    Fruit(string n,int q,int p)
    {
        name = n;
        qty = q;
        price = p;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    unordered_map<string,Fruit> mymap;
    Fruit f("Mango",10,100);
    mymap[f.name] = f;
    Fruit fa("Apple",10,123);
    mymap[fa.name] = fa;

    Fruit f2 = mymap["Mango"];
    cout<<f2.price<<endl;
    //COUNT FUNCTION
    
    cout<<mymap.count("Mango")<<endl;
    mymap.erase("Apple");
    if(mymap.count("Apple")!=0)
    {
        cout<<"FOUND "<<mymap["Apple"].price<<endl;
    }
    else
    {
        cout<<"NOT FOUND "<<endl;
    }
    
    
    return 0;
}