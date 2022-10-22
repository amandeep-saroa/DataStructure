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
            tail =  tail -> next;

        }

        cin >> data;

    }

    return head;

}
Node* insertNode(Node* head , int pos , int ele)
{

    Node* tempHead = head;
    int counter = 0;
    // create NewNode for new ele
    Node* newNode = new Node(ele);

    // IF POS IS MORE THAN THE LENGTH OF LL THEREFORE DONT EDIT LL therefore for that u need to check if we reached end of LL or not
    // use this condition in while itself along with counter

    // TO ADD Node at 0th pos therefore different case u just need to put address of head into newNode next
    if(pos == 0)
    {

        newNode -> next = head;
        // dont forget to update your head now 
        // now newNode is your head
        head = newNode;

        return head;

    }

    while(tempHead != NULL && counter <= pos - 1)
    {

        //move tempHead iterate through LL
        tempHead = tempHead -> next;
        counter++;

    }
    if(tempHead != NULL)
    {
        // store Right node address in tempTail
        Node* tempTail = tempHead -> next;
        // now put newNode address in next of leftNode
        tempHead -> next = newNode;
        // now move tempHead to next NewNode
        tempHead = tempHead -> next;
        // now connect this tempHead(newNode) with right Node address stored in tempTail;
        tempHead -> next = tempTail;
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
    int i,x;
    cin >> i >> x;
    Node* head = insertNode(head , i , x);
    print(head);

}