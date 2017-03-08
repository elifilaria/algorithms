#include <iostream>
#include <string>
using namespace std;
#include "elapsed_time.h"
 
class Stack {
private:
      int top;
      int capacity;
      int *storage;

public:
      Stack(int capacity) {
            if (capacity <= 0)
                  cout << "Stack's capacity must be positive" << endl;
            storage = new int[capacity];
            this->capacity = capacity;
            top = -1;
      }
 
      void push(int value) {
            if (top == capacity){
               int* resize_arr = new int[capacity + 100];
               for(int i = 0; i < capacity; i++)
                   resize_arr[i] = storage[i];

               capacity++;
               storage = resize_arr;
               delete[] resize_arr;
            top++;
            storage[top] = value;
      }
 
      void pop() {
            if (top == -1)
                  cout << "Stack is empty" << endl;
            top--;
      }
 

      ~Stack() {
            delete[] storage;
      }
};

int main()
{
   Stack elif(3);
   start_timer();
   for (int i= 0; i < 1000000; ++i) {
       elif.push(i);
}
   double cycles = elapsed_time();
   cout << cycles << endl;

   }
