#include <iostream>
using namespace std;

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {1, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
};


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

void BFS(int a[][7]){
    Queue q;
    q.size = 100;
    //BFS Implementation
    int node;
    int i = 1;
 
    cout << i;
    visited[i] = 1;
    q.enqueue(i);
    
    while (!q.isEmpty()){
        node = q.dequeue();
        for (int j = 0; j < 7; j++){
            if (a[node][j] == 1 && visited[j] == 0){
                cout << j;
                visited[j] = 1;
                q.enqueue(j);
            }
        }
    }
    return;
};

void DFS(int i){
    cout << i << ' ';
    visited[i] = 1;

    for (int j = 0; j < 7; j++){
        if(a[i][j] == 1 && !visited[j]){
            DFS(j);
        }
    }
};


int main(){

    BFS(a);
    cout << endl;
    DFS(1);
    return 0;
}