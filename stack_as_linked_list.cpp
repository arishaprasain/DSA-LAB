#include <iostream>
using namespace std;
class Stack;
class Node
{
private:
    int data;
    Node *next;

public:
    Node(){};
    Node(int num) : data(num), next(nullptr) {}
    friend class Stack;
};

class Stack
{
private:
    int stackSize;
    Node *top;
    Node *bottom;
    int count = 0;

public:
    Stack(){};
    Stack(int size) : stackSize(size), top(nullptr), bottom(nullptr)
    {
        cout << "Stack made! " << endl;
    }
    friend class Node;
    
    Node *push(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        if (count == 0)
        
        {
            
            bottom = newNode;
            top = newNode;
            cout << "Pushed :" << top->data << endl;;
            count ++ ;
        }
        else
        {
        
            top->next = newNode;
            top = newNode;
            cout << "Pushed :" << top->data << endl;
            count++;
        }

        return top;
    }
    int pop()
    {
        int popped_element;
        if (isEmpty())
        {
            cout << "Stack is empty! Nothing to pop" << endl;
            return 0;
        }
        else if (top == bottom)
        {
            delete top;
            top = bottom = nullptr;
            return bottom->data;
        }
        
        else
        {
            Node* prev;
            Node* current;
            current = top;
            while(current->next != top)
            {
                prev = current;
                current = current->next;
                
            }
            top = prev;
            popped_element = current->data;
            delete current;
            return popped_element;
            
        }
    }
    bool isEmpty()
    {
        return count == 0;
    }
    bool isFull()
    {
        int customSize = 10; // since linked list is endless , a customSize is defined to check for stack overflow
        if (count == stackSize - 1)
        {
            cout << "Stack Overflow!" << endl;
            return true;
        }
    }


    void stackTop()
    {
        cout << "Stack Top : " << top->data << endl;
        
    }
    void stackBottom()
    {
         cout << "Stack Bottom : " << bottom->data << endl;
        
    }
    
    void display_stack()
    {
        Node* current = bottom;
        while(current != top)
        {
            cout << current->data << "->" ;
            current = current->next;
            
            
        }
        cout << current->data << "->" ;
        
    }
    
};

int main()
{
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    stack.stackTop() ;
    stack.stackBottom() ;

    stack.display_stack();
  

    return 0;
}