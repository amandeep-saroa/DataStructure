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

    //2 base case

    if(head == NULL || head -> next == NULL)
    {

        return head;

    }
    // agr 0th node delete krni toh just update your head and return head and make sure you delete 0th node
    // for that store that 0th node in CurrentNode Node and delete it
    if(pos == 0)
    {
        // store current head somewhere so that u can delete it later so that it doesnt get lost
        Node* currentNode = head;
        // update your head ie move to the next node
        head = head -> next;
        // now delete the previous Head node
        delete currentNode;

        return head;

    }
    // agr 1st position pe dalna hai node therefore connect head with 2nd node for that u need to store 2nd node address somewhere and also 1st pos address somewhere so that u can delete it since it is heap
    else if(pos == 1)
    {

        Node* a = head -> next; // 1st node
        Node* b = a -> next;    // 2nd node 

        // connect head with b therefore delete a

        // dont need a therefore delete a

        delete a;

        head -> next = b;

        return head;

    }
    // else recursive call till we reach the position and position - 1
    else
    {   
        // move your head to next node
        deleteNode(head -> next , pos - 1);
            
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
    cout << endl;

    int pos;
    cin >> pos;

    Node* newhead = deleteNode(head , pos);
    print(newhead);

}