//class vector
//which takes infinite input
//push_back()
//pop_back()
//constructor  copy ctor
//cout<<v;
//v[i] it should print ith element
//cin>>
#include<iostream>
using namespace std;
class Vector{
public:
    int *arr;
    int size;
    int capacity;
public:
    // Vector()
    // {
    //     arr = new int[4];
    //     capacity = 4;
    //     size = 0;
    //     for(int i=0;i<4;i++) arr[i]=-1;
    // }
    Vector(int n=4)
    {
        arr = new int [n];
        // int rem = n%4; //we are taking deafult as 4;
        capacity = n;
        size =0;
        // for(int i=0;i<n;i++)
        // {
            // arr[i] = -1;
        // }
    }
    Vector(Vector &X)
    {   //int len = length(X.arr);
        arr = new int [X.capacity];
        capacity = X.capacity;
        size =X.size;
        //Deep copying 
        for(int i=0;i<size;i++)
        {
            arr[i]= X.arr[i];
        }
    }

    // int length(int *arr)
    // {   int count=0;
        // for(int i=0;arr[i]!=-1;i++)
        // {   cout<<"length function called"<<endl;
            // count++;
        // }
        // return count;
    // }
    void push_back(int n)
    {
        // int len = length(arr);
        if(size == capacity)
        {
            //Expand the array 
            int *oldarr = arr;
            arr = new int [2*size];
            //now copying the previous elements;
            for(int i=0;i<size;i++)
            {
                arr[i] = oldarr[i];
            } //this will copy the elements of old array to new array 
            capacity = 2*size;
        }
        arr[size++] = n;
    }
    void pop_back()
    {
        // int len = length(arr);
        //Shrink - 
        if(size>=0)
        {size--;}
        // arr[len] = -1;
    }
    void operator[](int i)
    {
        cout<<arr[i]<<endl;
    }

};
ostream& operator<<(ostream&os,Vector& V)
{
    for(int i=0;i<V.size;i++)
    {
        cout<<V.arr[i]<<"  ";
    }
    cout<<endl;
}
int main()
{
    Vector V;
    V.push_back(1);
    V.push_back(3);
     V.push_back(2);
       V.push_back(7);
       cout<<V.capacity;
      cout<<V<<endl;
        V.push_back(6);
    cout<<V;
    cout<<V.capacity;
    return 0;
}