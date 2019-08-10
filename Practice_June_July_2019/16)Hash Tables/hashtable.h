#include<string>
#include<iostream>
using namespace std;

template<typename T>
class node{
public:
    string key;
    T value;
    node<T> * next;
    node(string s,T v)
    {
        key = s;
        value = v;
        next = NULL;
    }
};
template<typename T>
class hashtable{
    int cs;
    int ts;
    node<T>** bucket;
    int hashFunc(string s)
    {
        int len = s.length();
        int ans=0;
        int p=1;
        for(int i=0;i<len;i++)
        {
            ans+= p*s[len-i-1];
            ans = ans % ts;
            p = p*37;
            p%= ts; 
        }
        return ans;
    }
public:
    hashtable(int ds=7)
    {
        cs = 0;
        ts= ds;
        bucket = new node<T>*[ts];
        //Initialize - with NULL
        for(int i=0;i<ts;i++)
        {
            bucket[i] = NULL;
        }
    }
    void insert(string s,T v)
    {
        int index = hashFunc(s);

        node<T>* n = new node<T>(s,v);
        n->next = bucket[index];
        bucket[index] = n;
    }
    void print()
    {
        for(int i=0;i<ts;i++)
        {
            node<T>* temp = bucket[i];
            cout<<"BUCKET "<<i<<endl;
            while(temp!=NULL)
            {
                cout<<temp->key<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
    T* search(string k)
    {
        int index = hashFunc(k);
        node<T>* temp = bucket[index];
        while(temp!=NULL)
        {
            if(k==temp->key)
            {
                return &(temp->value);
            }
            temp=temp->next;
        }
        return NULL;
    }
};
