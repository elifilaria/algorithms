#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <typeinfo>
using namespace std;
struct water {
    int *juggs;
    int *juggsmax;
    water() {
        juggs = new int[11]; juggsmax = new int[11];
        juggs[4] = 4; juggsmax[4] = 4;
        juggs[7] = 7; juggsmax[7] = 7;
        juggs[10] = 0; juggsmax[10] = 10;
    }
    void print() {
        cout << "Jugg 4 has " << juggs[4] << " out of " << juggsmax[4] << " units of water." << endl;
        cout << "Jugg 7 has " << juggs[7] << " out of " << juggsmax[7] << " units of water." << endl;
        cout << "Jugg 10 has " << juggs[10] << " out of " << juggsmax[10] << " units of water." << endl;
    }
    bool anynegatives() {
        bool four = juggs[4] < 0;
        bool seven = juggs[7] < 0;
        bool ten = juggs[10] < 0;
        if(four || seven || ten) {
            return(true);
        } else {
            return(false);
        }
    }
};

water pour(water current, int from, int to, int unaffected) {
    water returnwater;
    int tocapacity = current.juggsmax[to]-current.juggs[to];
    int fromcapacity = current.juggs[from];
    int actualtransfer;
    if (tocapacity == 0 || fromcapacity == 0) {
        actualtransfer = 0;
    } else {
        actualtransfer = min(tocapacity, fromcapacity);
    }
    if (actualtransfer == 0) {
        return(current);
    } else {
        returnwater.juggs[unaffected] = current.juggs[unaffected];
        returnwater.juggs[to] = current.juggs[to] + actualtransfer;
        returnwater.juggs[from] = current.juggs[from] - actualtransfer;
    }
    return(returnwater);
}

bool same(water water1, water water2) {
    bool four = water1.juggs[4] == water2.juggs[4];
    bool seven = water1.juggs[7] == water2.juggs[7];
    bool ten = water1.juggs[10] == water2.juggs[10];
    // cout << "four " << four << endl;
    // cout << "seven " << seven << endl;
    // cout << "ten " << ten << endl;
    if (four && seven && ten) {
        return(true);
    } else {
        return(false);
    }
}

bool searchVisited(water current, vector <water> visited) {
    for(int i = 0, end = visited.size(); i < end; ++i) {
        if (same(visited[i], current)) {
            return(true);
        }
    }
    return(false);
}

vector <water> findAllPossibleOneStep(water current) {
    vector <water> returnvector;
    water temp;
    temp = pour(current, 4, 7, 10);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
    //     temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 7, 4, 10);
    if(!same(temp, current)) {
        // cout << "pouring " << temp.juggs[4]-current.juggs[4] << " units from 7 to 4." << endl;
        // temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 7, 10, 4);
    if(!same(temp, current)) {
        // cout << "pouring " << temp.juggs[10]-current.juggs[10] << " units from 7 to 10." << endl;
        // temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 10, 7, 4);
    if(!same(temp, current)) {
        // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 10 to 7." << endl;
        // temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 10, 4, 7);
    if(!same(temp, current)) {
        // cout << "pouring " << temp.juggs[4]-current.juggs[4] << " units from 10 to 4." << endl;
        // temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 4, 10, 7);
    if(!same(temp, current)) {
        // cout << "pouring " << temp.juggs[10]-current.juggs[10] << " units from 4 to 10." << endl;
        // temp.print();
        returnvector.push_back(temp);
    }
    return(returnvector);
}

int searchForCorrectSolution(vector<water> visited) {
    int returnint = INT_MAX;
    for(int i = 0, end = visited.size(); i < end; ++i) {
        if (visited[i].juggs[4] == 2 || visited[i].juggs[7] == 2) {
            returnint = i;
        }
    }
    return(returnint);
}

void bfs(water start) {
    deque <water> stack;
    vector <water> tempstack;
    vector <water> visited;
    stack.push_back(start);
    int solution;
    water current;
    while (stack.size() > 0) {
        solution = searchForCorrectSolution(visited);
        if (solution != INT_MAX) {
            cout << "Correct solution found with " << visited[solution].juggs[4] << " units of water in the jug with capacity 4, " << visited[solution].juggs[7] << " units of water in the jug with capacity 7, and " << visited[solution].juggs[10] << " units of water in the jug with capacity 10." << endl;
            break;
        }
        if (tempstack.size() > 0) {
            tempstack.erase(tempstack.begin(), tempstack.end());
        }
        current = stack[0];
        stack.pop_front();
        // cout << "YOLO" << endl;
        // current.print();
        if (searchVisited(current, visited) == false) {
            visited.push_back(current);
            tempstack = findAllPossibleOneStep(current);
            for(int i = 0, end = tempstack.size(); i < end; ++i) {
                if (searchVisited(tempstack[i], visited) == false){
                    stack.push_back(tempstack[i]);
                }
            }
        }
    }
}

int main() {
    vector <vector <int> > waterlists;
    water start;
    bfs(start);
}
