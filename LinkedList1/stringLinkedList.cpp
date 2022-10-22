#include<iostream>
#include "StringNode.cpp"
using namespace std;

// function makes LinkedList and returns the address of that linkedList to the main since address is of Node therefore data type return is also Node pointer

Node* getLinkedList()
{

    //get data
    string data;
    cin >> data;

    // always fx your head to first Node initally head is null

    Node *head = NULL;

    while(data != "no")
    {

        Node *newNode = new Node(data);

        // CHECK IF head == NULL therefore linkedList is initalised know therefore make newNOde as your head only once otherwise using head(ie using temp as your head) go to end of linkedlist(where u find NULL in next data part of temp(ie head temprory travelling) and put the address of newNode there)

        if(head == NULL)
        {

            head = newNode;

        }
        else
        {

            //create temp to store head use this to traverse over the linkedList

            Node *temp = head;

            while(temp -> next != NULL)
            {

                // moe your temp to next node using address already placed in temp
                temp = temp -> next;

            }

            // know reach lastnode connect with newNODE
            temp -> next = newNode;

        }

        cin >> data;

    }


    // return the head of your linked list;
    return head;

}

void print(Node *head)
{

    Node *temp = head;

    while(temp != NULL)
    {

        cout << temp -> data << " ";
        temp = temp -> next;

    }

}

int main()
{


    Node *head = getLinkedList();


    //print your linkedList using head but never use head drectly
    print(head);

}