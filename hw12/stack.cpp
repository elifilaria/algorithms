#include <string>
using namespace std;
 
class Stack {
private:
      int top;
      int capacity;
      int *storage;
public:
      Stack(int capacity) {
            if (capacity <= 0)
                  throw string("Stack's capacity must be positive");
            storage = new int[capacity];
            this->capacity = capacity;
            top = -1;
      }
 
      void push(int value) {
            if (top == capacity)
                  throw string("Stack's underlying storage is overflow");
            top++;
            storage[top] = value;
      }

      void pop() {
            if (top == -1)
                  throw string("Stack is empty");
            top--;
      }

      ~Stack() {
            delete[] storage;
      }
};

int main()
{
   Stack s (10);
   s.push(3);
}
