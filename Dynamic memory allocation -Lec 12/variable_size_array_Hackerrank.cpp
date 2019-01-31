//variable size array , Hackerrank
#include<iostream>
using namespace std;
int main()
{
    int* *ptr; //pointer to array of pointers
    int rows,cols,queries;
    cin>>rows>>queries;
    ptr = new int*[rows];
    for(int i=0;i<rows;i++)
    {
        cin>>cols;
        ptr[i] = new int[cols];
        for(int j=0;j<cols;j++)
        {   
            cin>>ptr[i][j];
        }
    }
    int a,b;
    //a and b are addresses which we need to find;
    for(int i=0;i<queries;i++)
    {
        cin>>a>>b;
        cout<<ptr[a][b]<<endl;
    }

}