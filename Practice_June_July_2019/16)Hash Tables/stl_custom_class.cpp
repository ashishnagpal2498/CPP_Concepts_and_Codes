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

    Fruit f2 = mymap["Mango"];
    cout<<f2.price<<endl;
    return 0;
}