#include <iostream>
#include <stack>
using namespace std;
#include "elapsed_time.h"

int main ()

{

    stack <int> cards;

    start_timer();
    for (int i= 0; i < 1000000; ++i) {
        cards.push(i);
}
    double cycles = elapsed_time();
    cout << cycles << endl;
}

