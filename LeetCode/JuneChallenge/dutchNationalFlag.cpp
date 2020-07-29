// Dutch national flag - 
#include<iostream>
#include<vector>
using namespace std;
void sortColors(vector<int> & nums)
{
    int i=0,m=0,h=nums.size()-1;
    while(m<=h)
    {
        if(nums[m] == 0)
        {
            swap(nums[i],nums[m]);
            m++; i++;
        }
        else if(nums[m] == 2)
        {   // element still remaining to be processed -> 
            swap(nums[m],nums[h]);
            h--;
        }
        else{
            m++;
        }
    }
}
int main()
{
    int n,a;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {   
        cin>>a;
        nums.push_back(a);
    }    
    sortColors(nums);
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<endl;
    }
    return 0;
}