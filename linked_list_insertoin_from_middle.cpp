#include <iostream>

using namespace std;

template <class T>

class Node
{
    
       
    public:
     T data;
        Node* next;
        Node(){};
        Node(T d) 
        {
            data = d;
            Node* next;
        }

        T get_data()
        {
            return  data;
        }
        Node* get_next()
        {
            return  next;
        }

        
       
        
};
template <class T>
Node<T>* push(Node<T>* head, T data)
{
    Node<T>* newNode = new Node<T>();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

template <class T>
void linked_list_traversal(Node<T>* n)     //take head pointer and use it to traverse 
{
    Node<T>* current = n;
    int count = 0; 
    while(current != NULL)
    {
        cout <<"Element " << count << " : "<< current->data <<endl;
        current = current->next;
        count++;
    }
   
}

template <class T>
void insert_after(Node<T>* prev_node, T new_data)
{
    Node<T>* newNode = new Node<T>();
    newNode->data = new_data;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
    // return newNode;
}




int main()
{
    Node <int>* head = NULL;
    cout << "INSERTION FROM THE FRONT" << endl;
    head = push(head, 100);
    Node <int>* second = push(head, 200);
    Node <int>* third = push(second, 2);

    linked_list_traversal(third);

    cout<< "INSERTING IN THE MIDDLE" << endl;
    insert_after(second, 19);
    linked_list_traversal(third);



    
    return 0;
}