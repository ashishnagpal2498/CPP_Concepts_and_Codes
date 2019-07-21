//randomised Quick sort 
#include <iostream>
#include<stdlib.h>
#include<ctime>
#define arrIn for(int i=0;i<n;i++) cin>>arr[i];
#define arrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" ";}
using namespace std;

int partition(int*arr,int s,int e)
{
    int i= s-1;
    int p = e;
    int pivot_ele = arr[p];
    for(int j=s;j<e;j++)
    {
        if(arr[j]<pivot_ele)
        { 
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[p],arr[i+1]);
    return i+1;
}

void quickSort(int*arr,int s,int e)
{
    if(s>e) return;

    int p = partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}
void shuffle(int*arr,int n)
{
    srand(time(0));
    for(int i=n-1;i>0;i--)
    {
        int index = rand()%(i+1);
        swap(arr[index],arr[i]);
    }
}
int arr[100005];
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    arrIn;
    // arrOut;
    // cout<<endl;
     shuffle(arr,n);
    quickSort(arr,0,n-1);
    // arrOut;
    // srand(time(0));
    // cout<<endl<<rand()%100<<"  "<<rand()%100;
    // cout<<endl;
   
    arrOut;
    return 0;
}