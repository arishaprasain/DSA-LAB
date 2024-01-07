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
        void enqueue_at_rear(int val);
        int dequeue_at_front();

        void enqueue_at_front(int val);
        int dequeue_at_rear();

        bool isFull();
        bool isEmpty();
        void displayQueue();
        //void displayInputRestrictedQueue();
};
 bool Queue::isFull()
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

void Queue:: enqueue_at_rear(int val)
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
        cout << "Enqueued at rear: " << array[back] << endl;
        
    }
    //enqueuing elements that aren't the first
    else
    {
        array[++back] = val;
        cout << "Enqueued at rear : " << array[back] << endl;
    }
    
}

void Queue:: enqueue_at_front(int val)
{
    //check if queue is full
    if(isFull())
    {
        cout << "Can't enqueue because the queue is full." << endl;
        
    }
    else if(front == -1 && back == -1 )
    {
        //when queue is empty -> at the beginning
        ++front;
        ++back;
        array[front] = val;
        // cout << "Front : " << front << endl;
        // cout << "Back : " << back << endl;
        cout << "Enqueued at front: " << array[back] << endl;
    }

    //for enqueuing when front is at the first index of the queue
    else if(front == 0 )
    {
        front = size - 1;
        array[front] = val;     //setting front to the last index
        // cout << "Front : " << front << endl;
        // cout << "Back : " << back << endl;

        cout << "Enqueued at front : " << array[front] << endl;
        
    }

    //for enqueuing when front is somewhere in middle of the array and there is place before the front to enque elements
    else if(front != 0)
    {
        --front;
        array[front] = val;     //setting front to the last index
        // cout << "Front : " << front << endl;
        // cout << "Back : " << back << endl;

        cout << "Enqueued at front: " << array[front] << endl;

    }
    
    
    
}

int Queue:: dequeue_at_front()
{
    //check if queue is empty
    if(isEmpty())
    {
        cout << "Can't dequeue , the queue is empty" << endl;
        return -1;
    }
    
    else
    {
        front = (front + 1 ) % size;
        cout << "Successfully dequeued at front : " << array[front - 1] << endl;
        // cout << "Front : " << front << endl;
        // cout << "Back : " << back << endl;
        return array[front-1];
        
    }
    
}

int Queue:: dequeue_at_rear()
{
    //check if queue is empty
    if(isEmpty())
    {
        cout << "Can't dequeue , the queue is empty" << endl;
        return -1;
    }
    
    else
    {
        cout << "Successfully dequeued at rear : " << array[back--] << endl;
        // cout << "Front : " << front << endl;
        // cout << "Back : " << back << endl;
        return array[back + 1];
        
    }
    
}

void Queue::displayQueue()
{
    for (int i = front; i != (back + 1) % size; i = (i + 1) % size)
    {
        cout << array[i] << endl;
    }
}


int main()
{
    Queue q(5);
    cout << "ENQUEUE OPERARTION" << endl;
    q.enqueue_at_rear(10);
    q.enqueue_at_rear(100);
    q.enqueue_at_rear(348);
    q.enqueue_at_front(2345);
    q.enqueue_at_front(3435);
    q.enqueue_at_front(705);
    q.displayQueue();
    
    cout << "DEQUEUE OPERATION" << endl;
    q.dequeue_at_front();
    //q.dequeue_at_front();
    
    cout << "OUTPUT RESTRICTED DOUBLE ENEDE QUEUE AFTER DEQUEUE OEPRATION" <<endl;
    q.displayQueue();


    Queue p(5);
    cout << "ENQUEUE OPERARTION" << endl;
    p.enqueue_at_rear(34);
    p.enqueue_at_rear(4);
    p.enqueue_at_rear(6);
    p.enqueue_at_rear(45);
    p.enqueue_at_rear(569);
    
    p.displayQueue();
    
    cout << "DEQUEUE OPERATION" << endl;
    p.dequeue_at_front();
    p.dequeue_at_rear();
    
    cout << "INPUT RESTRICTED DOUBLE ENEDE QUEUE AFTER DEQUEUE OEPRATION" <<endl;
    p.displayQueue();
    
}








