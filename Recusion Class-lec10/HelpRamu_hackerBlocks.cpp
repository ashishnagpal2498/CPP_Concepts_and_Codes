//HELP RAMU
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int c1,c2,c3,c4;
    int n,m,testcase;
    cin>>testcase;
    vector<int> output;
    vector<int> rickshawtimes;
    vector<int> cabtimes;
    int ele;
    while(testcase>0)
    {    cin>>c1>>c2>>c3>>c4;
        cin>>n>>m;
       int ans1=0,ans2=0,ans3=0,ans4=0,finalans=0,i;
        //n- no of rickshaws
        //m - no of cabs;
        for( i=0;i<n;i++)
            {cin>>ele;
                rickshawtimes.push_back(ele);
            } //No of times input Rickshaw used;
            for( i=0;i<m;i++)
             {       cin>>ele;
                    cabtimes.push_back(ele);
             } //No of times input Cabs;
            for( i=0;i<n;i++)
            {
                ans1 = ans1 + min(c1*rickshawtimes[i],c2);
            }
            ans2 = min(ans1,c3);
            for( i=0;i<m;i++)
            {
                ans3 = ans3 + min(c1*cabtimes[i],c2);
            }
            ans4 = min(ans3,c3);
           finalans= min(ans2+ans4,c4);
           output.push_back(finalans);
           testcase--;
    }
    for(i=0;i<output.size();i++)
        {cout<<output[i]<<endl;}
    return 0;
}