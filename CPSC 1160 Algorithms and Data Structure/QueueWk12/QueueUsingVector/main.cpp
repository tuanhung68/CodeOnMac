#include <iostream>
#include "QueueV.h"

using namespace std;

int main(){
    QueueV<int> q;
    cout << "The initial queue: ";
    q.Enqueue(3);
    q.Enqueue(2);
    q.Enqueue(1);
    q.Enqueue(6);
    q.Enqueue(7);
    q.Display();
    cout << "The new queue: " << endl;
    q.Dequeue();
    q.Enqueue(100);
    q.Display();
    q.Enqueue(1000);
    q.Display();
    q.Enqueue(12);
    q.Display();

    QueueV<double> q2;
    cout << "The initial queue: ";
    q2.Enqueue(2.6);
    q2.Enqueue(10.1);
    q2.Enqueue(7.6);
    q2.Enqueue(40.2);
    q2.Enqueue(7.3);
    q2.Display();

    cout << "The new queue: " << endl;
    q2.Enqueue(67.1);
    q2.Enqueue(43.0);
    q2.Display();

    q2.Dequeue();
    q2.Dequeue();
    q2.Display();
    
    q2.Enqueue(100.0);
    q2.Enqueue(99.99);
    q2.Enqueue(77.7);
    q2.Display();
    

    return 0;
}