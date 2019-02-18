//STL priority Queues - Heap -
#include<iostream>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

//Creating custom class for Comparator
//Overloading () brackets
class myCompare{
public:
    bool operator()(int a, int b)
    {
       // cout<<"In custom operator";
        return a>b;
    }
};

int main()
{
    //By default - priority queue is of type MAX HEAP
    priority_queue<int> pmax;
     //Min heap in Priority queue
    //priority_queue<int,vector<int>,greater<int>> pq;
     //Predefined comparator - greater<int> - functional header file
     priority_queue<int, vector<int>,myCompare> pq;
     int arr[] = {1,4,3,2,6,0,10,12};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<"  ";
        pq.pop();
    }
    //myCompare c;
    //c();

    return 0;
}