//linked List - Basics
// How to use a linked list 
//inserting a front , mid and end
//Always remember where to use reference and where not - whenever original 
//linked list par kaam karna hai toh humesha reference aayega
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;

    Node(int d)
    {
        data=d;
        next =NULL;
    }
};

//Length function which returns the length of the linkedlist

int length(Node *head)
{
    int len=0;
    for(Node* temp = head ;temp!=NULL ; temp=temp->next)
    {
        len++;
    }
    return len;
}

void AddatFront(Node *&head ,int d)
{
    //This function adds the node at the front of linked list
    if(head==NULL)
    {
        //1st node to add here
        Node * ptr = new Node(d);
        head = ptr;
        return ;
    }
    Node *ptr = new Node(d);
    ptr->next =head;
    head =ptr;
    return ;
}
void addAtBack(Node*&head , int d)
{
    //Adding node at the back
    if(head==NULL)
    {
        //1st node
        Node * ptr = new Node(d);
        head = ptr;
        return;
    }
    Node * ptr = new Node(d);
    Node * cur = head;
    while(cur->next)
    {
        // if(cur->next->next ==NULL)
        // {
        //     //this is the last node
        //     cur->next->next = ptr;
        // }

        cur= cur->next;
    }
    cur->next = ptr;
    //here i have to go till end node
    return;

}
void takeinput_addBack(Node *&head)
{
    //This function takes the input d and call the add to add the node
    int d;
    cin>>d;
    while(d!=-1)
    {
        addAtBack(head,d);
        cin>>d;
    }
}
void takeinput_addFront(Node *&head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        AddatFront(head,d);
        cin>>d;
    }

}
void InsertAtPosition(Node * &head,int dt,int pos)
{
    if(pos==0)
    {
        //insert at starting
        AddatFront(head,dt);
        return;
    }
    //While loop to react to that position
    //take a variable temp and insert
    Node* temp = head;
    int cnt =1;
    while(cnt<=pos-1)
        {temp=temp->next;
            cnt++;}

    Node* ptr = new Node(dt);
    ptr->next=temp->next;
    temp->next = ptr;
    return;
}

//Delete the node at certain position
void DeleteAtPosition(Node*&head,int p)
{
    //check the position
    Node *temp = head;
    if(p==1)
    {
        //delete the head node;
        head =head ->next;
        delete temp;
        return;
    }
    int cnt=2;
    while(cnt<p)
    {
        temp = temp->next;
        cnt++;
    }
    //traversed till the previous node
    Node * waste = temp->next;
    temp->next=waste->next;
    delete waste;
    return ;
}

//Search an element 
//Linear search is used in case of linkedlist 
Node* SearchNode(Node*head,int key)
{
    //search recursively
    //base case
    if(head ==NULL)
    {
        return NULL;
    }
    if(head->data==key)
    {
        return head;
    }
    return SearchNode(head->next,key);
}

void printLL(Node *head)
{   Node * cur=head;
    while (cur)
    {
        cout<<cur->data<<"=>";
        cur = cur->next;
    }
}
//Overriding Cout and Cin operations
ostream& operator<<(ostream&os , Node* &head)
{
    printLL(head);
    return os;
}
istream& operator>>(istream& in , Node *&head)
{
        takeinput_addBack(head);
        return in;
}

//Mid Point Of Linked list 
//There are two ways , either 
//Traverse the whole linked list find out the length and N/2 is the mid
//Or we can have two pointers 1 goes at 2x speed where as other x
Node* midPoint(Node*head)
{
    Node* slowptr = head;
    Node*fastptr = head->next;
    while(fastptr&&fastptr->next)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }
    return slowptr;
}
//Merge Two  sorted Linked list
Node* merge(Node*a, Node*b)
{
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    Node* c;
    //Extra Node value 
    if(a->data < b->data)
    {
        c = a;
        //copy the value of the Node a if value is greater 
        c->next = merge(a->next,b);
    }
    else
    {
        c = b;
        c->next = merge(a,b->next);
    }
    return c;
}

