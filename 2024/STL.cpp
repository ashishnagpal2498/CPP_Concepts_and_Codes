// Online C++ STLs -->
#include <bits/stdc++.h>
using namespace std;

void printStack(stack<string> s1){
    cout<<"Stack Printing "<<endl;
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
}
int main() {
    // Write C++ code here
    int arr[5] = {1,2,3,4,5};
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    
    // Initialize Vector
    vector<int> v;
    vector<int> v2(5,1); // Size, default value
    vector<int> v5{87,3,4,1,6};
    v.push_back(5);
    v.push_back(20);
    v.push_back(13);
    cout<<"\n Front element --> "<<v.front()<<endl;
    cout<<"Back element "<<v.back()<<endl;
    
    for( auto it = v.begin(); it != v.end(); it++){
        cout<<*it<<" ";
    }
    
    // Doublely ended Queue
    // Insertion and Deletion on both the size
    deque<int> d;
    d.push_back(3);
    d.push_front(1);
    
    cout<<"\nDeque "<<d.front()<<" ";
    cout<<d.back()<<"\n";
    cout<<d[0]<<endl;
    
    
    // Doublely Linked List --> List
    // Random Access not possible --> traverse -->
    list<int> l;
    l.push_back(3);
    l.push_front(1);
    for(int i:l){
        cout<<i<<" ";
    }
    
    
    // Stack and Queue
    stack<string> s1;
    s1.push("Shreya");
    s1.push("Ashish");
    printStack(s1);
    cout<<"s1 --> size "<<s1.size()<<"\n";
    
    queue<string> q1;
    q1.push("Shreya");
    q1.push("Ashish");
    cout<<"Queue front - "<<q1.front()<<"\n";
    
    
    // Priority Queue
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;
    
    max_heap.push(32);
    max_heap.push(4);
    
    min_heap.push(9);
    min_heap.push(2);
    
    cout<<"Max Heap --> ";
    while(!max_heap.empty()){
        cout<<max_heap.top()<<" ";
        max_heap.pop();
    }
    cout<<"\n Min Heap --> ";
    while(!min_heap.empty()){
        cout<<min_heap.top()<<" ";
        min_heap.pop();
    }
    cout<<endl;
    
// ---------------     
    // SET - store unique elements - Implementation --> BST
    // Sorted values --> Slower than unordered_set
    // Complexity --> O(log n)
    
    set<int> mySet;
    mySet.insert(1);
    mySet.insert(1);
    mySet.insert(5);
    mySet.insert(6);
    cout<<"Set ";
    for(auto i: mySet){
        cout<<i<<" ";
    }
    // Erase using Iterator -->
    
    cout<<"\n";
    // Element exist or not ;
    cout<<"Count Function --> "<<mySet.count(5)<<endl;
    // Find method -->
    set<int>::iterator it = mySet.find(5);
    cout<<"Iterator value "<<*it;
    
    // --------- MAP ---------
    // Implementation --> Red Black Tree --> O(log n) complexity 
    // Use unordered_map --> O(1) --> Search
    map<int,string> myMap;
    
    myMap[1] = "SK";
    myMap[5] = "AN";
    myMap.insert({2,"Shreya"});
    cout<<"------ Map ------ \n";
    for(pair<int,string> p: myMap){
        cout<<p.first<<" --> "<<p.second<<endl;
    }
    
    return 0;
}