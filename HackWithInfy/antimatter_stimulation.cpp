//Hackwith Infy 
//Heap Implementation
//It should be a complete binary tree
//Visualise as a tree
//Heapify , compare the 3 elements and replace smallest element
//if a node is existing in heap then index must be < v.size
// Heap is a data structure - as array | visualized as tree - 
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
    int size()
    {
        return arr.size();
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
{   //Complete BT - filling start from left - 
    min_heap h1;
    //int arr[1005];
    int n;
    cin>>n;
    int data;
    for(int i=0;i<n;i++)
    {   cin>>data;
        h1.push(data);
    }
    //pop the elements;
     int min_ele = 10e8;
    while(!h1.isempty())
    {   //cout<<h1.minElement()<<" ";
           int element1 = h1.minElement();
        h1.pop();
        //cout<<element1<<" ";
        min_ele = min_ele > element1 ? element1 : min_ele;
        if(h1.size()!=1)
        {   int element2 = h1.minElement();
        //h1.pop();
            //cout<<element2<<endl;
            int diff = element2 - element1;
            min_ele = min_ele > diff ? diff : min_ele;
            }
        }
    
    cout<<min_ele<<endl;
    return 0;
}