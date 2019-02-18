//Implementation _MaxHeap 
#include<iostream>
#include<vector>
using namespace std;
class Max_heap{
    vector<int> arr;
    void heapify(int index)
    {
        int leftchild_index = 2*index ;
        int rightchild_index = 2*index+1;
        int max_index = index;
        if(leftchild_index<arr.size()&&arr[leftchild_index]>arr[max_index])
        {
            max_index = leftchild_index;
        }
         if(rightchild_index<arr.size()&&arr[rightchild_index]>arr[max_index])
        {
            max_index = leftchild_index;
        }
        if(max_index!=index)
        {
            swap(arr[max_index],arr[index]);
            heapify(max_index);
        }
    }

public:
    int max_val()
    {
        return arr[1];
    }
    Max_heap()
    {
        arr.push_back(-1);
    }
    void push(int d)
    {
        arr.push_back(d);
        int child_index = arr.size() -1;
        int parent_index = child_index/2;
        while(parent_index>=1&&arr[child_index]>arr[parent_index])
        {
            swap(arr[child_index],arr[parent_index]);
            child_index = parent_index;
            parent_index = parent_index/2;
        }
    }
    void pop()
    {
        int last_index = arr.size()-1;
        swap(arr[1],arr[last_index]);
        arr.pop_back();
        heapify(1);
    }
    bool empty()
    {
        return arr.size() ==1;
    }
};
int main()
{   Max_heap h1;
    int arr[] = {78,12,1,9,6,4,5,88};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        h1.push(arr[i]);
    }
    cout<<h1.max_val()<<endl;
    while(!h1.empty())
    {
        cout<<h1.max_val()<<"  ";
        h1.pop();
    }
    return 0;
}