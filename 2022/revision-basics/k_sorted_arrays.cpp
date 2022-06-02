// K sorted Arrays 

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int arr1[] = {1,3,4,7};
    int arr2[] = {2,5,9,10,11};
    int arr3[]= {0,5,6,8,12,14,19};
    int k = 3;
    int n1 = sizeof(arr1)/sizeof(int);

    int n2 = sizeof(arr2)/sizeof(int);

    int n3 = sizeof(arr3)/sizeof(int);
    priority_queue<pair<int,char>,vector<pair<int,char> >, greater<pair<int,char> > > minHeap;
    for(int i=0;i<k;i++){
        // store here elements; along with index- 
        minHeap.push({0,(char)'A'+i});
    }
    vector<int> ans;
    int count = 0;
    while(count < n1+n2+n3){
        // Take out the top element ->
        pair<int,char> topElement = minHeap.top();
        minHeap.pop();

        // Index is at topElement -> first
        switch(topElement.second){
            case 'A' : ans.push_back(arr1[topElement.first]);
                        topElement.first++;
                        if(topElement.first == n1){
                            topElement.first = INT_MAX;
                        }
                        break;
            case 'B' : ans.push_back(arr2[topElement.first]);
                        topElement.first++;
                        if(topElement.first == n2){
                            topElement.first = INT_MAX;
                        }
                        break;
            case 'C' : ans.push_back(arr3[topElement.first]);
                        topElement.first++;
                        if(topElement.first == n3){
                            topElement.first = INT_MAX;
                        }
                        break;
            default: break;            

        }
        minHeap.push({topElement.first,topElement.second});
        count++;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}