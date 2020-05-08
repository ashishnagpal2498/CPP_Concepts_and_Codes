//HackerEarth Circuits - Taxis
//Classic v/s Online Taxi-
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    float D,Oc,Of,Od,Cs,Cb,Cm,Cd;
    cin>>D>>Oc>>Of>>Od>>Cs>>Cb>>Cm>>Cd;
    float onlineFare=0.0,offlineFare=0.0;
    onlineFare = Oc+(D-Of)*Od;
    offlineFare = Cb + float(D/Cs)*Cm + D*Cd;
    //cout<<onlineFare<<" "<<offlineFare<<endl;
    onlineFare <= offlineFare ? cout<<"Online Taxi" : cout<<"Classic Taxi";
    return 0;
}