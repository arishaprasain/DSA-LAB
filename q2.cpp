// Perform enqueue and dequeue operations in Circular Queue

#include <iostream>
using namespace std;

class CircularQueue
{
    private:
        int front = -1;
        int back = -1;
        int size = 10 ;
        int *array;

    public:
        CircularQueue(){};
        CircularQueue(int maxSize = 10)
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
 bool CircularQueue::isFull()
{
    if (front == (back + 1) % size )
    {
        cout << "Queue is full" << endl;
        return true;
    }
    else
    {
        return false;
    }
    
}

 bool CircularQueue::isEmpty()
{
    if (front == -1)    // when queue hasn't been initialised ever
    {
        cout << "Queue is empty" << endl;
        return true;
    }
    else if(front == back + 1)  // when queue is made full and all elements dequeued
    {
        front = -1;
        back = -1;
        return true;
    }
    else
        return false;
}

void CircularQueue:: enqueue(int val)
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
        cout << "Successfully enqueued 1st elemet " << array[back] << endl;
        cout << " Back:" << back << endl;
        cout << "front : " << front << endl;
        
        
    }
    //enqueuing elements that aren't the first
    else
    {
        back = (back +1 ) % size ;
        array[back] = val;
        cout << "Successfully enqueued  elemet " << array[back] << endl;
        cout << " Back:" << back << endl;
        cout << "front : " << front << endl;
        
    }
    
}

int CircularQueue:: dequeue()
{
    //check if queue is empty
    if(isEmpty())
    {
        cout << "Can't dequeue , the queue is empty" << endl;
        return -1;
    }
    
    else
    {
        //front = -1;
        //back = -1;
        cout << "Successfully dequeued " << array[front] << endl;
        front++;
        cout << " Back:" << back << endl;
        cout << "front : " << front << endl;
        return array[front-1];
        
    }
    
}

void CircularQueue::displayQueue()
{
    for(int i = front  ; i < size ; i++)
    {
        cout << array[i] << endl;
    }
    
}

int main()
{
    CircularQueue q(5);
    cout << "ENQUEUE OPERARTION" << endl;
    q.enqueue(10);
    q.enqueue(100);
    q.enqueue(348);
    q.enqueue(2345);
    q.enqueue(3435);
    q.enqueue(1567);        //wont enqueue
    q.displayQueue();
    
    cout << "DEQUEUE OPERATION" << endl;
    q.dequeue();
    q.dequeue();
    
    cout << "QUEUE AFTER DEQUEUE OEPRATION" <<endl;
    q.displayQueue();
    
     cout << "ENQUEUE OPERARTION" << endl;
     q.enqueue(3705);
     q.enqueue(219);
     
     cout<< "final queue" << endl;
     q.displayQueue();
    
    
}








