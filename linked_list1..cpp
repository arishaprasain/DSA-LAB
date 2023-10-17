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
    while(current != NULL)
    {
        cout << current->data <<endl;
        current = current->next;
    }
   
}




int main()
{
    //allocating memory dynamically as required
    Node<int>* head = new Node<int>(1);
    Node<int>* second = new Node<int>(2);
    Node<int>* third = new Node<int>(13);
    Node<int>* fourth = new Node<int>(56);
    
    //linking head, second, third and fourth nodes
    head->next  = second;
    second->next  = third;
    third->next  = fourth;
    fourth->next  = nullptr;

    cout<< "Printing manually.." << endl;
    cout << head->get_data()<<endl;
    cout << second->get_data()<<endl;
    cout << third->get_data()<<endl;
    cout << fourth->get_data()<<endl;

    cout<< "Printing by traversing through a function.." << endl;   
    linked_list_traversal(head);

    
    return 0;
}