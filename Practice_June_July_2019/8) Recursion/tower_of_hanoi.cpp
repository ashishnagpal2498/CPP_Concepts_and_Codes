//Tower of Hanoi
#include<iostream>
#include<vector>
using namespace std;
void tower_of_hanoi(int n,char start,char destination,char helper)
{
    //base case -
    if(n==1)
    {
        cout<<"move the ring "<<n<<" from "<<start<<" to "<<destination<<endl;
        return;
    }

    //recursive case
    tower_of_hanoi(n-1,start,helper,destination);
    cout<<"move the ring "<<n<<" from "<<start<<" to "<<destination<<endl;
    tower_of_hanoi(n-1,helper,destination,start);
}
int main(int argc, char const *argv[])
{
    char start ='A',helper='C',destination='B';
    int n;
    cin>>n;
    // for(int i=n;i<0;i--)
    // {
        // start.push_back(i);
    // }
    tower_of_hanoi(n,start,destination,helper);
    return 0;
}