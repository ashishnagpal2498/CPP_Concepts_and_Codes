//2d array using dynamic memory allocation
#include<iostream>
#include<ctime>
using namespace std;

int main()
{
    int rows,cols;
      time_t start = time(0);
    cin>>rows>>cols;
    int* *ptr;
    //The number of row 
    //will be equal to the pounter alloted to ptr
    ptr = new int*[rows];
  
    for(int i=0;i<cols;i++)
    {
        ptr[i] = new int[cols];
    }
    int no=1;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            ptr[i][j] = no;
            no++;
        }
    }
    cout<<ptr[0][1];
    time_t end = time(0);
    cout<<end-start;
    
    int a=0,b=1,temp,n;
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {   if(i==1) {cout<<a; break;}
            cout<<b<<" ";
            temp = a+b;
            a=b;
            b=temp;
        }
        cout<<endl;
    }
    return 0;

}