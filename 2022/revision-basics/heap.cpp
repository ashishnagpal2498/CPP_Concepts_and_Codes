// Heap -

#include<iostream>
#include<queue>
using namespace std;

class Fruits{
public:
    int price;
    string name;
    Fruits(int p,string n){
        price = p;
        name = n;
    }
};

class comp{
public:
    bool operator()(Fruits& A, Fruits&B){
        if(A.price == B.price ) return A.name.size() < B.name.size();
        else if(A.price < B.price) return A.price <B.price;
        else A.price > B.price;
    }
};

int main(){
    priority_queue<Fruits,vector<Fruits>, comp> p;

}