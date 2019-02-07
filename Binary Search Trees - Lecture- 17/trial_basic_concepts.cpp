//trial C++
#include<iostream>
using namespace std;
int main()
{
    short abc = 'a';
    cout<<abc<<endl;
    int arr[] = {1,2,3,4,5};
    //pointer to array of 5 integers
    int (*a)[5] = &arr;
    int* a1 = arr;
    //pointer to integer;
    cout<<arr<<endl<<a1;
    cout<<endl<<++a1<<endl<<a;
    cout<<endl<<++a<<endl;
    ++a;
    cout<<a1-arr<<endl;
    cout<<a-&arr<<endl;
    return 0;
    }