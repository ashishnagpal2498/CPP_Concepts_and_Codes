//Hash Table - Data Structure 
//Insertion deletion and searching O(1) - 
// Key Val pair - used to search elements in table
//Factors - hash function - , size of table , Collisions 
//Collisions are basically values - which give same index - how to handle that

//We will be making a linked list for collision handling Separate chaining
//Linked list should be of fixed length 
//Possible Hash Functions prime number vala 37*i Submission of 
//Node * is the data - and Hash Table - is the actual data structure
// 
#include<iostream>
using namespace std;
int prime(int n)
{
    for(int i=n;i<1000;i++)
    { bool flag = true;
        for(int j =2;j*j<i;j++)
        {
            if(i%j==0)
            {
                flag = false;
            }
        }
        if(flag ==true)
        {
            return i;
        }
    }
}
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

    ~node()
    {
        if(next!=NULL)
        {
            delete next;
        }
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

    // Rehash Function
    void rehash()
    {
        node<T>**oldtable = bucket;
        int oldsize = ts;
        ts = 2*ts;
        int primetablesize = prime(ts);
        ts = primetablesize;
        cs=0;
        bucket = new node<T>*[ts];
        // NuLL all the values in Bucket
        for(int i=0;i<ts;i++)
        {
            bucket[i] = NULL;
        }

        // Copying Old values into new values;
        for(int i=0;i<oldsize;i++)
        {
            node<T>* temp = oldtable[i];
            while(temp!=NULL)
            {
                insert(temp->key,temp->value);
                temp=temp->next;
            }
            // Delete the array alloted
            delete oldtable[i];
        }
        delete [] oldtable;
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
        cs++;
        // cout<<cs<<"Tablesize  "<<ts<<endl;
        float loadfactor = (float)cs/ts;
        // cout<<loadfactor;
        if(loadfactor>=0.7)
        {   cout<<"Rehashing is Used"<<loadfactor<<endl;
            rehash();
        }
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
    // This will return the address of the Val
    T* search(string k)
    {
        //Index of bucket using - hash function- 
        int i = hashfun(k);
        node<T>*temp = bucket[i];
        while(temp!=NULL)
        {
            if(temp->key==k)
            {
                return &(temp->value);  
            }
            temp=temp->next;
        }
        return NULL;
    }
    void pop(string k)
    {
        int index = hashfun(k);
        node<T>*temp = bucket[index];

        // Find that node and delete it;
        if(temp->key==k)
        {
            // First node par hi present hai - 
            node<T>*waste = temp;
            bucket[index] = temp->next;
            // recursive delete will delete all the other node also
            waste->next = NULL;
            delete waste;
            return;
        }
        node<T>*prev = NULL;
        while(temp!=NULL&&temp->key!=k)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        temp->next = NULL;
        // deleting temp
        delete temp;
    }

    // Operator Overloading in Hash Table

    T& operator[](string k)
     {
        // search se puchha - Did you find 
        T* temp = search(k);
        if(temp==NULL)
        {
            // Insert the key into the table
            T garbage;
            insert(k,garbage);
            T* val = search(k);
            return *val;
        }
        return *temp;
     }

};


int main()
{
    hashtable<int> h(7);
    h.insert("Mango",100);
    h.printTable();
    h["Mango"] = 80;
    h["Apple"] = 120;
    // h.insert("Banana",80);
    // h.insert("Guava",120);
    // h.insert("Apple",90);
    //  h.insert("Orange",80);
     h.insert("Grapes",60);
     cout<<"Table 2";
    h.printTable();
    string s;
    cin>>s;
    int* ans = h.search(s);
    if(ans==NULL)
    {
        cout<<"Not Found"<<endl;
    }
    else
    {
        cout<<"Found:  "<<*ans<<endl;
    }
    cout<<"Enter the key to be deleted"<<endl;
    cin>>s;
    h.pop(s);
    cout<<endl;
    h.printTable();
    return 0;
}