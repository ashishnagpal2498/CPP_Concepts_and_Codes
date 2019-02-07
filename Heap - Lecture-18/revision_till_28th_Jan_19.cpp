//Revision till 28_Jan_19
//Token - smallest individual unit inside a program
// Literals , Identifiers keywords , operators punctuators
//Algorithm - before approaching
// 1)Patterns - Think the possible combination for the printing
// Curline , noofvalues to be printed , val to be printed
// Spaces in the patterns would be - n-curline if reducing
//Programming paradigms - How do we write the code - procedural , modular , OOPs
//Types of algorithm - Brute force , Divide and conquer , DP, Greedy
//Expression - Valid combination of operator , operands , 
//Difference b/w cin cin.get and cin.getline
//Array- BASE TYPE - typeof data array is storing
//Ganesh pattern - values - and nvalues

#define pi 3.14
//CPP-LIVE Basics
// Hour glass , apple oranges , evil king ,
//#define - preprocessor directive - 
//Bitwise operators - & | ! << >> ^

//Square root of a no. till p places
//arrays - 1) Sorted rotated array - pivot element 2) Wave sort , 3) Target sum pair
// The sliding window approach
// Unique number 1 - Zor operator , Unique number 2 - zor operator , then UN1 -
//Unique number 3 - ans variable - bit wise add - modulus
//Median of two sorted array - Median always lie between the array median-

//Pointers - name of array is pointer , but it cannot be done ++ in main
//becoz -reference - ITs not an actual pointer,
//Address are always passed by value
//character array - cin /cou differently treat - char arrays -
//Array of Pointers 
//Pointer to array of 5 integers


#include<iostream>
#include<time.h>
#include<cstring>
using namespace std;
//We write STD standard i/o library so that we cannot override the operator 
//cin or cout has standard defination

void printsubsequence(string s, int n)
{   int i =0;
    while(n)
    {
        n&1 ? cout<<s[i] : cout<<"" ;
        n = n>>1;
        i++;
    }
}

void trial_ptr(int (*ptr)[10])
{
    cout<<ptr[0][0];
}

void subsequence(string s)
{
    int n = s.length();
    for(int i=0;i<1<<n;i++)
    {
        printsubsequence(s,i);
        cout<<endl;
    }
}
//template T;
ostream& operator<<(ostream&ob,pair<int,int> p)
{
    ob<<p.first<<" ";
    ob<<p.second;
    return ob;
}

//vector ----------> 

//Spiral print , Rotate a 2-D Array 90 deg 
//Binary search - iMP - monotonic increasing search space 
//STL - upper bound and lower bound functions
//Bit masking - a^b b - set bits - 

//String stream - strings - read or write accordingly
//Kadane's Algorithm |  sum of all the subarray -
//Help Ramu - max of tickets;
// Rain Water Harvesting - precomputation - left and right height of the buildings


//Recusion - Assume that smaller problem is solved
// base case , self work and recusive work

bool isSorted(int* arr,int n)
{
    //Base case ;
    if(n==1)
    {
        return true;
    }

    //self work
    if(arr[0]>arr[1])
    {
        return false;
    }
    bool chotaans = isSorted(arr++,n-1);
    return chotaans;
}


int linear_search(int*arr,int n,int ele)
{
    if(n==0)
    {
        return -1;
    }

    //self work -
    if(arr[0]==ele)
    {
        return 0;
    }

    int smallarray = linear_search(arr+1,n-1,ele);
    if(smallarray==-1)
    {
        return -1 ;
    }
    else
    {
        return 1 + smallarray;
    }
}

int last_occurence_array(int*arr,int n,int ele)
{
    if(n==0)
    {
        return -1;
    }
    int smallarray = last_occurence_array(arr+1,n-1,ele);
    if(smallarray==-1)
    {
        if(arr[0]==ele)
        {
            return 0;
        }
        else return -1;
    }
    return 1+ smallarray;
}


int fast_power(int x,int y)
{
    //base case 
    if(y==0)
    {
        return 1;
    }
    int halfpower = fast_power(x,y/2);
        halfpower*=halfpower;
    if(y&1)
    {
        halfpower*=x;
    }
    return halfpower;
}

int stair_case(int n)
{
    
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    return stair_case(n-1)+stair_case(n-2)+stair_case(n-3);
}

//Backtracking problem - permutation

void permutation(char *str,int i)
{   
    //Base case
    if(str[i]=='\0')
    {
        cout<<str<<endl;
        return;
    }

    //Permutation- 
    for(int j=i;str[j]!='\0';j++)
    {   swap(str[i],str[j]);
        permutation(str,i+1);
        swap(str[i],str[j]);
    }

}

void permutation_using_string(string str,int i)
{
    if(str[i]=='\0')
    {
        cout<<str<<endl;
        return;
    }

    for(int j=i;str[j]!='\0';j++)
    {
        swap(str[i],str[j]);
        permutation_using_string(str,i+1);
        //swap(str[i],str[j]);
    }
}


int main()
{ 
    cout<<"Fast power "<<fast_power(2,5)<<endl;
    int array_sorting[] = {1,2,3,8,9,8,7,6,3};
    cout<<"Is array sorted  "<<isSorted(array_sorting,4)<<endl;
    int arr [][10] ={{1,2,3},{4,5,6}};
    cout<<"Element found at index  "<<linear_search(array_sorting,9,8);
    cout<<"Last Occurence  "<<last_occurence_array(array_sorting,9,8)<<endl;
    cout<<"Staircase problem "<<stair_case(4)<<endl;
    char ab[] = "abc";
    permutation(ab,0);
    string str = "abc";
    cout<<endl<<"Permutation using Strings  "<<endl;
    permutation_using_string(st1r,0);
  //   trial_ptr(arr);
  //   pair<int,int> p;
  //   p.first = 8;
  //   p.second = 923;
  //   cout<<p;
  // time_t a = time(0);
  //   string s={'a','b','c'};
  //   cout<<s<<"  "<<a<<"  Value of pi using #define "<<pi;
  //   int abc = 5;
  //   int ans = abc<<1;
  //   cout<<endl<<ans<<endl;
  //   //subsequence of a string using Bit masking
  //   subsequence(s);
  //   //strlen(s);
  //   string str;
  //   getline(cin,str);
  //   cout<<str;
    return 0;
}