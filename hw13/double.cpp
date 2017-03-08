#include <iostream>
#include <string>
using namespace std;
 
class Stack {
private:
      int top;
      int capacity;
      int *storage;
      int *storage1;
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
                  capacity *= 2;
                  storage1 = new int[capacity];
                  for (int i= 0; i < capacity-100; ++i) {
                      storage1[i] = storage[i];
       }}   
            
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
   Stack elif(1);
   elif.push(3);
   elif.push(5);
   elif.push(3);

   }

