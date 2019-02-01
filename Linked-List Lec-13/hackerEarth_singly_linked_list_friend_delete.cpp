//Linked list Implementation - HackerEarth
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    //contructor
    node(int d)
    {
        data = d;
        next=NULL;
        //all the new nodes formed will have null at their next pointer by default
    }
};
void printLL(node*head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
    return;
}
void createLL(node*&head,int dt)
{
    //If it is the first node then - pehle mein hi insert karna hai
    if(head==NULL)
    {
        node *ptr = new node(dt);
        head = ptr;
        return;
    }
    //If it is not the 1st node
    node*temp = head;
    while(temp->next)
    {
        temp=temp->next;
    }
    //temp is the position where new node is to be inserted
    node *ptr = new node(dt);
    temp->next = ptr;
    return;
}
void insertLL(node*&head,int n)
{
    int d;
   
    while(n>0)
    {    cin>>d;
        createLL(head,d);
        n--;
        
    }
    return;
}
int lengthofLL(node* head)
{
    int len=0;
    while(head)
    {
        len++;
        head=head->next;
    }
    return len;
}
node* deletenode(node* head,node* prev)
{
    if(prev==NULL)
    {
        //the node to be deleted is the 1st node
        node* ptr = head;
        head = ptr->next;
        delete ptr; //memory free
        return head;
    }
    //if this thing does not happen then
    if(head==NULL||head->next==NULL)
    {
        //empty LL
        return NULL;
    }
    // if(head->next==NULL)
    // {
    //     //last node to be deleted
    //     node*ptr = prev->next;
    //     prev->next =NULL;
    //     delete ptr;
    //     return head;
    // }
    node* waste = prev->next;
    prev->next = waste->next;
    delete waste;
    return head;
}
void DeleteFriend(node*&head,int no)
{
    //no - no of friends to be deleted
    while(no>0)
    {   bool deletefriend = false;
        // int len = lengthofLL(head);
        node* prev = NULL;
        for(node * temp = head;temp->next!=NULL;temp=temp->next)
        {   
            node* forward = temp->next;
            if(temp->data<forward->data)
            {
                //delete temp;
                head = deletenode(head,prev);
                deletefriend = true;
                break;
            }
            prev = temp;
        }
        if(!deletefriend)
        {
            //delete the last element of the linked list
            head = deletenode(head,prev);
        }
        no--;
    }
}
int main()
{
    
    int n;
    int l;
    int testcase;
    cin>>testcase;
    while(testcase>0)
    { node* head = NULL;
         cin>>n>>l;
    insertLL(head,n);
    // printLL(head);
    
    DeleteFriend(head,l);
    printLL(head);
    testcase--;
    }
   
    return 0;
}