//Advance Recursion -
//Permutation + backtracking
#include <iostream>
using namespace std;
void Permutation(char*str,int i)
{
    if(str[i]=='\0')
    {
        cout<<str<<endl;
    }
    for(int j=i;str[j]!='\0';j++)
    {
        swap(str[i],str[j]);
        Permutation(str,i+1);
        //BackTracking Step
        swap(str[i],str[j]);
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    char str[1005];
    cin>>str;
    Permutation(str,0);
    return 0;
}