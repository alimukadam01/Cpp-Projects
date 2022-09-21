#include <iostream>
using namespace std;

class circularQueue{
    public:
    int size;
    int f = -1;
    int r = -1;
    int* arr = new int [size];
    
    bool isEmpty(){
        if (f == r){
            return true;
        }
        return false;
    }
    
    bool isFull(){
        if(r%size == size -1){
            cout << "Queue is full." << endl;
            return true;
        }
        return false;
    }
    
    void enqueue(int val){
        if (this->isFull()){
            cout << "Queue is full." << endl;
            return;
        }
        else{
            r = r%size + 1;
            arr[r] = val;
        }
    }
    
    int dequeue(){
        if (this->isEmpty()){
            cout << "Queue is empty." << endl;
            return -1;
        }
        else{
            f = f%size + 1;
            return f;
        }
    }
};

int main() {
    circularQueue q1;
    
    q1.isEmpty();
    q1.size = 100;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    
    
    cout << q1.isFull() << endl;
    

    return 0;