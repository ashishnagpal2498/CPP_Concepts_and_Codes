//Hash Table - Data Structure 
//Insertion deletion and searching O(1) - 
// Key Val pair - used to search elements in table
//Factors - hash function - , size of table , Collisions 
//Collisions are basically values - which give same index - how to handle that

//We will be making a linked list for collision handling Separate chaining
//Linked list should be of fixed length 
//Possible Hash Functions prime number vala 37*i Submission of 
//Node * is the data - and Hash Table - is the actual data structure
#include<iostream>
using namespace std;

template<typename T>
class node{
public:
    string key;
    T value;
    node<T> * next;
    //Self referencial pointer - 

    node(string k,T v)
    {
        key = k;
        value = v;
    }


};
template<typename T>
class hashtable{
    int cs;
    int ts;
    node<T> ** bucket;

    int hashfun(string k)
    {
        int len = k.length();
         int ans = 0;
         int pow = 1; //37*0 is 1;
         for(int i=0;i<len;i++)
         {
            ans+= k[len-i-1] *pow;

            pow = pow*37;

            pow%=ts;
            ans%=ts;
         }
         return ans;
    }
public:
    hashtable(int tablesize = 7)
    { 
        cs = 0;
        ts = tablesize;
        bucket = new node<T>*[ts];
        //Making all the value in Bucket as NULL
        for(int i=0;i<ts;i++)
        {
            bucket[i] = NULL;
        }
    }
    // Now write the insert Function
    void insert(string k , T val)
    {
        // It will create a index using hash function - 
        int index = hashfun(k);

        node<T>* newnode = new node<T>(k,val);
        newnode->next = bucket[index];
        bucket[index] = newnode;

    }
    void printTable()
    {
        // loop till size of the table
        for(int i=0;i<ts;i++)
        {
            // Take the value of bucket [i] - in a linked list and 
            //Print the linked list
            node<T> * temp = bucket[i];
            cout<<"Bucket "<<i<<" ->  ";
            while(temp!=NULL)
            {
                cout<<temp->key<<" , "<<temp->value;
                temp=temp->next;
            }
            cout<<endl;
        }
    }

};


int main()
{
    hashtable<int> h(11);
    h.insert("Mango",100);
    h.insert("Banana",80);
    h.insert("Guava",120);
    h.insert("Apple",90);
    h.insert("Orange",80);
    h.insert("Grapes",60);
    h.printTable();
    return 0;
}