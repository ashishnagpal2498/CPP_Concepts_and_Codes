// Maximum subarray sum - Kadane's Algorithm 
#include<iostream>
#include<vector>
using namespace std;
int kadanesAlgo(vector<int> & nums)
{
    int maximumSum=0,sumSoFar=0;
    int i=0;
    int flagCount = 0,smallestNum = INT_MIN;
    while(i<nums.size())
    {   sumSoFar+=nums[i];
        if(sumSoFar<0)
        {   flagCount++;
            smallestNum = max(smallestNum,nums[i]);
            sumSoFar=0;
        }
        if(maximumSum<sumSoFar) maximumSum = sumSoFar;
        i++;
    }
    if(flagCount == nums.size()) return smallestNum;
    return maximumSum;
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
    int ans = kadanesAlgo(nums);
    cout<<ans<<endl;
    return 0;
}