#include<iostream>
using namespace std;
class Node{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
};
int height(Node *N)
{
    if (N==NULL) return 0;
    return N->height;
}
Node* newNode(int key)
{
    Node* a = new Node();
    a->key=key;
    a->left=NULL;
    a->right=NULL;
    a->height=1;
    return a;
}

int main()
{
    return 0;
}
