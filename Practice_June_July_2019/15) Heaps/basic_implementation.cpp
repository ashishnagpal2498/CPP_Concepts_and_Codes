//Heap Implementation
//Insertion - Min/Max Element and - Deletion
//Insert at last and then - parent compare -
//Deletion - 
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
class heap{
    vector<int> h;
    void heapify(int index)
    {
        int leftChild = 2*index;
        int rightChild = leftChild +1;

        //Assume the Min Index -
        int minIndex = index;

        //Check if the index Exist --------
        if(leftChild<h.size()   && h[leftChild]<h[minIndex])
        {
            minIndex = leftChild;
        }
        if(rightChild<h.size()&& h[rightChild]<h[minIndex])
        {
            minIndex = rightChild;
        }
        swap(h[minIndex],h[index]);
        if(minIndex!=index)
        {
            heapify(minIndex);
        }
    }
public:
    heap()
    {
        h.push_back(-1);
    }
    void push(int d)
    {
        h.push_back(d);
        int index = h.size()-1;
        int parentIndex = index/2;
        while(index>1&& h[parentIndex]>h[index])
        {
            swap(h[index],h[parentIndex]);
            index = parentIndex;
            parentIndex = index/2;
        }
    }
    bool isEmpty()
    {
        return h.size() == 1;
    }

    int minElement()
    {   if(!isEmpty())
        return h[1];
    }
    void pop()
    {
        int lastElementIndex = h.size() -1;
        swap(h[1],h[lastElementIndex]);
        h.pop_back();
        heapify(1);
    }

};
void printHeap(heap h1)
{
    while(!h1.isEmpty())
    {
        cout<<h1.minElement()<<" ";
        h1.pop();
    }
    cout<<endl;
}
int main(int argc, char const *argv[])
{
    heap h1;
    srand(time(0));
    for(int i=0;i<5;i++)
    {   
        int no = rand() %100;
        h1.push(no);
        cout<<no<<"  ";
    }
    cout<<endl;
    printHeap(h1);
    return 0;
}