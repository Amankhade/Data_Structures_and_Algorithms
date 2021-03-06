#include <iostream>
using namespace std;
#define size 4

int Queue[size];
int front = 0, rear = -1;

void enqueue(int element)
{
    if (rear == size - 1)
    {
        cout << "Queue Overflow!\n";
    }
    else
    {
        rear++;
        Queue[rear] = element;
    }
}

void dequeue()
{
    if (rear == -1)
    {
        cout << "Queue Underflow!\n";
    }
    else
    {
        cout << "Element deleted successfully: " << Queue[front] << endl;
        front++;
    }
}
void display()
{
    cout << endl;
    cout << "Elements in the Queue:\n";
    for (int i = front; i <= rear; i++)
    {
        cout << Queue[i] << endl;
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}
