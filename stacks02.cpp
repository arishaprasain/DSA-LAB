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

    Node *push(int data)
    {
        if (count == 0)
        {
            bottom->data = data;
            count++;
        }
        else
        {
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = top;
            top = newNode;
            count++;
        }

        return top;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! Nothing to pop" << endl;
            return 0;
        }
        if (top == bottom)
        {
            delete top;
            top = bottom = nullptr;
        }

        Node *temp = top;
        int popped_element = temp->data;
        top = top->next;
        delete temp;
        cout << "Popped Element : " << popped_element << endl;
        return popped_element;
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
    // Peek operation (return the element at a specific position from the top)
    int peek(int position)
    {
        if (position < 1 || position > stackSize)
        {
            cout << "Invalid position for peek." << endl;
            return -1; // You can choose an appropriate value for this case
        }

        Node *current = top;
        for (int i = 1; i < position; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    int stackTop()
    {
        cout << "Stack Top : " << top->data << endl;
        return top->data;
    }
    int stackBottom()
    {
        return bottom->data;
    }
};

int main()
{
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    std::cout << "Stack Top: " << stack.stackTop() << std::endl;
    std::cout << "Stack Bottom: " << stack.stackBottom() << std::endl;

    std::cout << "Peek at position 2: " << stack.peek(2) << std::endl;

    stack.pop();

    std::cout << "After popping, Stack Top: " << stack.stackTop() << std::endl;

    return 0;
}
