//Heap Implementation
//It should be a complete binary tree
//Visualise as a tree
//Heapify , compare the 3 elements and replace smallest element
//if a node is existing in heap then index must be < v.size
#include<iostream>
#include<vector>
using namespace std;
class min_heap{
    vector<int> arr;
    void heapify(int index)
    {
        int left_child= 2*index ;
        int right_child = 2*index +1;
            int minIndex = index;
        if(left_child<arr.size()&&arr[left_child]<arr[minIndex])
        {
            minIndex = left_child;
        }
        if(right_child<arr.size()&&arr[right_child]<arr[minIndex])
        {
            minIndex = right_child;
        }
        if(minIndex!=index)
        {
            swap(arr[minIndex],arr[index]);
            heapify(minIndex);
        }
    }
public:
    min_heap()
    {
        arr.push_back(-1);
    }
    void push(int d)
    {
        arr.push_back(d);
        int child_index = arr.size() - 1;
        int parent_index = child_index/2;
        //Min heap - child should be greater than parent
        while(parent_index>=1&&arr[child_index]<arr[parent_index])
        {
            swap(arr[child_index],arr[parent_index]);
            child_index = parent_index;
            parent_index = parent_index/2;
        }
    }
    int minElement()
    {
        return arr[1];
    }
    void pop()
    {
        int last_index = arr.size() -1;
        swap(arr[1],arr[last_index]);
        arr.pop_back();
        heapify(1);

    }
    //returns if heap is empty or not
    
    bool isempty()
    {
        return arr.size()==1 ;
    }
};

int main()
{   
    min_heap h1;
    int arr[] = {1,4,3,2,6,0,10,12};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        h1.push(arr[i]);
    }
    //pop the elements;
    while(!h1.isempty())
    {
        cout<<h1.minElement()<<"  ";
        h1.pop();
    }
    return 0;
}