//Tower of hanoi -
#include<iostream>
using namespace std;
void tower_of_hanoi(int n,char start,char helper,char destination)
{
    if(n==1)
    {
        cout<<"Moving ring "<<n<<" from "<<start<<" to "<<destination<<endl;
        return;
    }
    tower_of_hanoi(n-1,start,destination,helper);
    //Assume that all the pics are moved from start to helper
    cout<<"Moving ring "<<n<<" from "<<start<<" to "<<destination<<endl;
    tower_of_hanoi(n-1,helper,start,destination);
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    tower_of_hanoi(n,'A','C','B');
    return 0;
}