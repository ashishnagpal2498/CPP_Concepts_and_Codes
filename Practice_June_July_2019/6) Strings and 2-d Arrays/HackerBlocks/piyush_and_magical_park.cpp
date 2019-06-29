//Piyush and Magical Park
#include<iostream>
using namespace std;
int main()
{   char park[105][105];
    int n,m;
    cin>>n>>m;
    int k_strength;
    int s;
    cin>>k_strength>>s;
    int i=0,j=0;
    int max = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>park[i][j];
        }
    }
    int gain =0;
    int max_val =0;
    while(i<n&&j<m)
    {   bool flag = false;
        //Koi bhi move chalna hai toh strength will be -1
        s--;
        gain--;
        //read the character
        char ch = park[i][j];
        switch(ch)
        {
            case '.' : s -=2;
                        gain-=2;
                        break;
            case '*' : s+=5;
                        gain+=5;
                        break;
            case '#' : //Blocked - cannot move forward
                        flag = true;
                        break;                        
        }
        j++;
        if(s<0)
        {
            break;
        }
        if(j>=n||flag)
        {   if(gain>max_val)
            {
                max_val = gain;
                max = s;
            }
            gain =0;
            j = 0;
            i++; //next row
            flag = false;
        }

    }
    if(s>=k_strength) {  cout<<"Yes"<<endl; cout<<s+4;}
    else
        cout<<"No";

    return 0;
}