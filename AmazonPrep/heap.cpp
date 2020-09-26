// Heap Implementation
// Complete Bianry Tree -> left to right order
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,k;
ll arr[200005];
class minHeap{
    vector<ll> arr;
    void heapify(ll index){
        ll leftChild = 2*index;
        ll rightChild = leftChild+1;
        ll minIndex = index;

        if(leftChild < arr.size() && arr[leftChild]<arr[minIndex]){
            minIndex = leftChild;
        }
        if(rightChild < arr.size() && arr[rightChild]<arr[minIndex]){
            minIndex = rightChild;
        }
        if(minIndex != index){
            swap(arr[minIndex],arr[index]);
            heapify(minIndex);
        }
    }
public:
    minHeap(){
        arr.push_back(-1);
        // Block the 0th position
    }
    void push(ll ele){
        arr.push_back(ele);
        ll index = arr.size()-1;
        ll parent = (index)/2;

        while(index>1 && arr[index]<arr[parent]){
            swap(arr[index],arr[parent]);
            index = parent;
            parent = parent/2;
        }
    }
    ll top(){
        return arr[1];
    }
    void pop(){
        ll index = arr.size()-1;
        swap(arr[1],arr[index]);
        arr.pop_back();
        heapify(1);
    }
    bool empty(){
        return arr.size() ==1;
    }
};
// Running stream of elements -> print k elements -> **
ll* mergeKSortedArrays(ll n,ll k,ll**a){
    ll* array = new ll[n*k];
    // First of pair will store element
    // Second of pair is another pair which store index of array and curr index ->
    priority_queue<pair<ll,pair<ll,ll> >,vector<pair<ll,pair<ll,ll> > > , greater<pair<ll,pair<ll,ll> > > > p;
    for(int i=0;i<n;i++){
        p.push({a[i][0],{i,0}});
    }
    int i=0;
    while(!p.empty()&&i<n*k){
        auto f = p.top();
        p.pop();
        array[i++] = f.first;
        if(f.second.second == k-1){
            p.push({INT_MAX,{0,0}});
        }
        else{
            ll arrayIndex = f.second.first; 
            ll arrayIndexOffset = f.second.second+1;
            p.push({a[arrayIndex][arrayIndexOffset],{arrayIndex,arrayIndexOffset}});
        }
    }
    return array;
}
void printMinHeap(priority_queue<ll,vector<ll>,greater<ll> > heap)
{
    while(!heap.empty()){
        cout<<heap.top()<<" ";
        heap.pop();
    }
    cout<<endl;
}
void printMaxHeap(priority_queue<ll> heap)
{
     while(!heap.empty()){
        cout<<heap.top()<<" ";
        heap.pop();
    }
    cout<<endl;
}
// Running Median ->
// Maintain Two Heaps -> minHeap and Max Heap
void rmid(){
    priority_queue<int> left_max_heap;
    priority_queue<int,vector<int>, greater<int> > right_min_Heap;
    ll num;
    cin>>num;
    while(true){
        if(num == 0){
            return;
        }
        int leftHeapSize = left_max_heap.size();
        int rightHeapSize = right_min_Heap.size();
        // Balance Heap -> 
        while(leftHeapSize-rightHeapSize > 1){
            int ele = left_max_heap.top();
            left_max_heap.pop();
            right_min_Heap.push(ele);
            rightHeapSize++;
            leftHeapSize--;
        }
        while(rightHeapSize-leftHeapSize > 1){
             int ele = right_min_Heap.top();
            right_min_Heap.pop();
            left_max_heap.push(ele);
            leftHeapSize++;
            rightHeapSize--;
        }
        if(num == -1){
            // Query
            int median =INT_MAX;
            if(leftHeapSize >= rightHeapSize){
                median = left_max_heap.top();
                left_max_heap.pop();
                leftHeapSize--;
            }
            else{
                median = right_min_Heap.top();
                right_min_Heap.pop();
                rightHeapSize--;
            }
            cout<<median<<endl;

        }
        else{
            if(left_max_heap.empty()) {left_max_heap.push(num);leftHeapSize++;}
            else{
                if(left_max_heap.top() > num) {left_max_heap.push(num); leftHeapSize++;}
                else {right_min_Heap.push(num); rightHeapSize++;}
            }
        }
        // cout<<"Right heap -> ";
        // printMinHeap(right_min_Heap);
        // cout<<"Left Heap -> ";
        // printMaxHeap(left_max_heap);
        cin>>num;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cin>>n;
    // minHeap m;
    // ArrIn(n){
    //     cin>>arr[i];
    //     m.push(arr[i]);
    // }
    // cout<<"Min element is "<<m.top()<<endl;
    // m.pop();
    // cout<<"Min element is "<<m.top()<<endl;
    // cin>>n>>k;
    // ll** a = new ll*[n];
    // for(int i=0;i<n;i++){
    //     a[i] = new ll[k];
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<k;j++){
    //         cin>>a[i][j];
    //     }
    // }
    // ll* array = mergeKSortedArrays(n,k,a);
    // for(int i=0;i<n*k;i++){
    //     cout<<array[i]<<" ";
    // }
    while(!feof(stdin)){
        rmid();
    }
    return 0;
}    