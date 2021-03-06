#include <iostream>
#include <limits.h>
#include <queue>
#include <math.h>
using namespace std;
struct NODE
{
    int key;
    NODE *left;
    NODE *right;
};

NODE *createNode(int data)
{
    NODE *a = new NODE;
    a->key = data;
    a->left = a->right = NULL;
    return a;
}

void Insert(NODE *&pRoot, int x)
{
    if (pRoot == NULL)
        pRoot = createNode(x);
    if (pRoot->key == x)
        return;
    if (pRoot->key > x)
        Insert(pRoot->left, x);
    if (pRoot->key < x)
        Insert(pRoot->right, x);
}

NODE *createTree(int a[], int n)
{
    NODE *pRoot = createNode(a[0]);
    for (int i = 1; i < n; i++)
        Insert(pRoot, a[i]);
    return pRoot;
}

void LNR(NODE *pRoot)
{
    if (!pRoot)
        return;
    LNR(pRoot->left);
    cout << pRoot->key << " ";
    LNR(pRoot->right);
}

void NLR(NODE *pRoot)
{
    if (!pRoot)
        return;
    cout << pRoot->key << " ";
    NLR(pRoot->left);
    NLR(pRoot->right);
}
void LRN(NODE *pRoot)
{
    if (!pRoot)
        return;
    LRN(pRoot->left);
    LRN(pRoot->right);
    cout << pRoot->key << " ";
}
int Height(NODE *pRoot)
{
    int h = 0;
    if (!pRoot)
        return 0;
    h = 1 + max(Height(pRoot->left), Height(pRoot->right));
    return h;
}
void levelOrder(NODE *pRoot)
{
    if (!pRoot)
        return;
    queue<NODE *> q;
    q.push(pRoot);
    while (!q.empty())
    {
        NODE *temp = q.front();
        cout << temp->key << " ";
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
int countNode(NODE *pRoot)
{
    if (pRoot == NULL)
        return 0;
    else
        return 1 + countNode(pRoot->left) + countNode(pRoot->right);
}
int sumNode(NODE *pRoot)
{
    if (pRoot == NULL)
        return 0;
    else
        return pRoot->key + sumNode(pRoot->left) + sumNode(pRoot->right);
}

/**
 * If the root is null, return null. If the key is found, return the root. Otherwise, if the key is
 * less than the root, search the left subtree. Otherwise, search the right subtree
 * 
 * @param pRoot The root of the tree.
 * @param x the value to be searched
 * 
 * @return The node that contains the key x.
 */
NODE *search(NODE *pRoot, int x)
{
    if (pRoot == NULL)
        return NULL;
    if (x == pRoot->key)
        return pRoot;
    else if (x < pRoot->key)
        return search(pRoot->left, x);
    else
        return search(pRoot->right, x);
}

/**
 * If the root is not null, and the root's key is greater than the key to be removed, then remove the
 * key from the left subtree. Otherwise, remove the key from the right subtree. If the root's key is
 * equal to the key to be removed, then if the root has no children, delete the root. Otherwise, if the
 * root has only a right child, then delete the root and replace it with its right child. Otherwise, if
 * the root has only a left child, then delete the root and replace it with its left child. Otherwise,
 * if the root has two children, then replace the root's key with the largest key in the left subtree,
 * and remove that key from the left subtree
 * 
 * @param pRoot the root of the tree
 * @param x the value to be removed
 * 
 * @return the value of the node that is being removed.
 */
void remove(NODE *&pRoot, int x)
{
    if (pRoot == NULL)
        return;
    if (pRoot->key > x)
        remove(pRoot->left, x);
    else
        remove(pRoot->right, x);

    if (pRoot->key == x)
    {
        if (pRoot->left == NULL && pRoot->right == NULL)
        {
            delete pRoot;
            pRoot = NULL;
        }
        else if (pRoot->left == NULL && pRoot->right != NULL)
        {
            NODE *p = pRoot;
            pRoot = pRoot->right;
            delete p;
        }
        else if (pRoot->left != NULL && pRoot->right == NULL)
        {
            NODE *p = pRoot;
            pRoot = pRoot->left;
            delete p;
        }
        else if (pRoot->left != NULL && pRoot->right != NULL)
        {
            NODE *p = pRoot->left;
            while (p->right != NULL)
                p = p->right;
            pRoot->key = p->key;
            remove(pRoot->left, p->key);
        }
    }
}

void removeTree(NODE *&pRoot)
{
    if (pRoot != NULL)
    {
        removeTree(pRoot->left);
        removeTree(pRoot->right);
        delete pRoot;
        pRoot = NULL;
    }
}

int HeightNode(NODE *pRoot, int value)
{
    NODE *p = search(pRoot, value);
    if (p == NULL)
        return -1;
    return Height(p);
}

int Level(NODE *pRoot, NODE *p)
{
    int count = 1;
    NODE *currNode = pRoot;
    int val = p->key;

    while (currNode != p && currNode)
    {
        if (val > currNode->key)
            currNode = currNode->right;
        else
            currNode = currNode->left;
        ++count;
    }

    if (!currNode)
        return -1;
    return count;
}

int countLeaf(NODE *pRoot)
{
    int count = 0;
    if (pRoot == NULL)
        return 0;
    if (pRoot->left == NULL && pRoot->right == NULL)
        return 1;
    else
        return countLeaf(pRoot->left) + countLeaf(pRoot->right);
}

int countLess(NODE *pRoot, int x)
{
    int count = 0;
    if (pRoot == NULL)
        return 0;
    else if (pRoot->key < x)
    {
        count++;
        count += countLess(pRoot->left, x);
        count += countLess(pRoot->right, x);
    }
    else
    {
        count += countLess(pRoot->left, x);
    }
    return count;
}

/**
 * If the current node is greater than the given value, then add 1 to the count and recursively call
 * the function on the left and right subtrees. Otherwise, recursively call the function on the right
 * subtree
 * 
 * @param pRoot pointer to the root of the tree
 * @param x the value to compare against
 * 
 * @return The number of nodes in the tree that are greater than x.
 */
int countGreater(NODE *pRoot, int x)
{
    int count = 0;
    if (pRoot == NULL)
        return 0;
    else if (pRoot->key > x)
    {
        count++;
        count += countGreater(pRoot->left, x);
        count += countGreater(pRoot->right, x);
    }
    else
    {
        count += countGreater(pRoot->right, x);
    }
    return count;
}

int isBSTUtil(NODE *pRoot, int min, int max);

int isBST(NODE *pRoot)
{
    return (isBSTUtil(pRoot, INT_MIN, INT_MAX));
}

/**
 * If the tree is a BST, then the value of every node in the left subtree is less than the value of the
 * current node, which is less than the value of every node in the right subtree
 * 
 * @param pRoot The root of the tree
 * @param min minimum value of the key in the subtree rooted at pRoot
 * @param max The maximum value a node can have.
 * 
 * @return The function isBSTUtil() returns 1 if the given tree is a BST, otherwise returns 0.
 */
int isBSTUtil(NODE *pRoot, int min, int max)
{
    if (pRoot == NULL)
        return 1;
    if (pRoot->key < min || pRoot->key > max)
        return 0;
    return (isBSTUtil(pRoot->left, min, pRoot->key - 1) && isBSTUtil(pRoot->right, pRoot->key + 1, max));
}

/**
 * If the root is NULL, it's a full binary tree. If the root has no children, it's a full binary tree.
 * If the root has two children, it's a full binary tree if both of its children are full binary trees.
 * Otherwise, it's not a full binary tree
 * 
 * @param pRoot The root of the tree
 * 
 * @return The function isFullBST() returns true if the given binary tree is full and false if it is
 * not.
 */
bool isFullBST(NODE *pRoot)
{
    if (pRoot == NULL)
        return true;
    if (pRoot->left == NULL && pRoot->right == NULL)
        return true;
    if ((pRoot->left) && (pRoot->right))
    {
        return (isFullBST(pRoot->left) && isFullBST(pRoot->right));
    }
    return false;
}

int height(NODE *pRoot)
{
    if (pRoot == NULL)
        return 0;
    return 1 + max(height(pRoot->left), height(pRoot->right));
}

bool isAVL(NODE *pRoot)
{
    if (pRoot == NULL)
        return 1;
    if (abs(height(pRoot->left) - height(pRoot->right)) <= 1 && (isAVL(pRoot->left)) && (isAVL(pRoot->right)))
    {
        return 1;
    }
    return 0;
}

int main()
{
    // int a[] = {4, 7, 8, 2, 6};
    // NODE *pRoot = createTree(a, 5);
    // LNR(pRoot);
    // NLR(pRoot);
    // cout << endl;
    // levelOrder(pRoot);
    // LRN(pRoot);
    // cout << endl;
    // cout << Height(pRoot) << endl;
    // cout << countNode(pRoot) << endl;
    // cout << sumNode(pRoot) << endl;
    // NODE* temp = search(pRoot, 4);
    // cout<<Level(pRoot,temp);
    // cout << temp->key;
    // remove(pRoot, 2);
    // LNR(pRoot);
    // removeTree(pRoot);
    // if (pRoot == NULL)
    //     cout << "Removed";
    // cout << countLeaf(pRoot);
    // cout << countGreater(pRoot, 8);
    // cout << isFullBST(pRoot);
    // cout<<isAVL(pRoot);
    NODE *pRoot = createNode(7);
    pRoot->left = createNode(6);
    pRoot->right = createNode(12);
    pRoot->left->left = createNode(4);
    pRoot->left->right = createNode(5);
    pRoot->right->right = createNode(13);
    pRoot->right->right->right=createNode(26);
    if (isAVL(pRoot))
        cout << "The Tree is AVL Tree" << endl;
    else
        cout << "The Tree is not AVL Tree " << endl;
}