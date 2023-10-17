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
Node<T>* push(Node<T>* head, T data)
{
    Node<T>* newNode = new Node<T>();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}




int main()
{
    Node <int>* head = NULL;
    cout << "INSERTION FROM THE FRONT" << endl;
    head = push(head, 100);
    head = push(head, 200);
    head = push(head, 2);

    linked_list_traversal(head);



    
    return 0;
}