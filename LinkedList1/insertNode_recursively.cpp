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

Node* insertNode(Node* head , int pos , int ele)
{   
    if(head == NULL)
    {

        return head;

    }
    
    // 2 base case
    if(pos == 0)
    {   
        

        // first create New Node 
        Node* newNode = new Node(ele);

        // connect NewNode with head and update your head 
        newNode -> next = head;
        head = newNode;


    }
    else if(pos == 1)
    {

        // create new Node for the data

        Node* newNode = new Node(ele);
        // connect head with newNode and newNode ky next mai rhs of previous head ky right wala node
        Node* temp = head -> next;
        head -> next = newNode;
        newNode -> next = temp;

        //return the head

        return head;


    }
    else
    {

        // rest LL recursive call handle kryga 
        insertNode(head -> next , pos - 1 , ele);

    }
    
    return head;

}
void print(Node * head)  // since address therefore pointer
{

    // always create a temprory pointer to keep the address of head and use that only to travel throug linked list
    // agr tum head ko nhi store krogye linkedlist toh print karlogye leking tum apna 1st node ka address gwa dogye therefore temp pointer mai head store karo and use that not the original one

    Node *tempHead = head;

    // jab tak head ky next(address of next node) is not equal tab tak linked list print hogi
    while(tempHead!= NULL)
    {

        // to access the data in head node use arrow notation 
        cout << tempHead -> data << " ";
        // now print next node make it as your head now therefore put address of next node in your head since agli ka address already head node mai therefore head se hi usa next access karo using arrow notation

        tempHead = tempHead -> next;

    }

}
int main()
{

    Node* head = getLinkedList();

    cout << endl;

    int pos , ele;
    cin >> pos >> ele;

    Node* newHead = insertNode(head , pos , ele);   

    print(newHead);

}