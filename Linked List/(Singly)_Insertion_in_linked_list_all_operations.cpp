#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
} *First = NULL, *Last = NULL;
void init(int data)
{
    node *newNode;
    newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    if (First == NULL)
    {
        First = newNode;
        Last = newNode;
    }
    else
    {
        Last->next = newNode;
        Last = newNode;
    }
}
void display(node *ptr)
{
    ptr = First;
    while (ptr != NULL)
    {
        cout << ptr->data << "-->";
        ptr = ptr->next;
    }
}
void Insert_At_Beginning(node *ptr, int data)
{
    ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = First;
    First = ptr;

}
void Insert_At_End(node *ptr, int data)
{
    ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;

    Last->next = ptr;
    Last = ptr;
}
void Insert_at_certain_position(node *ptr, int position, int data)
{
    ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    int i = 0;
    node *point = (node *)malloc(sizeof(node));
    point = First;
    while (i < position - 2)
    {
        point = point->next;
        i++;
    }
    ptr->next = point->next;
    point->next = ptr;
}
int main()
{
    init(5);
    init(10);
    init(3);
    init(7);
    init(6);
    init(4);
    cout << "Linked list before operation:\n";
    display(First);
    cout << "\nLinked list after operation:\n";
    Insert_At_Beginning(First, 12);
    Insert_At_End(Last, 19);
    Insert_at_certain_position(First, 2, 98);
    display(First);
    return 0;
}
