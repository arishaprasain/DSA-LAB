// WRITE AN ALGORITHM AND PROGRAM FOR FOLLOWING CASES IN SINGLY
// LINEAR LINKED LIST:
// 1. INSERTION OPERATIONS
// a. INSERT NODE AT BEGINNING OF THE LIST
// b. INSERT NODE AT END OF THE LIST
// c. INSERT NODE AFTER SPECIFIC NODE
// d. INSERT NODE BEFORE SPECIFIC NODE
// 2. DELETION OPERATIONS
// a. DELETE NODE FROM BEGINNING OF THE LIST
// b. DELETE NODE FROM END OF THE LIST
// c. DELETE NODE AFTER SPECIFIC NODE


#include <iostream>
using namespace std;

class LinkedList;
class Node
{
    private:
        int data;
        Node* next;

    public:
        Node(){};
        Node(int val)
        {
            
            data =val;
            next = NULL;

        }
        friend class LinkedList;
  
};
class LinkedList
{
    private:
        Node* head = NULL;
        Node* tail = NULL;
        int size = 10;          // default size made 10;

    public:
        LinkedList(){};
        LinkedList(Node* n)
        {
            head = n;         

        }

         //INSERTION OPERATIONS
        Node* insert_at_beginning(int val);
        Node* insert_at_end(int val);
        void insert_after_specific(int val);
        void insert_before_specific(int val);

        //DELETION  OPERATIONS
        int delete_at_beginning(int val);
        int delete_at_end(int val);
        int delete_after_specific(int val);

       //display function
       void displayLinkedList(Node * n);


};
// display function
void LinkedList :: displayLinkedList(Node* hd)
{
    cout << "DISPLAYING THE LINKED LIST " << endl;
    Node* current = head;
    while(current->next != NULL)
    {
        cout << current->data << endl;
        current = current->next;
    }
    
}


Node* LinkedList::insert_at_beginning(int v)
{
    //inserting first element in the linked list(LIST EMPTY CONDITION)
    Node* newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        cout << "Inserted at beginning (1st element ) : " << head->data << endl;
        return head;
    }
    
    //inserting non first element at the front (LIST NOT EMPTY CONDITION)
    else
    {
        newNode->next = head;
        head = newNode;
        cout << "Inserted at beginning of linked list : " << head->data << endl;
        return head;
        
    }
}

Node* LinkedList::insert_at_end(int v)
{
    //(LIST EMPTY CONDITION)
    Node* newNode = new Node(v);
    Node* current = head;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        cout << "Inserted at end (1st element ) : " << head->data << endl;
        return tail;
    }
    
    //(LIST NOT EMPTY CONDITION)
    else 
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next  = newNode;
    
        cout << "Inserted at end : " << current->next->data << endl;
        current = current->next;
        current->next = NULL;
        return tail;
       
        
    }
}

//inserttion after specific node
void LinkedList ::insert_after_specific(int val)
{
    int data;
    cout << "Enter data to insert after " << val << " in the new node : " << endl;
    cin >> data ;
    
    Node* newNode = new Node(data);
    
    //list empty condition
    if (head == NULL )
    {
        cout << "List is empty, can't insert after a specific ndoe : " << endl;
        //return tail;
    }
    
    // inserting after a specific node with val as data
    else
    {
        Node* current = head;
        while(current->data != val)
        {
            current = current->next;
        }  // at this point current points to node before the specific node
        
        current = current->next;    //current points to specific node
        newNode->next = current->next;
        current->next = newNode;
        
    }
}

//inserttion before specific node
void LinkedList ::insert_before_specific(int val)
{
    int data;
    cout << "Enter data to insert before " << val << " in the new node : " << endl;
    cin >> data ;
    
    Node* newNode = new Node(data);
    
    //list empty condition
    if (head == NULL )
    {
        cout << "List is empty, can't insert after a specific ndoe : " << endl;
        //return tail;
    }
    
    // inserting before a specific node with val as data
    else
    {
        Node* current = head;
        while(current->next->data != val)
        {
            current = current->next;
        }  // at this point current points to node before the specific node
        
        
        newNode->next = current->next;
        current->next = newNode;
        
        
    }
}

int main()
{
    Node* head = new Node(5);

    LinkedList l(head);
    l.insert_at_beginning(70);
    l.insert_at_beginning(34);
    l.insert_at_beginning(7);
    l.insert_at_beginning(27);
    l.displayLinkedList(head);
    
    
    l.insert_at_end(450);
    l.insert_at_end(2354);
    l.insert_at_end(46);
    l.insert_at_end(575);
    
    l.displayLinkedList(head);
    
    
    return 0;
}
