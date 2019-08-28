//Arrangement Rearrangement - 
//arr[i] = i
#include<iostream>
#define Arrout for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
using namespace std;
void fixArray(int*arr,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=-1&&arr[i]!=i)
        {
            //Must be placed at correct position
            int x = arr[i];

            //
            while(arr[x]!=-1&&arr[x]!=x)
            {
                int y = arr[x];
                arr[x] = x;
                x =y;
            }
            arr[x] =x;
            if(arr[i]!=i)
            {
                arr[i]= -1;
            }
        }
    }
}
int fixArr2(int *arr,int n)
{
    for(int i=0;i<n;)
    {
        if(arr[i]!=-1&&arr[i]!=i)
        {
            swap(arr[i],arr[arr[i]]);
        }
        else i++;
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    int n = sizeof(arr)/sizeof(int);
    Arrout;
    cout<<endl;
    // fixArray(arr,n);
    fixArr2(arr,n);
    Arrout;
    return 0;
}