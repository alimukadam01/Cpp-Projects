#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* createNode(int data, node* parentNode)
{
    node* p = new node();
    p->data = data;
    p->right = NULL;
    p->left = NULL;
    
    
    if (parentNode->left == NULL){
        parentNode->left = p;
        return p;
    }
    else if (parentNode->right == NULL){
        parentNode->right = p;
        return p;
    }
    else{
        cout << "Enter parent node with an NULL pointer." << endl;
        return p;
    }
};

void preOrderTraversal(node* root){
    if (root != NULL){
        cout << root->data << ' ';
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
};

void inOrderTraversal(node* root){
    if (root != NULL){
        inOrderTraversal(root->left);
        cout << root->data << ' ';
        inOrderTraversal(root->right);
    }
};

void postOrderTraversal(node* root){
    if (root != NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << ' ';
    }
};


int main() {
    node* root = new node();
    root->left = NULL;
    root->right = NULL;
    root->data = 1;
    
    node* n1 = createNode(2, root);
    node* n2 = createNode(3, root);
    node* n3 = createNode(4, n1);
    node* n4 = createNode(5, n1);
    node* n5 = createNode(6, n2);
    node* n6 = createNode(7, n2);
    node* n7 = createNode(8, n3);
    
    cout << "PreOrderTraversal:" << endl;
    preOrderTraversal(root);
    cout << endl << "InOrderTraversal:" << endl;
    inOrderTraversal(root);
    cout << endl << "PostOrderTraversal:" << endl;
    postOrderTraversal(root);
    

    return 0;
}