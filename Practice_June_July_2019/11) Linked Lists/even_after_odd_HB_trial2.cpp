//Even-After Odd
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int d)
    {
        data = d;
        next =NULL;
    }
};
void addTohead(node*&head,int d)
{
    if(head==NULL)
    {
        head = new node(d);
    return;
    }
    node* n = new node(d);
    n->next = head;
    head = n;

}
void addToTail(node*&head,int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return;
    }
    node*temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    node* n = new node(d);
     n->next = NULL;
     temp->next = n;   
    return;
}
void createLL(node*&head,int n)
{
    int d;
    while(n--)
    {
        cin>>d;
        addToTail(head,d);
    }
}
void oddEven(node*&head,int n)
{   node*temp = head;
    node*prev = NULL;
    int i=1;
    while(i<=n)
    {   node* nxt = temp->next;
        if(temp->data&1)
        {   
            //odd add to head;
            if(head==temp)
            {   prev = head;
               // cout<<"Its ODD AND HEAD "<<endl;
            }
            else
            {   //cout<<"Its ODD AND NOT HEAD "<<endl;
                prev->next = temp->next;
                prev = temp;
                node* waste = temp;
                addTohead(head,temp->data);
                delete waste;
            }
        }
        else //if(!(temp->data&1)&&i==1)
        {
            //1st node and Even
            if(temp==head)
            {   //cout<<"Its EVEN AND HEAD "<<endl;
                head = temp->next;
                node*waste = temp;
                addToTail(head,temp->data);
                delete waste;
            }
            else
            {   //cout<<"Its EVEN AND NOT HEAD "<<endl;
                prev->next = temp->next;
                //cout<<prev->data<<"  "<<temp->data<<endl;
                node*waste = temp;
                addToTail(head,temp->data);
                delete waste;
            }

        }
        // prev = temp;
        temp = nxt;
        i++;
    }
}
void oddEven2(node*&head,int n)
{
    int i=1;
    node* temp =head;
    node* prev = NULL;
    while(i<=n)
    {   if(temp->data&1)
        { prev = temp;
            // if(temp!=head)
            // {
            //     prev->next = temp->next;
            //     node*waste= temp;
            //     addTohead(head,temp->data);
            //     delete waste;
            // }
            // else
            // {
            //     prev = temp;
            // }
        }
        else
        {
            //even - move karte jaa
            if(temp!=head)
            {
                prev->next = temp->next;
                node* waste = temp;
                addToTail(head,temp->data);
                delete waste;
            }

        }
        temp = prev ->next;
        i++;
    }
}
void printLL(node*head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
node* reverse(node* head,int k)
{
    node*curr = head;
    node* nxt= NULL;
    node* prev = NULL;
    int count =0;
    while(count<k&&curr!=NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
    if(nxt!=NULL)
    {
        head->next = reverse(nxt,k);
    }
    return prev;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    node*head = NULL;
    createLL(head,n);
   // printLL(head); cout<<endl;
    // oddEven2(head,n);
    int k; cin>>k;
    head = reverse(head,k);
    printLL(head);
    return 0;
}