#include<iostream>
using namespace std;
#include "Node.cpp"

Node* getLinkedList()
{

    int data;
    cin >> data;

    Node* head = NULL;
    Node* tail = NULL;

    while(data != -1)
    {

        Node* newNode = new Node(data);

        if(head == NULL && tail == NULL)
        {

            head = newNode;
            tail = newNode;

        }
        else
        {

            tail -> next = newNode;
            tail = tail -> next;

        }

        cin >> data;

    }

    return head;

}

Node* deleteNode(Node* head , int pos)
{   

    // if head is null that no LL created therefore simply return head
    if(head == NULL)
    {

        return head;

    }

    // if told to delete the 0th Node ie Head node handle this case seperatly

    if(pos == 0)
    {

        // just update your original head put address of next node in head
        head = head -> next;
        return head;

    }

    // otherwise do this
    Node* temp = head;
    int counter = 0;
    // LOOP TILL YOU REACH THE POS or till the end of LL
    while(counter < pos - 1 && temp -> next != NULL)
    {

        // MOVE YOUR TEMP
        temp  = temp -> next;
        counter++;

    }

    if(temp != NULL)
    {

        
        // move temp to the next node (this node we will delete but first take the address of next node from here and store in another ptr and then connect this right node with left node)

        // move temp two time 1st node delete and 2nd ka address temp -> next mai dalo
        Node* a = temp -> next;

        Node* b = a -> next;

        // now put b in temp -> next

        temp -> next = b;

        //also deallocate the memeory of a since we dont need that address Node
        delete a;



    }

    return head;



}

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

    Node* head = getLinkedList();
    print(head);

    cout << endl;

    int pos;
    cin >> pos;

    Node* Newhead = deleteNode(head , pos);
    print(Newhead);

}