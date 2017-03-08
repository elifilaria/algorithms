#include <cstdlib>
#include<iostream>
using namespace std;
#include "elapsed_time.h"

class node
{
 public:
    int data;
    node* next;
};

class StackusingList
{
public:
StackusingList(int max)
{
    top = NULL;
    maxnum = max;
    count=0;
}

void push(int element)
{
    node *newTop = new node;
    if(count == maxnum){
        if(top == NULL)
        {
            newTop->data = element;
            newTop->next = NULL;
            top = newTop;
            count++;
}        }
        else
        {
            newTop->data = element;
            newTop->next = top;
            top = newTop;
            count++;
        }
    }

void pop()
{
    if(top == NULL)
            cout << "nothing to pop" << endl;
    else
    {
        node * old = top;
        top = top->next;
        count--;
        delete(old);
    }
}
private:
    node *top;
    int count; //head
    int maxnum;
    int stackData;
};

int main(int argc, char** argv) {
    StackusingList *sl = new StackusingList(1);
    start_timer();
    for (int i= 0; i < 1000000; ++i) {
        sl->push(i);
}
    double cycles = elapsed_time();
    cout << cycles << endl;

    return 0;
}
