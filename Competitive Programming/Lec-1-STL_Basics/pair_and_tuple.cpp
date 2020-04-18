//pair and tuple
#include<iostream>
#include<tuple>
using namespace std;
int main()
{   
    pair<int ,int> pr1,pr2,pr3,pr4(4,5);
    //No of ways to initialize pair
    //1) Using constructor of pair class
    //2) Using assignment operator and object
    pr1 = {1,2};
    // 3) Using . operator and defining separately
    pr2.first = 7; pr2.second = 9;
    //4) Using make pair function
    pr3 = make_pair(3,6);

    tuple<int,char,bool> tp;
    tp = make_tuple(1,'c',true);
    cout<< get<2>(tp);
}