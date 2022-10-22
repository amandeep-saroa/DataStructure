#include<iostream>
using namespace std;

#include "Node.cpp"

Node* getLinkedList()
{

    int data;
    cin >> data;

    // Now keep track of head and also tail(last node of the linkedList)

    // BOTH INITIALLY NULL
    Node* head = NULL;
    Node* tail = NULL;

    while(data != -1)
    {
        // create NewNode dynamically newNode is name of pointer it store address of the Node that we just created
        Node* newNode = new Node(data);

        // if head is NULL also tail is NULL that means its the first Node which is now head and tail of the LinkedList

        if(head == NULL && tail == NULL)
        {

            head = newNode;
            tail = newNode;

        }
        // else it means that we have linkedList therefore only update the tail 
        else
        {

            // connect tail with newNode
            tail -> next = newNode;
            // move tail to newNode address
            tail = tail -> next;

        }

        cin >> data;

    }

    return head;

}

// The above function have timeComplexity in Order of n to insert n Nodes : O(n)

void print(Node* head)
{

    Node* temp = head;

    while(temp != NULL)
    {

        cout << temp -> data << " ";
        temp = temp -> next;

    }

}

int main()
{
    // since we store the address of the first node of the linkedList therefore pointer has to be of the same data type
    Node *head = getLinkedList();

    print(head);

}