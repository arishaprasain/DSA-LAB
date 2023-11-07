// implementing stack as abstract data type

#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *array;

public:
    Stack(int s) // default constructor
    {
        size = s;
        top = -1;
        array = new int[size];
        cout << "Stack of size " << size << " successfully allocated!" << endl;
    }
    void push(int num)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow!" << endl;
        }
        else
        {

            array[++top] = num;
            cout << num << " pushed successfully to the top of stack. " << endl;
        }
    }

    void display()
    {
        cout << "The elements are :" << endl;
        for (int i = size - 1; i >= 0; i--)
        {
            if (array[i] == 0)
            {
                continue;
            }
            else
            {
                cout << array[i] << endl;
            }
        }
        cout << "Currrent top element: " << array[top] << endl;
    }
    // pop elements
    void pop()
    {
        //stack is empty case
        if (top == -1)
        {
            cout << "Cannot pop because the stack is empty. " << endl;
        }
        else 
        {
            cout << "Successfully popped " << array[top] << " (topmost element) of the stack!" << endl;
            array[top--] = 0 ;
            
        }

    }
    //peek from top position of the stack
    void peek(int position)
    {
        if (top - position + 1 < 0)
        {
            cout << "Element position invalid! " << endl;
        }
        else 
            cout << "Element at " << position << " position of the stack is " << array[top - position + 1];

    }

    ~Stack()
    {
        delete[] array;
    }
};
int main()
{

    cout << "Hi" << endl;
    Stack s(10);
    cout << "Hillo" << endl;
    s.push(100);
    s.push(214);
    s.push(1055);
    s.push(789);
    s.push(451);

    s.display();

    s.pop();
    s.display();
    s.peek(7);
    s.peek(4);
    return 0;
}