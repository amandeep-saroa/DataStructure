#include<string>

class Node
{

    public:

        //data memeber Node will contain data and address of nextNode
        std::string data; // to store string data;
        Node *next;  // store address of next node since stores address of next node therefore pointer is of type NODE 


        // constructor

        Node(std::string data)
        {

            this -> data = data;
            this -> next = NULL;

        }

};