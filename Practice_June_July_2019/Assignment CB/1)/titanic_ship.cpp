//Assignment CB -1 
//Find the best Possible position -
#include<iostream>
#include<vector>
using namespace std;
int main()
{   
    vector<int> arr1, arr2;
    int n;
    cin>>n;
    // int num;
    for(int i=1;i<=n;i++)
    {
        arr1.push_back(i);
    }
    // for(int i=0;i<arr1.size();i++)
    // {
    //     cout<<arr1[i]<<" ";
    // }
    bool flag_arr =true ;
    
    while(true)
    {   int i=0; 
        bool flag = true;
        if(flag_arr)
        {   //cout<<"Flag array - 1 - "<<arr1.size()<<endl;
            flag_arr = false;
            // Elements are in array 1
            if(arr1.size()==1)
            {
                //Single element left cout the position and break
                cout<<arr1[0];
                break;
            }
            i=0;
            // Odd - even Places -
            while(i<arr1.size())
            {   if(flag)
                {
                // Odd place -
                //Replace kar do by -1
                //arr1[i++] = -1;
                flag = false;
                ++i;
                }
                else
                {   arr2.push_back(arr1[i]);
                    ++i;
                //Even position - no change 
                    flag = true;
                }

            }
            arr1.clear();
        }

        //Flag array False means - elements are in arr2
        else
        {  flag = true;
            // cout<<"Flag array 0 - "<<arr2.size()<<endl;
            flag_arr = true;
            //elements are in array 2
            if(arr2.size()==1)
            {
                //Print element and break;
                cout<<arr2[0];
                break;
            }
            i=0;
            // Odd - even Places -
            while(i<arr2.size())
            {   if(flag)
                {
                // Odd place -
                //Replace kar do by -1
                //arr1[i++] = -1;
                flag = false;
                ++i;
                }
                else
                {   arr1.push_back(arr2[i]);
                    ++i;
                //Even position - no change 
                    flag = true;
                }

            }
            arr2.clear();
        }
     }
     cout<<"\nAlternate way to attempt the question - BITMASking\n";
    int num = n;
    int p = 1;
    int ans;
     while(n)
     {
        if(num&p)
        {   //cout<<"Inside IF";
            ans = p;

        }
        n = n<<1;
        p = p<<1;
     }
     cout<<ans;
    return 0;
}