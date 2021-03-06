#include <iostream>
#include <malloc.h>
using namespace std;

struct bnode
{
    int data;
    bnode *left, *right;
};

bnode *insert(int val)
{
    bnode *newNode = (bnode *)malloc(sizeof(bnode));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void preorderTraversal(bnode *node)
{
    if (node == NULL)
        return;

    cout << node->data << "-->";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void inorderTraversal(bnode *node)
{
    if (node == NULL)
        return;

    inorderTraversal(node->left);
    cout << node->data << "-->";
    inorderTraversal(node->right);
}

void postorderTraversal(bnode *node)
{
    if (node == NULL)
        return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << "-->";
}

int main()
{
    bnode *root = (bnode *)malloc(sizeof(bnode));

    root = insert(10);
    root->left = insert(20);
    root->right = insert(30);
    root->left->left = insert(40);
    root->left->right = insert(50);

    cout << "\nPreorder Sequence: " << endl;
    preorderTraversal(root);

    cout << "\nInorder Sequence: " << endl;
    inorderTraversal(root);

    cout << "\nPostorder Sequence: " << endl;
    postorderTraversal(root);
    return 0;
}