//MergeSort
Node * mergeSort(Node*head)
{
    //Base case , if there is no element or only 1 element 
    //then return 
    if(head==NULL||head->next==NULL)
    {
        return head;
    }

    //Mergesort says - divide , sort and then merge
    //Find the mid point of the linked list
    //1st ki starting head se 
    //second ki starting mid->next se
    Node* mid= midPoint(head);
    Node * firsthalf = head;
    Node* secondhalf = mid->next;
    mid->next =NULL; 

//Recursively solve the other parts of LL
    firsthalf = mergeSort(firsthalf);
    secondhalf= mergeSort(secondhalf);

    return merge(firsthalf,secondhalf);

}

//Reverse a Linked list Iteratively

void reverse_a_linkedList(Node*&head)
{
    Node* prev=NULL;
    Node* cur=head;
    Node* N ;
    while(cur!=NULL)
    {
        //Store the value of cur ka next in the pointer N
        N = cur->next;

        //update the value of the cur->next ki to previous value
        cur->next =prev;
        prev =cur;
        cur = N; //updation
    }
    //Previous is the pointer where new head starts
    head = prev;
    return ;
}
//Reverse a linked list using recursion

Node * Reverse_recursion(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }

    Node * chotahead = Reverse_recursion(head->next);
    //In this , when head and chhotahead both points to same , nothing happens
    //in second iteration -
    // head -> []-> []->NULL  isko point kar rha h Chotta head
    // head ka next ka next should point to head , and head ka next NULL
    
    head->next->next = head;
    head ->next =NULL;
    return chotahead;


}

//Finding the tail of the Linked List
Node * tailfind(Node*head)
{   if(head==NULL||head->next==NULL)
    {
        return head;
    }
    while(head->next!=NULL)
    {
            head=head->next;
    }
    return head;
}

//Cycle Detection in a linked list
//Take two pointers , X and 2x if they meet , then cycle exist
void CycleDetection(Node*head)
{
    if(head==NULL||head->next==NULL)
    {
        cout<<"No cycle exist "<<endl;
        return ;
    }
    Node* slow=head;
    Node* fast=head->next;
    while(slow!=NULL||fast!=NULL)
    {
        if(slow==fast)
        {
            cout<<"cycle exist "<<endl;
            break;
        }
        ///segmentation fault
        
        slow=slow->next;
        fast =fast->next->next;
    }
    //Now we need to find at which node the cycle exist will be;
    slow = head;
    while(true)
    {
        if(slow==fast)
        {
            //Point found;
            cout<<"cycle exist at node "<<slow->data<<endl;
            break;
        }
        slow = slow->next;
        fast = fast->next;
    }

    return ;

}

int main()
{
    Node *head = NULL;
    // Node * start = NULL;
    takeinput_addFront(head);
    // takeinput_addFront(start);
    cout<<head<<endl;
        
        //7_Jan_19
            //Node* midpoint_val = midPoint(head);
            // cout<<midpoint_val->data;
    
    // head = mergeSort(head);
    // cout<<head<<endl;
    // reverse_a_linkedList(head);
    // cout<<head<<endl;
    // head = Reverse_recursion(head);
    // cout<<head<<endl;
    //Node * tailNode = tailfind(head);
    //tailNode ->next = head->next->next;
   // CycleDetection(head);
    // cout<<head;
    //This gives an infinite loop as there exist a cycle 
    //Hence how to detect that cycle

    //takeinput_addBack(head);
   // printLL(head);
    // Node * start =NULL;
    /* takeinput_addFront(head);
     printLL(head);
    cout<<endl;
   //Always initialise the pointer as Null 
    // Node * ptr =NULL;
    // cin>>ptr;
    // cout<<ptr;
    cout<<"Length of linked list is "<<length(head);
    cout<<"\n Enter data and position  ";
    int d,p;
    cin>>d>>p;
    InsertAtPosition(head,d,p);
    printLL(head);
    cout<<"\n Enter element to be searched";
    int k;
    cin>>k;
    Node * ans = SearchNode(head,k);
    if(ans==NULL)
    {
        cout<<"element not found \n";
    }
    else{
        cout<<"element found "<<ans->data<<endl;
    }
    //Delete a node
    cout<<"Insert the ith node to be deleted";
    cin>>k;
    DeleteAtPosition(head,k);
    cout<<head;
    ans = midPoint(head);
    cout<<"\n Data At mid point is  "<<ans->data;
    */

    return 0;
}