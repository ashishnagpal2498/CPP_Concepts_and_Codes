//Ascii , Subsequeces
#include<iostream>
#include<string>
using namespace std;

void subsequence_chararray(char *input , int beg,char *decision , int i)
{
    if(input[beg]=='\0')
    {
        decision[i]='\0';
        cout<<decision<<endl;
        return ;
    }

    //Recursive case 
    subsequence_chararray(input,beg+1,decision,i);
      decision[i] = int(input[beg]);
     subsequence_chararray(input,beg+1,decision,i);
    decision[i] = input[beg];
    //Iteration will be next , I is doing nothing just keeping a check
    //on the iteration no.
   
    subsequence_chararray(input,beg+1,decision,i+1);

}


// void ascii_subsequence(string input,string output)
// {
//     if(input.size()==0)
//     {
//         cout<<output<<" ";
//         return ;
//     }

//     ascii_subsequence(input.substr(1),output);
//     ascii_subsequence(input.substr(1),output + input[0]);
//     int asciival = int(input[0]);
       
//     // ascii_subsequence(input.substr(1),output +asci);
// }
int main()
{
    char arr[100],decision[100]="";
    cin>>arr;
    // ascii_subsequence(s,"");
    subsequence_chararray(arr,0,decision,0);
    return 0;
}