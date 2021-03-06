#include <iostream>
#include <malloc.h>
using namespace std;
struct Stack
{
    int data;
    struct Stack *link;
} *Top = NULL, *Last = NULL;

void push(int data)
{
    Stack *newNode;
    newNode = (Stack *)malloc(sizeof(Stack));
    newNode->data = data;
    newNode->link = NULL;
    if (Top == NULL)
    {
        Top = newNode;
        Last = newNode;
    }
    else
    {
        Last->link = newNode;
        Last = newNode;
    }
}

void pop()
{
    Stack *ptr = Top;
    if (Top == Last)
    {
        if (Top == NULL)
        {
            cout << "Stack Underflow!" << endl;
        }
        else
        {
            cout << "Element popped successfully:" << Last->data << endl;
            Top = NULL;
            free(Last);
        }
    }
    else
    {
        while (ptr->link != Last)
        {
            ptr = ptr->link;
        }
        cout << "Element popped successfully:" << Last->data << endl;
        ptr->link = NULL;
        free(Last);
        Last = ptr;
        free(ptr);
    }
}

void display()
{
    Stack *ptr = Top;
    while (ptr != NULL)
    {
        cout << ptr->data << "-->";
        ptr = ptr->link;
    }
    cout << endl;
}

int main()
{
    int choice;

    char c;
    while (1)
    {
        cout << "\n1. Push an element\n2. Pop an element\n3. Display the stack\n4 .Exit\n"
             << endl;
        cout << "Enter your choice:\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter element: \n";
            cin >> data;
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            cout << "Elements of stack:\n";
            display();
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid Operation\n";
        }
    }
    return 0;
}