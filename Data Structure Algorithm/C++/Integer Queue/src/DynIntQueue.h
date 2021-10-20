#ifndef DYNINTQUEUE_H
#define DYNINTQUEUE_H
#include <iostream>
using namespace std;

class DynIntQueue
{
private:
    //structure for the quede nodes
    struct QueueNode
    {
        int value;       //value in a node
        QueueNode *next; // pointer to the next node
    };
    QueueNode *front; // the front of the queue
    QueueNode *rear;  // the rear of the queue
    int numItems;     // number of items in the queue

public:
    //constructor
    DynIntQueue();
    //Destructor
    ~DynIntQueue();

    //queue operations
    void enqueue(int);
    void dequeue(int &);
    bool isEmpty() const;
    bool isFull() const;
    void clear();
};

//********************************************
// The constructor creates an empty queue.   *
//********************************************
DynIntQueue::DynIntQueue()
{
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}
//********************************************
// Destructor                                *
//********************************************
DynIntQueue::~DynIntQueue()
{
    clear();
}
//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
void DynIntQueue::enqueue(int num)
{
    QueueNode *newNode = nullptr;

    //create a new node and store num there
    newNode = new QueueNode;
    newNode->value = num;
    newNode->next = nullptr;

    //adjust front and rear as necessary
    if (isEmpty())
    {
        // if the queue is empty, then both front and rear are pointing to the same stuff
        front = newNode;
        rear = newNode;
    }
    else
    {
        //if the queue is non empty, then add this newNode to the end of the queue
        rear->next = newNode; // let the previous last node connect to this newNode
        rear = newNode;       // let this node be the last node
    }

    //update the numItems
    numItems++;
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
void DynIntQueue::dequeue(int &num)
{
    QueueNode *temp = nullptr;
    if (isEmpty()) // if the queue is empty, then we cant dequeue anything
    {
        cout << "the queue is empty\n";
    }
    else
    {
        //save the front node value in num
        num = front->value;

        //remove the front node and delete it
        temp = front;
        front = front->next;
        delete temp;

        //update the NumberItems
        numItems--;
    }
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
bool DynIntQueue::isEmpty() const
{
    bool status;
    if (numItems > 0)
    {
        status = false;
    }
    else
    {
        status = true;
    }

    return status;
}

//********************************************
// Function clear dequeues all the elements  *
// in the queue.                             *
//********************************************

void DynIntQueue::clear()
{
    int value; //dummy variable for dequeue
    while (!isEmpty())
    {
        dequeue(value);
    }
}
#endif