#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(){};
        Node(int i)
        {
            data = i;
            Node* next = nullptr;
        }

        int get_data()
        {
            return data;
        }

        Node* get_next()
        {
            return next;
        }

};

Node* push(Node *n, int data)  //insertion to the  last
{
    Node* current = n;          //head is passed
    Node* newNode = new Node();
    current->next = newNode;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;

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

Node* delete_node(Node* head, int data) {
    if (head == nullptr) {
        cout << "The list is empty, and no deletion occurred." << endl;
        return head;
    }

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node found as the first member of the linked list and deleted." << endl;
        return head;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data == data) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Node found and deleted." << endl;
            return head;
        }
        current = current->next;
    }

    cout << "Node not found in the linked list" << endl;
    return head;
}

int main() {
    Node* head = new Node(46);
    Node* second = push(head, 1002);
    Node* third = push(second, 10);
    Node* fourth = push(third, 100);

    cout << "ORIGINAL LIST" << endl;
    linked_list_traversal(head);
    cout << "--------------------------------------------" << endl;

    cout << "CASE 1 : ELEMENT NOT ON THE LIST: " << endl;
    head = delete_node(head, 0);

    linked_list_traversal(head);
    cout << "--------------------------------------------" << endl;

    cout << "CASE 2 : ELEMENT AT THE FIRST POSITION DELETION: " << endl;
    head = delete_node(head, 46);

    linked_list_traversal(head);
    cout << "--------------------------------------------" << endl;

    cout << "CASE 3 : ELEMENT AT OTHER THAN FIRST POSITION DELETION: " << endl;
    head = delete_node(head, 100);

    linked_list_traversal(head);
    cout << "--------------------------------------------" << endl;

    return 0;
}