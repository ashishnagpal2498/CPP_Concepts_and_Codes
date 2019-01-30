//Permutations of a String 
#include<iostream>
using namespace std;
void printPermutations(char *a, int i)
{
    //Base case
    if(a[i]=='\0')
    {
        cout<<a<<endl;
        return;
    }

    //Recursive case
    for(int j=i;a[j]!='\0';j++)
    {   swap(a[i],a[j]);
        printPermutations(a,i+1);
        // Backtracking Step . Wapis aate huye Swap Kar diya
        swap(a[i],a[j]);
    }
}
int main()
{
    char arr[10]="abc";
    printPermutations(arr,0);
}