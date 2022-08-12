#include <iostream>
#include "QueueDLL.h"

using namespace std;

int main(){
    cout << "The first queue: " << endl;
    QueueDLL<double> q2;
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
    cout << endl;
   
    // cout << "The second queue: " << endl;
    // QueueDLL<int> q1;
    // cout << "The initial queue: ";
    // q1.Enqueue(2);
    // q1.Enqueue(3);
    // q1.Enqueue(1);
    // q1.Enqueue(10);
    // q1.Enqueue(55);
    // q1.Display();

    // cout << "The new queue: " << endl;
    // q1.Dequeue();
    // q1.Enqueue(5);
    // q1.Enqueue(70);
    // q1.Display();

    // q1.Dequeue();
    // q1.Dequeue();
    // q1.Enqueue(100);
    // q1.Enqueue(200);
    // q1.Enqueue(300);
    // q1.Display();
    // cout << endl;
    
    

    
    return 0;
}