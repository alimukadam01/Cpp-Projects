#include<iostream>
using namespace std;

class Queue{
  public:
  int size;
  int r = -1;
  int f = -1;
  int* arr = new int [size];
  
  
  bool isEmpty(){
      if(f == r){
          return true;
      }
      return false;
  }
  
  bool isFull(){
      if (r == size - 1){
          return true;
      }
      return false;
  }
  
  void enqueue(int val){
      if (this->isFull()){
          cout << "Queue Overflow!" << endl;
          return;
      }
      else{
          r++;
          arr[r] = val;
          cout << "Success!" << endl;
          return;
      }
  }
  
  int dequeue(){
      if (this->isEmpty()){
          cout << "Queue Empty!" << endl;
          return -1;
      }
      f++;
      return arr[f];
  }
  
  
};

int main() {
   Queue q1;
   q1.size = 100;
   cout << q1.isEmpty() << endl;
   q1.enqueue(1);
   q1.enqueue(2);
   q1.enqueue(3);
   q1.enqueue(4);
   q1.enqueue(5);
   cout << q1.isEmpty() << endl;
   
   cout << "After dequeing..." << endl;
   cout << q1.dequeue() << endl;
   cout << q1.dequeue() << endl;
   cout << q1.dequeue() << endl;
   cout << q1.dequeue() << endl;
   
    return 0;
}