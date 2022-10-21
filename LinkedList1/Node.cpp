
// since we want to store two things one is data and other is address of next node 
// and we dont have any such data type that stores two things togerther
// therefore we create our own data type and so we use class ( class is basically user defined data type)
// we want to store two things 1. data which is int 2. is address of next Node since it is address therefore it has to be a pointer and since it store the address of next node therefore pointer has to be of same data type that is Node which is user defind data type

class Node
{

    public:


        int data;  // to store the data value
        Node * next;


        // para constructor so when a user has to create the object(that is node to store in linked list) of this class he/she has to pass the data 

        Node(int data)
        {   

            this -> data = data;
            // and so whenever a new data is added it is obviously the last node of the linkedList therefore next will store Null since it is the last node and no new node is created after this
            this -> next = NULL;

        }

};