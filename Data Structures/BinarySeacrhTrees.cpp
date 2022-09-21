#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *createNode(int data, node *parentNode)
{
    node *p = new node();
    p->data = data;
    p->right = NULL;
    p->left = NULL;

    if (parentNode->left == NULL)
    {
        parentNode->left = p;
        return p;
    }
    else if (parentNode->right == NULL)
    {
        parentNode->right = p;
        return p;
    }
    else
    {
        cout << "Enter parent node with an NULL pointer." << endl;
        return p;
    }
};

void preOrderTraversal(node *root)
{
    if (root != NULL)
    {
        cout << root->data << ' ';
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
};

void inOrderTraversal(node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        cout << root->data << ' ';
        inOrderTraversal(root->right);
    }
};

void postOrderTraversal(node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << ' ';
    }
};

bool isBST(node *root)
{
    static node *prev = NULL;

    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return false;
        }
        if (prev != NULL && root->data < prev->data)
        {
            return false;
        }
        prev = root;
        return isBST(root->right);
    }
    return 1;
};

node *bstSearch(node *root, int key)
{
    if (root == NULL)
    {
        cout << "NULL root provided." << endl;
        return NULL;
    }
    else if (root->data == key)
    {
        cout << "Found that bitch!" << endl;
        return root;
    }

    if (key < root->data)
    {
        bstSearch(root->left, key);
    }
    else
    {
        bstSearch(root->right, key);
    }
};

node *searchIter(node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            cout << "Found that bitch!" << endl;
            return root;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
};

void insertInBST(node *root, int key)
{
    node *prev = new node();
    node *insert = new node();
    insert->data = key;
    insert->left = NULL;
    insert->right = NULL;

    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            cout << "Kitni baar daalega bhai, hai pehle se hi usme." << endl;
            return;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if (key > prev->data)
    {
        prev->right = insert;
    }
    else
    {
        prev->left = insert;
    }
}

node *inOrderPredecessor(node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
};

node *deleteNode(node *root, int value)
{
    node *iPre;
    if (root == NULL)
    {
        return root;
    }

    if (root->left == NULL && root->right == NULL && root->data == value)
    {
        delete root;
        return NULL;
    }

    if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
};

int main()
{
    node *root = new node();
    root->left = NULL;
    root->right = NULL;
    root->data = 10;

    node *n1 = createNode(7, root);
    node *n2 = createNode(19, root);
    node *n3 = createNode(2, n1);
    node *n4 = createNode(8, n1);
    node *n5 = createNode(12, n2);
    node *n6 = createNode(20, n2);

    cout << endl << "preOrderTraversal:" << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "postOrderTraversal:" << endl;
    postOrderTraversal(root);
    cout << endl << "InOrderTraversal:" << endl;
    inOrderTraversal(root);
    cout << endl;

    cout << "Checking whether given tree is BST: " << isBST(root) << endl;

    int key;
    cout << "Enter the number you want to search for: ";
    cin >> key;
    cout << "Searching for " << key << " in the BST using Binary Search" << endl
         << bstSearch(root, key) << endl;
    cout << "Searching for " << key << " in the BST using Iterative Search" << endl
         << searchIter(root, key) << endl;

    insertInBST(root, 45);
    inOrderTraversal(root);
    cout << endl;
    deleteNode(root, 10);
    inOrderTraversal(root);

    return 0;
}