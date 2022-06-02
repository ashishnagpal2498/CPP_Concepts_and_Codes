// Running Median of Elements using Heaps -

#include<iostream>
#include<queue>
using namespace std;

void rebalance( priority_queue<int, vector<int>, greater<int> > &minHeap, int &leftHeapSize,
    priority_queue<int> &maxHeap, int &rightHeapSize
)
{       
    // cout<<"Before rebalance - leftHeapSize and rightHeapSize sizes "<<leftHeapSize<<" -> "<<rightHeapSize<<endl;

    while(leftHeapSize-rightHeapSize>1){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        leftHeapSize--;
        rightHeapSize++;
    }
    while(rightHeapSize-leftHeapSize > 1){
        maxHeap.push(minHeap.top());
        minHeap.pop();
        leftHeapSize++;
        rightHeapSize--;
    }
    // cout<<"After rebalance - leftHeapSize and rightHeapSize sizes "<<leftHeapSize<<" -> "<<rightHeapSize<<endl;
}
int main(){
    int q;
    cin>>q;

    int leftHeapSize,rightHeapSize; leftHeapSize = rightHeapSize = 0;

    priority_queue<int,vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;

    while(q != 0){
        // Query
        int median = INT_MAX; 
        if(!maxHeap.empty() && leftHeapSize == rightHeapSize || leftHeapSize-rightHeapSize >= 1){
            median = maxHeap.top();
            //maxHeap.pop();
            leftHeapSize = maxHeap.size();
        }
        else if(rightHeapSize-leftHeapSize == 1){
            cout<<"Here ->>"<<minHeap.top()<<endl;
            median = minHeap.top();
            //minHeap.pop();
            rightHeapSize = minHeap.size();
        }
        // Query or Pushing to Queue
        if(q == -1 ){
            cout<<median<<"\n";
        }
        else{
            
            if(median== INT_MAX || q<=median){
                maxHeap.push(q);
                leftHeapSize = maxHeap.size();
            }
            else{
                minHeap.push(q);
                rightHeapSize = minHeap.size();
            }
      
        }

        if(abs(leftHeapSize-rightHeapSize)>1){
            rebalance(minHeap,leftHeapSize,maxHeap,rightHeapSize);
        }
        cin>>q;
    }

    return 0;

}