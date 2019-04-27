//need to find mikes hashes for given value of arrays
#include<iostream>
using namespace std;
class hashtable{
//Mike and hash functions
    int MAX;
int* hash_array(int A[], int n)
{   
    int* hash = new int[MAX]; //MAX is the maximum possible value of A[i]
    for(int i=0;i<=MAX;i++) hash[i]=-1; //initialize hash to -1.
    int count = 0;
    for(int i=0;i<n;i++) // Loop through elements of array
    {
        if(hash[A[i]] == -1) // A[i] was not assigned any hash before
        {
            hash[A[i]] = count; // Assigning hash to A[i]
            count++;
            continue;
        }
        for(int j = 0;j<i;j++)
        {
            if(hash[A[j]] > hash[A[i]]) // All the hashes greater than previous hash of A[i] are decremented.
                hash[A[j]]--;
        }
        hash[A[i]] = count - 1; // Assigning a new hash to A[i]
    }
    return hash;
}
    public:
        hashtable(int* arr,int n)
        {   MAX = 100005;
            insert(arr,n);
        }
        void insert(int*arr,int n)
        {
            int* hasharr = hash_array(arr,n);
            print(hasharr);
        }
        void print(int*hasharr)
        {
            for(int i=0;i<=MAX;i++)
            {
                 if(hasharr[i]!=-1)
                {
                    cout<<1+hasharr[i]<<endl;
                }
            }
        }
};
int main()
{
    int n;
    cin>>n;
    int arr[100005];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    hashtable h1(arr,n);
    return 0;
}