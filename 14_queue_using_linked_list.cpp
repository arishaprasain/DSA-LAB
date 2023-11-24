#include <iostream>
using namespace std;

class Queue;
class Node
{
private:
    int data;

    Node *next = NULL; // for enqueuing

public:
    Node() {} // default constructor
    Node(int d)
    {
        data = d;
        next = NULL;
    }

    friend class Queue;     // to access the next pointer and 'data' member of this class 
  
};

class Queue
{
private:
    Node *front = NULL; // for dequeuing
    Node *back = NULL;  // for enqueuing
    int queueSize;
    int count = 0;

public:
    Queue() {} // default constructor
    Queue(int size)
    {
        queueSize = size;
    }

    void enqueue(int value)
    {
        ++count;
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        

        if (isEmpty()) // when first element is inserted into the queue
        {
            // cout << "1st if" << endl;
            front = newNode;
            back = newNode;
            cout << "Enqueued : " << value << endl;
        }
        else if (!isFull()) // when other than first element is inserted into the queue
        {
            // cout << "2nd if" << endl;
            back->next = newNode;
            back = newNode;

            cout << "Enqueued : " << value << endl;
        }
        else if (isFull())// when the queue is full
        {
            // cout << "3rd if" << endl;
           
            return;
        } 
        
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Can't dequeue an empty queue. " << endl;
        }

        else 
        {
            Node* temp = front;
            front = front->next;
            cout << "Dequeued : " << temp->data << endl;
            delete temp;
        }
    }

    void display()
    {
        Node *current = front;
        cout << "The elements in the queue are :" << endl;
        while (current != nullptr)
        {

            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool isEmpty()
    {
        if (front == NULL)
        {
            cout << "The queue is empty. " << endl;
            return true;
        }
        else
            return false;
    }

    bool isFull()
    {
        if (count > queueSize)
        {
            cout << "The queue is full. " << endl;
            return true;
        }
        else
            return false;
    }
};

int main()
{
    Queue q(6);
    
    q.enqueue(1);
    q.enqueue(11);
    q.enqueue(111);
    q.enqueue(1232);
    q.enqueue(324);
    q.enqueue(654);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}