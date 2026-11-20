#include <iostream>

class Node{

    public:

        int data;
        Node *next = NULL;

};


class LinkedList
{


    Node *head_ptr;
   
    LinkedList()
        {
        Node *head_ptr;
        }


    void add(int data)
    {

        Node curr;

        if((head_ptr->next) == NULL)
        {
            curr.data = data;
            curr.next = NULL;
            head_ptr = &curr;
            return; 
        }

        Node *traverse = head_ptr;
        while(traverse->next != NULL)
        {
            traverse = traverse->next;
        }

        curr.data = data;
        curr.next = NULL;
        traverse->next = &curr;

        



    }

};