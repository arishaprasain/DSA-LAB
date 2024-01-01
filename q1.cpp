#include <iostream>
using namespace std;

class Queue
{
    private:
        int front = -1;
        int back = -1;
        int size = 10 ;
        int *array;

    public:
        Queue(){};
        Queue(int maxSize = 10)
        {
            size = maxSize;
            array = new int[size];
            
        }
        void enqueue(int val);
        int dequeue();
        bool isFull();
        bool isEmpty();
        void displayQueue();
};
 bool Queue::isFull()
{
    if (back == size - 1)
    {
        cout << "Queue is full" << endl;
        return true;
    }
    else
    {
        return false;
    }
    
}

 bool Queue::isEmpty()
{
    if ((back == - 1) && (front == -1))
    {
        cout << "Queue is empty" << endl;
        return true;
    }
    else
    {
        return false;
    }
    
}

void Queue:: enqueue(int val)
{
    //check if queue is full
    if(isFull())
    {
        cout << "Can't enqueue because the queue is full." << endl;
        
    }
    //for enqueuing first element
    else if(front == -1 && back == -1)
    {
        ++front;
        ++back;
        array[back] = val;
        
    }
    //enqueuing elements that aren't the first
    else
    {
        array[++back] = val;
    }
    
}

int Queue:: dequeue()
{
    //check if queue is empty
    if(isEmpty())
    {
        cout << "Can't dequeue , the queue is empty" << endl;
        return -1;
    }
    
    else
    {
        front++;
        cout << "Successfully dequeued " << array[front - 1] << endl;
        return array[front-1];
        
    }
    
}

void Queue::displayQueue()
{
    for(int i = front; i <= back ; i++)
    {
        cout << array[i] << endl;
    }
    
}

int main()
{
    Queue q(5);
    cout << "ENQUEUE OPERARTION" << endl;
    q.enqueue(10);
    q.enqueue(100);
    q.enqueue(348);
    q.enqueue(2345);
    q.enqueue(3435);
    q.displayQueue();
    
    cout << "DEQUEUE OPERATION" << endl;
    q.dequeue();
    q.dequeue();
    
    cout << "QUEUE AFTER DEQUEUE OEPRATION" <<endl;
    q.displayQueue();
    
}








