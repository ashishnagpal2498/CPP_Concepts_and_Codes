//Max Heap
#include<iostream>
using namespace std;
class Max_heap{
    int arr[100];
    int size;
    void heapify(int index)
    {
        int MaxIndex = index;
        int left_index = 2*index;
        int right_index = 2*index+1;
        if(left_index<size&&arr[left_index]<arr[MaxIndex])
        {
            MaxIndex = left_index;
        }
        if(right_index<size&&arr[right_index]<arr[MaxIndex])
        {
            MaxIndex = right_index;
        }
        if(MaxIndex!=index)
        {
            swap(arr[MaxIndex],arr[index]);
            heapify(MaxIndex);
        }
    }
public:
    Max_heap()
    {
        arr[0] = -1;
        size = 1;
    }
    void push(int ele)
    {
        arr[size] = ele;
        int element_index = size;
        size++;
        int parent_element = element_index/2;
        if(parent_element>=1&&arr[element_index]<arr[parent_element])
        {
            swap(arr[parent_element],arr[element_index]);
            element_index = parent_element;
            parent_element = parent_element/2;
        }
    }
    int Max_element()
    {
        return arr[1];
    }
    bool isEmpty()
    {
        return size ==1;
    }
    void pop()
    {
        int last_ele = size -1;
        swap(arr[last_ele],arr[1]);
        size--;
        heapify(1);
    }
};
int main()
{
    Max_heap h2;
    int arr[] = {1,6,5,3,0,11,9,15};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        h2.push(arr[i]);
    }
    while(!h2.isEmpty())
    {
        cout<<h2.Max_element()<<"  ";
        h2.pop();
    }
    return 0;
}