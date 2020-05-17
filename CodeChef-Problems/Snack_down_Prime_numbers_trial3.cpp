//Prime Numbers 
//Trial 3
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
    for(int i=2;i<number;i++)
    {
        if(isPrime(i))
        {
            allprimes.push_back(i);
        }
    }
    int i=0,j=(allprimes.size())/2;
     while(i<j)
     { if(allprimes[i]*allprimes[j]==number) { return true;}
         else if(allprimes[i]*allprimes[j]>number) j--;
         else { i++;}
     }
     return false;
}
int main()
{
    int n;
    int testcases;
    vector<bool>ans;
    cin>>testcases;
    if(testcases<1||testcases>200) return 0;
    while(testcases>0)
    {
        cin>>n;
        vector<int> allprimes;
        for(int i=1;i<=n;i++)
        {
            if(isPrime(i))
            {
                allprimes.push_back(i);
            }
        }
            int i=1;
            int endpointer=(allprimes.size())/2;
        bool flag=false;
        while(i<endpointer)
            {    for (int j=i+1; j<allprimes.size();j++)
                { if(allprimes[i]*allprimes[j]<=n)
                    {   
                        int temp = n - (allprimes[i]*allprimes[j]);
                    
                        if(isPrime(temp)){
                            ;
                            }
                        else if(primeMultiplyer(temp))
                            {
                                // cout<<"Yes";
                                flag =true;
                                break;
                            }
                    
                     }
                   else{
                         i++;
                        break;
                        }
        
                 }
                 if(flag==true) {ans.push_back(1); break;}
             }
    if(flag==false){ans.push_back(0);}
    testcases--;
    }
    for(int i=0;i<ans.size();i++)
    {   if(ans[i]){cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}
    }
    return 0;
}