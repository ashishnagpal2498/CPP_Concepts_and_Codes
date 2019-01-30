//Subsequences Using recursion
#include<iostream>
#include<string>
using namespace std;

int Subsequences_count(string input,string output)
{   static int count = 0;
    if(input.length()==0)
    {   count++;
        return count;
    }
    
    Subsequences_count(input.substr(1),output);
    Subsequences_count(input.substr(1),output +input[0]);
    return count;
}
//Subsequence Using Strings 
void Subsequences(string input,string output)
{
    if(input.length()==0)
    {
        cout<<output<<" ";
        return;
    }
    
    Subsequences(input.substr(1),output);
    Subsequences(input.substr(1),output +input[0]);
}
//Recursion
//Using character array

// void subsequence_chararray(char *input , int beg,char *decision , int i)
// {
//     if(input[beg]=='\0')
//     {
//         decision[i]='\0';
//         cout<<decision<<endl;
//         return ;
//     }

//     //Recursive case 
//     subsequence_chararray(input,beg+1,decision,i);
//     decision[i] = input[beg];
//     //Iteration will be next , I is doing nothing just keeping a check
//     //on the iteration no.
//     subsequence_chararray(input,beg+1,decision,i+1);
// }


int main()
{
   string arr;
  // char arr[100];
    cin>>arr;
    // char decision[100]="";
    cout<<Subsequences_count(arr,"")<<endl;
Subsequences(arr,"");


    return 0;
}