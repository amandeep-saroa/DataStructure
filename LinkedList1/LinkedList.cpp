#include<iostream>
using namespace std;
// will use Node class to make object of own made data type
#include "Node.cpp"

void print(Node * head)  // since address therefore pointer
{

    // always create a temprory pointer to keep the address of head and use that only to travel throug linked list
    // agr tum head ko nhi store krogye linkedlist toh print karlogye leking tum apna 1st node ka address gwa dogye therefore temp pointer mai head store karo and use that not the original one

    Node *tempHead = head;

    // jab tak head ky next(address of next node) is not equal tab tak linked list print hogi
    while(tempHead -> next != NULL)
    {

        // to access the data in head node use arrow notation 
        cout << tempHead -> data << " ";
        // now print next node make it as your head now therefore put address of next node in your head since agli ka address already head node mai therefore head se hi usa next access karo using arrow notation

        tempHead = tempHead -> next;

    }

}

int main()
{
    
    // know we want to crete two nodes(that is object of our own made node) and connect them together to create a linkedlist
    // creating dynamically 
    Node n1(1); 
    // know when the above line is written the data is set to 1 and the address for next is set to NULL;

     //lets create one more node

    Node n2(2);
    // know again when the above line is written the data is set to 1 and the address for next is set to NULL;
    // know we want to connect these two node
    // connect krnye ky liye hamye n1 ky next mai n2 ka address dalna hai therefore hamye use krna hai & to get the address 
    // since we want to add address of n2 into next of n1

    n1.next = &n2;


    // PRINTING LINKEDList 
    // So when we want to print data in each node we can print data of first node by using object of node class and access data from there like n1.data
    // similarly for 2nd node data we can do cout << n2.data

    // Remember we always have to keep track of address of the first node also known as head node in some varaible
    // if we dont do this so that means we have lost the complete linkedlist since first node ie head contains the address of 2nd node and 2nd node contains the address of 3rd node
    Node * head = &n1;  // pointer store the address since we are storing address of node therefore data type is node

  
    // Now we have to print the whole linked list using this head pointer

    cout << head -> data;  // arrow means go to the address place in head pointer and access the data value from that address Node




    Node n3(3);
    Node n4(4);
    Node n5(5);

    // each Node ky next mai agli wali node ka address hoga ie 2nd node ky next mai n3 ka address

    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    // n4.next main automatically null chalgya jaisye para constructor ky pass gye hum

    // make your own print function which will get one argument that is address of head node its data type is also Node since store address of the Node

    print(head);


}