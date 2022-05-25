#include<iostream>
using namespace std; 
int main(){
        long long int a;
        cin>>a;
        long long int reverse = 0;
        long long increment = 1;
        while(a){
            int digit = a%10;
            a = a/10;    
            reverse = reverse * 10 + digit;
            // increment*=10;
        }
        cout<<"Reverse of number is "<<reverse;
    return 0;
}