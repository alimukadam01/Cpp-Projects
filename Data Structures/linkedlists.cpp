#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
};
 
void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
    cout<< endl; 
}

Node* deleteFirst(Node* head)
{
    Node* ptr = head;
    head = head->next;
    delete(ptr);
    
    return head;
    
}

Node* deleteAtIndex(Node* ptr, int index)
{
    Node* p = ptr;
    Node* q = ptr->next;
    
    for(int i = 0; i < (index-1); i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    delete(q);
    
    return ptr;
}


Node* deleteLast(Node* head)
{
    Node* p = head;
    Node* q = head->next;
    
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    delete(q);
    
    return head;
}

Node* deleteAtValue(Node* ptr, int value)
{
    Node* p = ptr;
    Node* q = ptr->next;
    
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    delete(q);
    
    return ptr;
}

 
// Driver code
int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node*fourth = NULL;
    Node*fifth = NULL;
    Node*sixth = NULL;
    Node*seventh = NULL;
    Node*eighth = NULL;
    
    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();
    sixth = new Node();
    seventh = new Node();
    eighth = new Node();
 
    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;
    
    third->data = 3;
    third->next = fourth;
    
    fourth->data = 4;
    fourth->next = fifth;
    
    fifth->data = 5;
    fifth->next = sixth;
    
    sixth->data = 6;
    sixth->next = seventh;
    
    seventh->data = 7;
    seventh->next = eighth;
    
    eighth->data = 8;
    eighth->next = NULL;
 
    printList(head);
    
    head = deleteFirst(head);
    cout<< "After deletion" << endl;
    printList(head);
 
    deleteAtIndex(head, 3);
    cout<< "After deletion at Index 3" << endl;
    printList(head);
    deleteLast(head);
    cout<< "After deletion at End" << endl;
    printList(head);
    deleteAtValue(head, 3);
    cout<< "After deletion of Value 3" << endl;
    printList(head);
    
    return 0;
}