#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the removeDuplicates function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {

if(head==NULL||head->next==NULL)
{
    return head;
}

SinglyLinkedListNode* curr = head->next;
SinglyLinkedListNode * prev = head;
int val;
bool flagdelete= false;
while(curr)
{     val= prev->data;

    if(curr->data==val)
    {
        //value duplicate 
        SinglyLinkedListNode* waste = curr;
        prev->next = curr->next;
        delete waste;
        flagdelete = true;
    }
    if(flagdelete)
    {
        flagdelete = false;
    }
    else{
     prev = curr;
    }
    curr=prev->next;

}
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        SinglyLinkedList* llist = new SinglyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        SinglyLinkedListNode* llist1 = removeDuplicates(llist->head);

        print_singly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist1);
    }

    fout.close();

    return 0;
}