/*
Length of LL

For a given singly linked list of integers, find and return its length. Do it using an iterative method.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains elements of the singly linked list separated by a single space. 
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
Output format :
For each test case, print the length of the linked list.

Output for every test case will be printed in a separate line.
 Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
Sample Output 1 :
7
Sample Input 2 :
2
10 76 39 -3 2 9 -23 9 -1
-1
Sample Output 2 :
8
0
*/

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

        // create newNode put data to constructor
        Node* newNode = new Node(data);

        // if head and tail null that means its the first Node
        if(head == NULL && tail == NULL)
        {

            head = newNode;
            tail = newNode;

        }
        // else only update the tail that means connect to tail of LL to the this newNode and move the tail to this newNode
        else
        {

            tail -> next = newNode;
            tail = tail -> next;

        }

        // get data for another Node
        cin >> data;

    }

    // return head of the LinkedList
    return head;

}

int length(Node *head)
{       
    // always store head in temp pointer and use that to iterate  over the Node
        Node *temp = head;
        int len = 0;
        while(temp != NULL)
        {

            len++;
            // move temp to nextNode
            temp = temp -> next;

        }

        return len;

}

// above length function Time Complexity is of : O(n) since will loop to get to end of n node LinkedList

int main()
{

    Node *head = getLinkedList();

    cout << length(head);
}