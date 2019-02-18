//Running median of array
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
int main()
{
    //Maintain two heaps- min heap and a max heap
    //1) Take two heaps
    //2) Maintain it after every insertion - if query asked - pop that
    //3) If the size of left heap - right heap > 1 pop doosre mein daal do

   
    int t = 2;
    while(t--)
    {    priority_queue< int,vector<int>, greater<int> > right_median(20,INT_MAX);
    priority_queue<int> left_median(20,INT_MIN);
    int n;
    int p=1;
    int left_size, right_size;
    left_size = right_size = 0;
    //cin>>n;
    int median=0;

        cin>>n;
        while(n!=0)
        {    
            if(n==-1)
            {       left_size = left_median.size();
                right_size = right_median.size();
                //query 
                if(left_size==right_size||left_size-right_size==1)
                {
                     median = left_median.top();
                    left_median.pop();
                    //left size will be now
                    //if the value becomes 0 then 
                    left_size= left_median.size();
                }
                else if(right_size-left_size==1)
                 {
                     median = right_median.top();
                     right_median.pop();
                    right_size = right_median.size();
                }
                 printf("%d\n",median);
        }
          else
        {
            if(median==0)
            {   left_median.push(n);
                //p++;
                median = n;
                left_size = left_median.size();
            }
            else if(n<median&&median!=0){
                left_median.push(n);
                 left_size = left_median.size();
            }
                
            else {
                right_median.push(n);
                right_size = right_median.size();
            }
            //cin>>n;
            //left_size = left_median.size();
        }

        //what if the sizes imbalance - left median heap is greater
          // Check for Imbalance
             if(left_size-right_size>1)
             {
                while(left_size-right_size>1)
                {
                    int t_ele = left_median.top();
                    left_median.pop();
                    right_median.push(t_ele);
                    left_size--;
                    right_size = right_median.size();
                }
                median = left_median.top();
             }
        if(right_size-left_size>1)
        {
            while(right_size-left_size>1)
            {
                int t_ele = right_median.top();
                right_median.pop();
                left_median.push(t_ele);
                right_size--;
                left_size = left_median.size();
            }
            median = right_median.top();
        }
          cin>>n;
    }
}

    return 0;
}