#include<iostream>
using namespace std;
#include "Node.cpp"

// want to create takeInput method in which we take input from user and create the linked list and returns the head of that linked list to the main function
// since woh head next Node ka address hai its of data type Node (own data structure) therefore return type is Node* since pointer store the address
// if we return the address of the head of the linkedlist therefore we can access the linkedList and all its elements

Node* takeInput()
{

    // incase of array we need take size of the array from user
    // then we create array of that size
    // then we run for loop till we take n elements from user and put those ele into indices of the array

    // INCASE OF LINKEDLIST

    // dont need size of linkedList
    // we need to create node and link them up so we need to run loop to take Node from user
    // so how we run the loop we dont know the size toh loop kaise run krye 
    // for know ASSUME if user enters -1 therefore that means he dont want to enter more elements therefore as soon he enter -1 we return the head of the linkedList to the main

    // lets start taking data input from user then creating node puting that data into Node and taking another input

    int data;   // assume for know
    cin >> data;
    Node *head = NULL;  //initially null linked list not created
    while(data != -1)
    {


        //store data in Node therefore create a node dynamically

        Node *newNode = new Node(data);

        if(head == NULL)
        {   
            // head ek bar update hoga bsss
            // since head khali therefore entered data is for head Node and 
            // THEREFORE make first node address as head
            
            head = newNode;  

        }
        else   // update the next (ie address data member of the node to store the address of the next NODE)
        {

            // newNode -> next = newNode;  dont do this always use the head not the actuall use head address by storing in temp pointer to get to the last node and put the new address instead of null

            Node *temp = head;

            while(temp -> next != NULL)
            {

                temp = temp -> next;

            }

            // reach last node now  connect last node to this newNode

            temp -> next = newNode;

        }

        // get data
        cin >> data;
    

    }

    return head;

}

void print(Node *head)
{

    // store head in temp to use head

    Node *temp = head;

    while(temp != NULL)
    {

        cout << temp -> data << " ";
        // move your temp to next Node address

        temp = temp -> next;

    }

}

int main()
{

    Node *head = takeInput();

    print(head);

}