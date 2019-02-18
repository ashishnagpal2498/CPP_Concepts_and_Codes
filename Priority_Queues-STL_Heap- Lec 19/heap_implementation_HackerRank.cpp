#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class min_heap{
    vector<int> arr;
    void heapify(int index)
    {
        int mIndex = index;
        int left_child = 2*index;
        int right_child = 2*index+1;
        if(left_child<arr.size()&&arr[left_child]>arr[mIndex])
        {
            mIndex = left_child;
        }
        if (right_child < arr.size() && arr[right_child] > arr[mIndex]) {
          mIndex = right_child;
        }
        if(mIndex!=index)
        {
            swap(arr[index],arr[mIndex]);
            heapify(mIndex);
        }
    }
    public:
    min_heap()
    {
        arr.push_back(-1);
    }
    void push(int a)
    {
        arr.push_back(a);
        int child_index = arr.size()-1;
        int parent_index = child_index/2;
        while(parent_index>=1&&arr[child_index]<arr[parent_index])
        {
            swap(arr[child_index],arr[parent_index]);
            child_index = parent_index;
            parent_index = parent_index/2;
        }
    }
    
    bool empty()
    {
        return arr.size() ==1;
    }
    int top()
    {   if(!empty())
        {return arr[1];}
        return -1;
    }
    void pop(int n)
    {   int ind;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==n)
            {
                ind = i;
                break;
            }
        }
        int last_index = arr.size()-1;
        swap(arr[ind],arr[last_index]);
        swap(arr[ind],arr[1]);
        arr.pop_back();
        heapify(1);
    }
};

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    min_heap h1;
    int n;
    cin>>n;
    int q;
    int val;
    for(int i=0;i<n;i++)
    {
        cin>>q;
        switch(q)
        {
            case 1 : cin>>val;
                        h1.push(val);
                        break;
            case 2 : cin>>val;
                        h1.pop(val);
                        break;
            case 3 : cout<<h1.top()<<endl;
        }
    }
    return 0;
}
