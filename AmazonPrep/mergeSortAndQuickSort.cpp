// Merge Sort And Quick Sort
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
void merge(ll* arr,ll s,ll m,ll e){

    int i,j,k,
    n1 = m-s+1,
    n2 = e-m;

    int a1[n1],a2[n2];

    // Copy Arrays
    for(i=0;i<n1;i++) a1[i] = arr[s+i];
    for(i=0;i<n2;i++) a2[i] = arr[m+1+i];

    i=0;
    j=0;
    k=s;
    while(i<n1 && j<n2){
        if(a1[i]>a2[j]){
            arr[k++] = a2[j++];
        }
        else{
            arr[k++] = a1[i++];
        }
    }
    while(i<n1){
        arr[k++] = a1[i++];
    }
    while(j<n2){
        arr[k++] = a2[j++];
    }
}
void mergeSort(ll *arr,ll s,ll e){
    if(s < e ){
        int mid = s + (e-s)/2;

        mergeSort(arr,s,mid);
        mergeSort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
}
int partition1(ll* arr,ll s,ll e){

    int pEle = arr[e];

    int i = s-1;

    for(int j= s;j<=e-1;j++){
        if(arr[j]<pEle){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;

}
int partition2(ll* arr,ll s,ll e){
    int pivot = arr[s];

    int j = e+1;
    // All elements greater to pivot will come to its right
    for(int i=s+1;i<=e;i++){
        if(arr[i]>pivot){
            j--;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[s],arr[j-1]);
    return j-1;
}
void quickSort(ll* arr,ll s,ll e){
    if(s<e){
        int partitionIndex = partition2(arr,s,e);

        quickSort(arr,s,partitionIndex-1);
        quickSort(arr,partitionIndex+1,e);
    }
}
void randomize(ll* arr,ll n){
    srand(time(0));
    for(int i=0;i<n;i++){
        int index = rand()%n;
        swap(arr[index],arr[i]);
    }
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cin>>n;
    ArrIn(n) cin>>arr[i];
    mergeSort(arr,0,n-1);
    ArrOut(n);
    cout<<endl;
    randomize(arr,n);
    ArrOut(n);
    cout<<endl;
    quickSort(arr,0,n-1);
    ArrOut(n);
    return 0;
}    