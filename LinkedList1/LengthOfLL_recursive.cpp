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

int getLengthofLL_recursive(Node* head)
{

    // we always use temp to iterate

    Node* temp = head;

    // if HEAD IS NULL THAT MEANS LL IS no more therefore return length 0
    if(temp == NULL)
    {

        return 0;

    }

    // return 1 add krke and move your temp (temp head ) to next node
    return 1 + getLengthofLL_recursive(temp -> next);

}

int main()
{

    Node* head = getLinkedList();

    cout << getLengthofLL_recursive(head);

}