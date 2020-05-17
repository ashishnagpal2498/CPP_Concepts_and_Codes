//Prime nos till n integer
#include<iostream>
#include<vector>
using namespace std;
bool isPrime(int i)
{   if(i == 1) return true;
    bool prime =true;
    for(int j=2;j*j<=i;j++)
    {
        if(i%j==0) prime =false;
    }
    return prime;
}
bool primeMultiplyer(int number)
{   vector<int> allprimes;
    // vector all primes stores all primes of number n
    for(int i=1;i<=number;i++)
    {
        if(isPrime(i))
        {
            allprimes.push_back(i);
        }
    }
    int i=0,j=allprimes.size()-1;
     while(i<j)
     {
         if(allprimes[i]*allprimes[j]==number) { return true;}
         else if(allprimes[i]*allprimes[j]>number) j--;
         else { i++;}
     }
     return false;
}
int main()
{   vector<int> ans;
    int testcases;
    cin>>testcases;
    if(testcases<1||testcases>200) return 0;
    int n;
   while(testcases>0)
    {       cin>>n;
            // if(n>200||n<1) { testcase--; continue;}
            vector<int> allprimes;
            for(int i=1;i<=n;i++)
                {
                     if(isPrime(i))
                { allprimes.push_back(i);} //Loop to compute all primes of number
                }
         int i=1,j=(allprimes.size());
      bool flag=false;
      while(i<j)
      { 
             if(allprimes[i]*allprimes[j]<=n&&isPrime(allprimes[i])&&isPrime(allprimes[j]))
            {   int temp = n - (allprimes[i]*allprimes[j]);
                 if(isPrime(temp))
                    {   //If the remainder number is prime , Shift The pointer to the left
                        j--;
                    }
                 else if(primeMultiplyer(temp))
                    {   
                        ans.push_back(1);
                       flag=true;
                         break;
                    }
                else {
                    i++; j--;
                    }
            }
         else{
            j--;
         }
      }
    if(flag==false)
    {ans.push_back(0);}
    testcases--;
    }
    for(int i=0;i<ans.size();i++){
        if(ans[i]==1) {cout<<"YES"<<endl;}
        else{ cout<<"NO"<<endl;}
    }
    return 0;
}