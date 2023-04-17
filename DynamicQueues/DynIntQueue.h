#include <iostream> 
#include <cstdlib>
using namespace std;

template <class T>
class DynIntQueue
{
   struct QueueNode
   {      
      T value;
      QueueNode *next;
      QueueNode(T value1, QueueNode *next1 = nullptr)
      {
         value = value1;
         next = next1;
      }
   };
   // These track the front and rear of the queue
   QueueNode *front;
   QueueNode *rear;
public:
   // Constructor and Destructor
   DynIntQueue();
   ~DynIntQueue();

   // Member functions
   void enqueue(T);
   void dequeue(T &);
   bool isEmpty() const;
   void clear();
   class underflow {};
   class overflow {};
};



//************************
// Constructor.          *
//************************
template <class T>
DynIntQueue<T>::DynIntQueue()
{
    front = nullptr;
    rear = nullptr;
}

//************************
// Destructor.           *
//************************
template <class T>
DynIntQueue<T>::~DynIntQueue()
{
    QueueNode* garbage = front;
    while (garbage != nullptr)
    {
        front = front->next;
        garbage->next = nullptr;
        delete garbage;
        garbage = front;
    }
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
template <class T>
void DynIntQueue<T>::enqueue(T num)
{
    if (isEmpty())
    {
        front = new QueueNode(num);
        rear = front;
    }
    else
    {
        rear->next = new QueueNode(num);
        rear = rear->next;
    }
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
template <class T>
void DynIntQueue<T>::dequeue(T& num)
{
    QueueNode* temp = nullptr;
    if (isEmpty()) throw underflow;
    else
    {
        num = front->value;
        temp = front;
        front = front->next;
        delete temp;
        temp = nullptr;
    }
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
template <class T>
bool DynIntQueue<T>::isEmpty() const
{
    if (!front) return 1;
    else return 0;
}

//********************************************
// Function clear dequeues all the elements  *
// in the queue.                             *
//********************************************
template <class T>
void DynIntQueue<T>::clear()
{
    string value;   // Dummy variable for dequeue

    while (!isEmpty())
        dequeue(value);
}