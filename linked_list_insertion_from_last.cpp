#include <iostream>

using namespace std;



class Node
{
    
       
    public:
     int data;
        Node* next;
        Node(){};
        Node(int d) 
        {
            data = d;
            Node* next;
        }

        int get_data()
        {
            return  data;
        }
        Node* get_next()
        {
            return  next;
     }

};     
       
        

Node* push(Node* head, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

void linked_list_traversal(Node* n)     //take head pointer and use it to traverse 
{
    Node* current = n;
    int count = 0; 
    while(current != NULL)
    {
        cout <<"Element " << count << " : "<< current->data <<endl;
        current = current->next;
        count++;
    }
   
}

void insert_at_last(Node* prev_last_node, int new_data)
{
    Node* lastNode = new Node();
    lastNode->data = new_data;
    lastNode->next = NULL;
    prev_last_node->next = lastNode;
    // return newNode;
}




int main()
{
    Node * head = NULL;
    cout << "INSERTION FROM THE FRONT" << endl;
    head = push(head, 100);
    Node * second = push(head, 200);
    Node * third = push(second, 2);  //this is the latest head here

    linked_list_traversal(third);  // so printnig from head i.e.  2,200,100

    cout<< "ADDING A NODE AT LAST" <<endl;
    insert_at_last(head , 902);
    linked_list_traversal(third);

    return 0;
}