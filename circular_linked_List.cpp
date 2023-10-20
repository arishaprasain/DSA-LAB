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
            Node* next = nullptr;
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

void circular_linked_list_traversal(Node* head)
{
    Node* current = head;
    cout<< "Printing the circular linked list" << endl;
    cout << head->data << " - 1" << endl;
    int count = 1;
    while (current->next != head)
    {
        count++;
        cout << current->next->data << " - " << count << endl;
        current = current->next;
        if (count == 5)
        {
            break;
        }
    }
    cout << current->next->data << " - " << count++ << endl;

}

Node* push(Node* n, int data)
{
    Node* head = n;
    Node* newNode = new Node();
    newNode->data = data;
    
    head->next = newNode;
    
    return newNode;
}

int main()
{
    Node* head = new Node(46);
    Node* second = push(head, 100);
    Node* third = push(second, 10);
    Node* fourth = push(third, 123);
    fourth->next = head;
    circular_linked_list_traversal(head);
}
