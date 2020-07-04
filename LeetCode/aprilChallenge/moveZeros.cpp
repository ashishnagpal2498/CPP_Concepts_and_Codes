// Move Zeros 
#include<iostream>
#include<vector>
using namespace std;
void moveZeros(vector<int> & nums)
{
    int i=0,j=0;
    while(i<nums.size())
    {
        if(nums[i]!=0)
        {
            swap(nums[i],nums[j]);
            j++;
        }
        i++;

    }
}
int main()
{
    int n;
    cin>>n;
    int a;
    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        nums.push_back(a);
    }
    moveZeros(nums);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}