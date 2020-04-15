#include<iostream>
using namespace std;
class node{
public:
    int data;
    int noofChild;
    node* *nChild;
    node(int d,int n)
    {   data =d;
            noofChild =n;
        if(n==0)
        {   
            nChild=NULL;
        }
        else{
            nChild = new node*[n];
            
        }
    }
};
