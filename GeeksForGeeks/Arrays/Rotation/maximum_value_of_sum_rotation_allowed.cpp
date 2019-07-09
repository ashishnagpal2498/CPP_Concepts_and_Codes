//Find the maximum value of the sum
#include<iostream>
using namespace std;
int find_max_val(int *arr,int n)
{   int max_vl =0;
    for(int i=1;i<n;i++)
    {
        max_vl = arr[max_vl] < arr[i] ? i : max_vl;
    }
    return max_vl;
}
void reverse(int*arr,int start,int end)
{
    while(start<end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;

    }
    return;
}
int max_sum(int *arr,int n)
{
    int max_val_index = find_max_val(arr,n);
    //Got the index of max_val -
    cout<<max_val_index<<endl;
    reverse(arr,0,max_val_index);
    reverse(arr,max_val_index+1,n-1);
    reverse(arr,0,n-1);
    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum+= i*arr[i];
    }
    cout<<endl;
    return sum;
}

int main()
{   int n;
    cin>>n;
    int arr[10005];
    for(int i=0;i<n;i++) cin>>arr[i];
        //Maximum value of sum(i*arr[i]) - Rotation allowed -
   cout<<max_sum(arr,n);

    return 0;
}