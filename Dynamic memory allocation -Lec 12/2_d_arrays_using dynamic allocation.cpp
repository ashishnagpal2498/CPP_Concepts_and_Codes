//variable size array
#include<iostream>
using namespace std;
void DeleteArray(int **a,int n)
{
    for(int i=0;i<n;i++)
    {
        delete [] a[i];
        //this loop will delete all the rows alloted to a[i] array;
    }
    //now time to delete a;
    delete [] a;
    a=0;
}
int main()
{
    int* *ptr; //int* is the datatype of the pointer ptr
    int rows,cols;
    cin>>rows>>cols;
    //Now create an array of pointers
    ptr = new int*[rows];
    for(int i=0;i<rows;i++)
    {
        ptr[i] = new int[cols];
    }
    int no=1;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            ptr[i][j]=no;
            no++;
            cout<<ptr[i][j]<<"  ";
        }
        cout<<endl;
    }
    int a, b;
    cin>>a>>b;
    cout<<ptr[a][b];
    cout<<"Address of pointer  "<<ptr<<endl;
    DeleteArray(ptr,rows);
    cout<<" Address after deletion  "<<ptr;
    return 0;
}