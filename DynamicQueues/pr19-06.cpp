// This program demonstrates the DynIntQeue class
#include <iostream>
#include "DynIntQueue.h"
#include <string>
using namespace std;

int main()
{
    try {
        string item[5] = { "Hi","Hello","Hey","Howdy","Hail" };
        DynIntQueue<string> iQueue;

        cout << "Enqueuing 5 items...\n";

        // Enqueue 5 items
        for (int k = 0; k < 5; k++)
            iQueue.enqueue(item[k]);

        // Deqeue and retrieve all items in the queue
        cout << "The values in the queue were:\n";
        while (!iQueue.isEmpty())
        {
            string value;
            iQueue.dequeue(value);
            cout << value << "  ";
        }
        cout << endl;
    }
    catch (DynIntQueue<string>::underflow) { cout << "The queue is empty.\n"; }
    catch (DynIntQueue<string>::overflow) { cout << "The queue is full.\n"; }


   return 0;
}