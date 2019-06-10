//median of two sorted arrays Trial 2
#include<iostream>
using namespace std;
float median(int arr1[],int arr2[],int m,int n )
{
    int hi1=m-1,low1=0,low2=0,hi2=n-1;
    while(true)
    {   int medindex1=(hi1+low1)/2;
        int medindex2= (hi2+low2)/2;
        int median1=arr1[medindex1],median2=arr2[medindex2];
        if(hi1-low1==1||hi2-low2==1)
        {
            int largest = max(arr1[low1],arr2[low2]);
            int smallest =min(arr1[hi1],arr2[hi2]);
            return (float)(largest+smallest)/2;
        }
        if(median1<median2)
        {
            low1=medindex1;
            hi2=medindex2;
        }
        else{
            low2=medindex2;
            hi1=medindex1;
        }
    }
}
int main()
{   int *ptr=NULL; //use of pointer 
    cout<<sizeof(ptr)<<endl;
    int arr1[]={1,3,5,7,10,15}; 
    int arr2[]={2,16,18,20,22};
    int sz1= sizeof(arr1)/sizeof(int);
    int sz2= sizeof(arr2)/sizeof(int);
   float md= median(arr1,arr2,sz1,sz2);
    cout<<md;
    return 0;
}