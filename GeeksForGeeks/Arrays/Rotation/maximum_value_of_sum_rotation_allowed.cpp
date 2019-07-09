//Find the maximum value of the sum
#include<iostream>
using namespace std;
// int find_max_val(int *arr,int n)
// {   int max_vl =0;
//     for(int i=1;i<n;i++)
//     {
//         max_vl = arr[max_vl] < arr[i] ? i : max_vl;
//     }
//     return max_vl;
// }
// // Wrong - 
// ///////////////////---------------------->>>>>>>
// void reverse(int*arr,int start,int end)
// {
//     while(start<end)
//     {
//         swap(arr[start],arr[end]);
//         start++;
//         end--;

//     }
//     return;
// }
// int max_sum(int *arr,int n)
// {
//     int max_val_index = find_max_val(arr,n);
//     //Got the index of max_val -
//     // cout<<max_val_index<<endl;
//     reverse(arr,0,max_val_index);
//     reverse(arr,max_val_index+1,n-1);
//     reverse(arr,0,n-1);
//     int sum =0;
//     for(int i=0;i<n;i++)
//     {
//         sum+= i*arr[i];
//     }
//     cout<<endl;
//     return sum;
// }
//------------------> WORNG ANSSS

// 

//Calculate sum for once and then compute the other sums using the previous sum-
pair<int,int> arr_Sum(int*arr ,int n)
{
    int sum=0;
    int curVal =0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        curVal+= i*arr[i];
    }
    return make_pair(sum,curVal);
}

int max_valRotation(int*arr,int n)
{   //O(n)
    //Rotation is taken from backward to forward -

    pair<int,int> Arr_vals= arr_Sum(arr,n);
    int arr_Sum = Arr_vals.first;
    int maxVal = Arr_vals.second;
    int curVal = maxVal;
    for(int i=1;i<=n-1;i++)
    {
         curVal = curVal + arr_Sum - (n)*arr[n-i];
         if(maxVal<curVal)
         {
            maxVal = curVal;
         }
    }
    return maxVal;
}

int maxSum(int arr[], int n);  
int findPivot(int arr[], int n); 
  
// function definition 
int maxSum(int arr[], int n)  
{ 
    int sum = 0; 
    int i; 
    int pivot = findPivot(arr, n); 
  
    // difference in pivot and index of  
    // last element of array 
    int diff = n - 1 - pivot;  
    for(i = 0; i < n; i++) 
    { 
        sum= sum + ((i + diff) % n) * arr[i]; 
    } 
    return sum; 
} 
  
// function to find pivot 
int findPivot(int arr[], int n) 
{ 
    int i; 
    for(i = 0; i < n; i++) 
    { 
        if(arr[i] > arr[(i + 1) % n]) 
            return i; 
    } 
} 

int maxSumNew(int arr[], int n) 
{ 
    // Compute sum of all array elements 
    int cum_sum = 0; 
    for (int i=0; i<n; i++) 
        cum_sum += arr[i]; 
  
    // Compute sum of i*arr[i] for initial 
    // configuration. 
    int curr_val = 0; 
    for (int i=0; i<n; i++) 
        curr_val += i*arr[i]; 
  
    // Initialize result 
    int res = curr_val; 
  
    // Compute values for other iterations 
    for (int i=1; i<n; i++) 
    { 
        // Compute next value using previous  
        // value in O(1) time 
        int next_val = curr_val - (cum_sum - arr[i-1]) 
                       + arr[i-1] * (n-1); 
  
        // Update current value 
        curr_val = next_val; 
  
        // Update result if required 
        res = max(res, next_val); 
    } 
  
    return res; 
} 

int main()
{   int n;
    cin>>n;
    int arr[10005];
    for(int i=0;i<n;i++) cin>>arr[i];
        //Maximum value of sum(i*arr[i]) - Rotation allowed -
   // cout<<max_sum(arr,n);
       cout<< max_valRotation(arr,n);
    cout<<endl<<maxSum(arr,n);
    cout<<endl<<maxSumNew(arr,n);
    return 0;
}