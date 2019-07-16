//Cyclic Number-
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int rotations(string mapp,string str,int n)
{
    if(str==mapp)
    {   //cout<<"Abort  "<<endl;
        return 0;
    }
    int i=0;
    string str_1 = str;
    while(i<n)
    {   string temp="";
        //create temp string 
        for(int j=i+1;j<n;j++) temp+=str[j];
        for(int m=0;m<=i;m++)
        temp+=str[m];    
        //compare from tmp string
        if(temp==mapp)
        {   //cout<<"SUCCESS "<<temp<<"  "<<mapp<<endl;
            return i+1;
        }
        //copy the temp to str -

        str_1 = temp;
       // for(int l=0;l<n;l++) str[l] += temp[l];
        //cout<<"Value of STR_1  "<<str_1<<"  "<<i<<endl;
        i++;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    vector<string> str;
    cin.get();
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        str.push_back(s);
    }
    int min_count =1000000000;
    int len =str[0].length();
    for(int i=0;i<n;i++)
    {   int count = 0;
        bool flag = true;
        //take this string as parent - 
        string mapping = str[i];
        for(int j=0;j<n;j++)
        {
            int no_of_rotations = rotations(mapping,str[j],len);
         //   cout<<"No of Rotations  "<<no_of_rotations<<endl;
            if(no_of_rotations==-1)
            {
                //Cannot create string out of that - hence - this cannot be basic string
                flag = false;
                break;
            }
            else
            {
                count+=no_of_rotations;
            }
        }
        if(!flag)
        {
            //This cannot be basic string 
            //donot update the count
        }
        else
        {
            min_count = min_count > count ? count : min_count;
        }
    }
    if(min_count==1000000000) cout<<-1;
    else cout<<min_count<<endl;
    return 0;
}