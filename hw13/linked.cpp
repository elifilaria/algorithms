#include <cstdlib>
#include<iostream>
using namespace std;

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
    if(count == maxnum)
            cout <<"stack is full" << endl;
    else
    {
        node *newTop = new node;
        if(top == NULL)
        {
            newTop->data = element;
            newTop->next = NULL;
            top = newTop;
            count++;
        }
        else
        {
            newTop->data = element;
            newTop->next = top;
            top = newTop;
            count++;
        }
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
    StackusingList *sl = new StackusingList(5);
    sl->push(6);
    sl->pop();

    return 0;
}
