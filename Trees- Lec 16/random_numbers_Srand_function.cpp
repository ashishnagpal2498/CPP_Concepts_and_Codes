// Srand function
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    srand(NULL);
    cout<<"Random no is  "<<rand()%100<<endl;
    return 0;
}