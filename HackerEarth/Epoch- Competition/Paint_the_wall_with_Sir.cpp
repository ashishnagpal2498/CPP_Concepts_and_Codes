#include<iostream>
#include<vector>
using namespace std;
int main()
{   
    int N,M,h;
    
    
    // vector<int> paint[3];
    int testcase;
    cin>>testcase;
    while(testcase>0)
    { vector<int> height;
    vector<int>color;
        int distinctcolor=0;
        cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>h;
        height.push_back(h);
    }
    for(int i=0;i<N;i++)
    {
        cin>>h;
        color.push_back(h);
    }
    // for(int i=0;i<N;i++)
    // {
    //     cout<<"Height painted"<<height[i]<<" Color used"<<color[i];
    // }
    // int previoussize=0;
    // int currsize = 0;
    for(int i=0;i<N;i++)
    {   
        // cout<<"Inside loop "<<i<<endl;    
        if((i>0&& color[i-1]!=color[i])||i==0)
        {   distinctcolor++; 
            // cout<<endl<<distinctcolor<<"Distint colors"<<endl;
        }
        // cout<<height[i];
            // for(int j=0;j<height[i];j++)
            // {   //Pushing the color into the array
            //     cout<<"Inputting - "<<i<<" Element";
            //     paint[i].push_back(color[i]);
            // }
            // cout<<endl;
            if(i>0)
            {  int temp =i;
                for(int a=i-1;a>=0;a--)
                {  
                    if(height[temp]>=height[a]&&a-1>0&&height[temp]>=height[temp-1]) distinctcolor--; //Overlapping 
                }
            }
    }
    if(distinctcolor<=0)
    {
        cout<<"1"<<endl;
    }
    else
    {
        cout<<distinctcolor<<endl;
        }
        testcase--;
    }
    return 0;
}