#include <iostream>
using namespace std;

class Queue
{
private:
    int queueSize = 10;
    int frontIndex, backIndex;
    int *array;

public:
    Queue()
    {
        cout << "default constructorr called" << endl;
    } // default constructor
    Queue(int s)
    {
        // custom size = 10
        queueSize = s;
        frontIndex = -1;
        backIndex = -1;
        array = new int[queueSize];
        cout << "2nd constructorr called" << endl;
    }

    void enqueue(int data)
    {

        if (!isFull() && (backIndex + 1 <= queueSize))
        {

            array[++backIndex] = data;
        }
    }
    void dequeue()
    {
        //checking front index and back index values of queue
        //cout << "FI : " <<  frontIndex << endl;
        //cout << "BI : " << backIndex << endl;
        if (isEmpty())
        {
            cout << "Can't dequeue, the queue is empty. " << endl;
        }

        else
        {
            ++frontIndex;
            cout << "Dequeued first element of the queue" << endl;
        }
    }

    void display()
    {
        cout << "Displaying elements of the queue" << endl;
        for (int i = frontIndex + 1 ; i <=  backIndex; i++)
        {
            cout << array[i] << endl;
        }
    }

    bool isEmpty()
    {
        if (backIndex == frontIndex)
        {
            cout << "Queue is empty" << endl;
            return true;
        }
        else
            return false;
    }

    bool isFull()
    {
        if (backIndex - frontIndex - 1 == queueSize)
        {
            cout << "Queue is full" << endl;
            return true;
        }
        else
            return false;

            
    }
};

int main()
{
    Queue q(4);
    q.isEmpty();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.isFull();
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.isFull();
    q.isEmpty();

    return 0;
}