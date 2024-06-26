#include <iostream>
using namespace std;
#define CAPACITY 3

int queue[CAPACITY];
int font=0, rear=0, totalitem=0;

void enqueue(int data){
  if(CAPACITY != totalitem){
    rear = rear % CAPACITY;
    cout<< "rear: "<< rear << endl;
    queue[rear] = data;
    cout << data << " has been enqueue (added)" << endl;
    totalitem++;
    rear++;
  }
  else{
    cout << "Space FUll" << endl;
  }
}

void dequeue(){
  if(totalitem != 0){
    cout  << queue[font] << " has been dequeue (deleted)" << endl;
    queue[font] = 0;
    font = font % CAPACITY;
    totalitem--;
    font--;
  }
  else{
    cout << "No data to dequeue" << endl;
  }
}


void printQueue(){
  for(int i=0; i< CAPACITY; i++){
    cout << queue[i] << ",";
  }
  cout << endl;
}


int main() 
{
  enqueue(10);
  printQueue();
  enqueue(20);
  printQueue();
  enqueue(30);
  printQueue();
  dequeue();
  printQueue();
  enqueue(50);
  printQueue();
  dequeue();
  printQueue();
    
    
}
