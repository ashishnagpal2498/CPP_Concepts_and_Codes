//Permutations of a string 
#include<iostream>
using namespace std;

void Permutations(char *a,int i)
{
    //Base Case
    //When string will reach to null , Print the string
    if(a[i]=='\0')
    {
        cout<<a<<endl;
        return;
    }

    //Recursive case 
    for(int j=i;a[j]!='\0';j++)
    {   //Swapping elements
        swap(a[i],a[j]);
        Permutations(a,i+1);
        swap(a[i],a[j]); //Backtracking Step
    }
}

int main()
{
    char ab[10] ="abc";
    Permutations(ab,0);
    return 0;
}