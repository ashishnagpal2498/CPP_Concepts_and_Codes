//Special ingredient dish
#include<iostream>
using namespace std;
// int main()
// {
//     //if the dish is unique -
//     //Bit masking ???
//     //
//     // if the string is aabca , abcd and aabbcc - ans would be 3 - 
//     //Secret ingredient comes in each string once 
//     int testcase;
//     cin>>testcase;
//     while(testcase--)
//     {   string str; int n;
//         cin>>n;
//         cin.get();
//         int incr = 0;
//         //int freq_arr[26] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
//         int freq_arr[26] ={0};
//     //cout<<freq_arr[2]<<endl;
//         for(int i =0 ;i<n;i++)
//         {   cin>>str;

//         int len = str.length();
//         //cout<<len<<endl;
//         for(int j=0;j<len;j++)
//         {
//             if(freq_arr[str[j] -'a']==incr)
//             {   //cout<<"Inside If "<<endl;

//                 //int val = freq_arr[str[j] -'a'];
//                 //val = val<<1;
//                 freq_arr[str[j] -'a']++; //val;
//                 //cout<<"Value at "<<str[j] -'a'<<"  is  "<<freq_arr[str[j] -'a']<<endl;
//             }
//         }
//         incr++;
//     }
//     int count = 0;
//     for(int i=0;i<26;i++)
//     {
//         if((freq_arr[i]/n)==0&&freq_arr[i]!=0)
//         {
//             count++;
//         }
//     }
//     cout<<count<<endl;
//     // for(int i=0;i<n;i++)
//     // {
//     //     cin>>str[i];

//     // }
//     // for(int i=0;i<n;i++)
//     // {   int len = str[i].length();
//     //     int turn =1;
//     //     for(int j=0;j<len;j++)
//     //     {   if(turn&1)
//     //         {   if(freq_arr[str[i][j]- 'a']==false)
//     //                 {
//     //                 freq_arr[str[i][j]- 'a'] = true;
//     //                 }
//     //         }
//     //         else
//     //         {
//     //             if(freq_arr[str[i][j]-'a']==true)
//     //             {
//     //                 freq_arr[str[i][j]- 'a'] = false;
//     //             }
//     //         }
//     //     }
//     //     if(n&1)
//     //     {   int count = 0;
//     //         for(int i=0;i<26;i++)
//     //         {
//     //             if(freq_arr[i])
//     //                 count++;
//     //         }
//     //         cout<<count<<endl;
//     //     }
//     //     else
//     //     {
//     //         int count = 0;
//     //         for(int i=0;i<26;i++)
//     //         {
//     //             if(!freq_arr[i])
//     //                 count++;
//     //         }
//     //         cout<<count<<endl;

//     //     }
// }
//     return 0;
//     //}
// }
int main()
{
    // int freq_arr[1005][26] = {0};
    // int n;
    // cin>>n;
    // cin.get();
    // int incr = 0;
    //  for(int i =0 ;i<n;i++)
    //      {   cin>>str;
    //         int j=0;
    //         while(str[j]!='\0')
    //         {
    //             if(freq_arr[i][j]==0)
    //             {
    //                 freq_arr[i][j]++;
    //             }
    //             j++;
    //         }

    //      }
    //      for(int i=0;i<n;i++)
    //      {

    //      }
    int testcase;
    cin>>testcase;
    while(testcase--)
    {int freq_arr[26] = {0};
     string str; int n;
        cin>>n;
        cin.get();
        int incr = 0;
       
        for(int i=0;i<n;i++)
        {    cin>>str;
            int j=0;
            while(str[j]!='\0')
            {
                if(freq_arr[str[j]-'a']==incr) freq_arr[str[j]-'a']++;
                j++;
            }
            incr++;
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(freq_arr[i]%n==0&&freq_arr[i]!=0) count++;
        }
        cout<<count<<endl;
        }
        return 0;
}