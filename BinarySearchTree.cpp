#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *CreateNode(int init)
{
    Node *p = new Node;
    p->data = init;
    p->left = NULL;
    p->right = NULL;
    return p;
}
typedef Node *Tree;
Tree myTree;
void CreateTree(Tree &root)
{
    root = NULL;
}
void NLR(Tree root)
{
    if (root)
    {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(Tree root)
{
    if (root)
    {
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}
void LRN(Tree root)
{
    if (root)
    {
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
    }
}
void DestroyTree(Tree &root)
{
    if (root)
    {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
}
void AddNode(Tree &root, Node *node)
{
    if (root)
    {
        if (node->data == root->data)
        {
            return;
        }
        if (node->data < root->data)
        {
            AddNode(root->left, node);
        }
        else
        {
            AddNode(root->right, node);
        }
    }
    else
    {
        root = node;
    }
}
Node *FindNode(Tree root, int x)
{
    if (root)
    {
        if (root->data==x) {
            return root;
        }
        else if (x<root->data){
            return FindNode(root->left,x);
        }
        return FindNode(root->right,x);
    }
    return NULL;
}
// node p need to exchange, tree (right tree)
void FindAndReplace1(Tree &p, Tree &tree)
{
    if (tree->left)                     // chưa phải nhỏ nhất (trái nhất)
        FindAndReplace1(p, tree->left); // tiếp tục tìm
    else                                // tree là nút trái nhất
    {
        p->data = tree->data; // copy data
        p = tree;             // trỏ nút p vào nút tree sẽ làm thế mạng bị xóa
        tree = tree->right;   // nút trái không còn tuy nhiên nút phải có thể còn nên ta phải nối chúng lại
    }
}
// nút p là nút cần thay thế, tree là cây đang xét (cây bên trái)
void FindAndReplace2(Tree &p, Tree &tree)
{
    if (tree->right)                     // chưa phải lớn nhất (phải nhất)
        FindAndReplace2(p, tree->right); // tiếp tục tìm
    else                                 // tree là nút trái nhất
    {
        p->data = tree->data; // copy data
        p = tree;             // trỏ nút p vào nút tree sẽ làm thế mạng bị xóa
        tree = tree->left;    // nút phải không còn tuy nhiên nút trái có thể còn nên ta phải nối chúng lại
    }
}
void DeleteNode(Tree &root, int x)
{
    if (root)
    {
        if (x > root->data)
            DeleteNode(root->right, x);
        else if (x < root->data)
            DeleteNode(root->left, x);
        else // nút hiện tại (root) là nút cần xóa
        {
            Node *p = root; // lưu lại nút cần xóa tránh bị ghi đè
            if (!root->left)
                root = root->right; // trường hợp 1
            else if (!root->right)
                root = root->left; // trường hợp 2
            else
                FindAndReplace1(p, root->right); // cách 1
            // FindAndReplace2(p, root->left); // cách 2
            delete p; // xóa nút
        }
    }
    else
    {
        cout << "Not found!\n"; // Không tìm thấy phần tử cần xóa
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Tree tree;
    CreateTree(tree);
    NLR(tree);
    return 0;
}