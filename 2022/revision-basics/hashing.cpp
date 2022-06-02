// Hashing - >
// DS -> support insertion, deletion and search in constant time

#include<iostream>
#include<string>
using namespace std;

// hash function - Converts key into index value - Int

// Collisions 
template<typename T>
class Node{
public:
    string key;
    T value;
    Node <T>* next;
    Node(string k,T v){
        key = k;
        value = v;
    }
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

template<typename T>
class HashTable{
    int cs;
    int ts;
    Node<T>** bucket;

    int hashFunc(string s){
        int n = s.size();
        int ans =0;
        int p=1;
        for(int i=0;i<n;i++)
        {
            ans+= s[i]*p;

            p*=37;

            p%=ts;
            ans%=ts;
        }
        return ans;
    }
    bool isPrime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    int nextPrime(int n){
        n<<=1;
        while(true){
            if(isPrime(n)) return n;
            n++;
        }
    }
    void rehash(){
        int oldTs = ts;
        Node<T>** oldBucket = bucket;
        int primeNo = nextPrime(oldTs);
        ts = primeNo;
        cout<<"Prime Number -> "<<primeNo<<endl;
        bucket = new Node<T>*[ts];
        for(int i=0;i<ts;i++){
            bucket[i] = NULL;
        }
        for(int i=0;i<oldTs;i++){
            Node<T>* temp = oldBucket[i];
            if(temp)
            {
                while(temp){
                    insert(temp->key,temp->value);
                    temp= temp->next;
            }
            // Delete Linked List ->
            delete temp;
            }

        }
        delete [] oldBucket;
    }
public:
    HashTable(int tableSize = 11 ){
        cs = 0;
        ts = tableSize;
        bucket = new Node<T>*[ts];

        // NULL initialize
        for(int i=0;i<ts;i++){
            bucket[i] = NULL;
        }
    }
    // 
    void insert(string s,int val){

        int hashIndex = hashFunc(s);
        T* temp = search(s);
        if(temp != NULL ){
            // Make the value from the address we got
            *temp = val;
            return;
        }
        Node<T> * newNode = new Node<T>(s,val);
        newNode->next = bucket[hashIndex];
        bucket[hashIndex] = newNode;

        cs++;

        double loadFactor = (double)(cs)/ts;
        if(loadFactor > 0.7){
            cout<<"Load Factor Greater -> rehashing required "<<loadFactor<<endl;
            rehash();
        }
    }
    // Hash function

    //  Search
    T* search(string key){
        int hashIndex = hashFunc(key);

        Node<T>* temp = bucket[hashIndex];
        while(temp){
            if(temp->key == key) return &(temp->value);
            temp = temp->next;
        }
        // Common value return if key not found
        return NULL;
    }
    void print(){

        Node<T>* temp = NULL;
        for(int i=0;i<ts;i++){
            temp = bucket[i];
            cout<<i<<" -> ";
            while(temp){
                cout<<temp->key<<",";
                temp = temp->next;
            }
            cout<<"\n";
        }
    }

    T& operator[](string key){
        T* temp = search(key);
        if(temp == NULL){
            T garbage;
            insert(key,garbage);
            
            temp = search(key);
        }

        return *temp;

    }
};

int main(){
    HashTable<int> tb(7);
    tb.insert("Mango",100);
    cout<<"Square brackets operator -> "<<tb["Banana"]<<"\n";
    tb.insert("Apple",120);
    tb.insert("Banana",140);
    tb.insert("Chiku",163);
    tb.insert("Orange",169);
    tb.insert("Papaya",98);
    tb.print();
    int* findNode = tb.search("Orange");
    if(findNode == NULL) cout<<"Node not found\n";
    else cout<<"Value is "<<*findNode<<"\n";
    cout<<"Sq brackets "<<tb["Banana"]<<endl;
    return 0;
}