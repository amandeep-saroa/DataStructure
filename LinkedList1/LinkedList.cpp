#include<iostream>
using namespace std;
// will use Node class to make object of own made data type
#include "Node.cpp"

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


}