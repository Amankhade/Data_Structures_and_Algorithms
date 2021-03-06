#include <iostream>
#include <malloc.h>
using namespace std;
struct Queue
{
    int data;
    struct Queue *link;
} *front = NULL, *rear = NULL;

void enqueue(int data)
{
    Queue *newNode;
    newNode = (Queue *)malloc(sizeof(Queue));
    newNode->data = data;
    newNode->link = NULL;
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->link = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    Queue *ptr = front;
    cout << "Element deleted successfully:" << front->data << endl;
    front = front->link;
    free(ptr);
}

void display()
{
    cout << endl;
    cout << "Elements in the Queue:\n";

    Queue *ptr = front;
    while (ptr != NULL)
    {
        cout << ptr->data << "-->";
        ptr = ptr->link;
    }
    cout << endl;
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