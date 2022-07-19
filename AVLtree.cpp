#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};
/**
 * If the node is null, return 0. Otherwise, return the height of the node
 * 
 * @param N The node whose height is to be calculated.
 * 
 * @return The height of the node.
 */
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
/**
 * It creates a new node with the given key and returns a pointer to the new node
 * 
 * @param key The key of the node.
 * 
 * @return A pointer to a node.
 */
Node *newNode(int key)
{
    Node *a = new Node();
    a->key = key;
    a->left = NULL;
    a->right = NULL;
    a->height = 1;
    return a;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

/**
 * The leftRotate function is used to perform a left rotation on the given node
 * 
 * @param y The node that is being rotated.
 * 
 * @return The new root of the subtree.
 */
Node *leftRotate(Node *y)
{
    Node *x = y->right;
    Node *T2 = x->left;
    x->left = y;
    y->right = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

/**
 * If the key is less than the node's key, then we recurse left. If the key is greater, then we recurse
 * right. Otherwise, we return the node
 * 
 * @param node The node to be inserted.
 * @param key The key to be inserted into the tree.
 * 
 * @return The node that is being returned is the node that is being inserted.
 */
Node *insert(Node *node, int key)
{
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < 1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

/**
 * If the root is not null, print the root, then recursively call preOrder on the left and right
 * subtrees
 * 
 * @param root The root of the tree
 */
void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Ket qua: ";
    preOrder(root);
    return 0;
}
