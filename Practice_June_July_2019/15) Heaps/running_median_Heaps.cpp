//Running Median -
#include <iostream>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue<int > left_max_heap;
    priority_queue<int , vector<int> , greater<int> > right_min_heap;

    int left_size = 0 ,right_size = 0;
    int no;
    cin>>no;
    int median = INT_MAX;
    while(no!=0)
    {
        if(no==-1)
        {
            //Query -
            if(left_size-right_size==1||left_size==right_size)
            {
                //give the element , pop and reduce size -
                median = left_max_heap.top();
                left_max_heap.pop();
                left_size--;
            }
            else
            {
                median = right_min_heap.top();
                right_min_heap.pop();
                right_size--;
            }

            // Check for size -
            if(left_size-right_size>1)
            {
                //loop while it is balanced ;
                while(left_size-right_size<1)
                {
                    //pick element -
                   int ele = left_max_heap.top();
                    right_min_heap.push(ele);
                    left_max_heap.pop();
                    left_size--; right_size++;
                }
            }
            else if(right_size-left_size>1)
            {
                while(right_size-left_size<1)
                {
                    //pick element -
                   int ele = right_min_heap.top();
                    left_max_heap.push(ele);
                    right_min_heap.pop();
                    left_size++; right_size--;
                }
            }
            cout<<median<<endl;
        }
        else
        {
            //Check - if both are of same size - push into left -
            if(median==INT_MAX)
            {
                median = no;
                left_max_heap.push(no);
            }
            else if(no<median)
            {
                left_max_heap.push(no);
            }
            else
            {
                right_min_heap.push(no);
            }

            // Balance ---

            // Check for size -
            if(left_size-right_size>1)
            {
                //loop while it is balanced ;
                while(left_size-right_size<1)
                {
                    //pick element -
                   int ele = left_max_heap.top();
                    right_min_heap.push(ele);
                    left_max_heap.pop();
                    left_size--; right_size++;
                }
            }
            else if(right_size-left_size>1)
            {
                while(right_size-left_size<1)
                {
                    //pick element -
                   int ele = right_min_heap.top();
                    left_max_heap.push(ele);
                    right_min_heap.pop();
                    left_size++; right_size--;
                }
            }

            // End of Else -
        }
        cin>>no;
    }
    return 0;
}