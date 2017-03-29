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
    water() { // 23, 29, 31, 37, and 41
        juggs = new int[42]; juggsmax = new int[42];
        juggs[23] = 23; juggsmax[23] = 23;
        juggs[29] = 0; juggsmax[29] = 29;
        juggs[31] = 0; juggsmax[31] = 31;
        juggs[37] = 0; juggsmax[37] = 37;
        juggs[41] = 41; juggsmax[41] = 41;
    }
    void print() {
        cout << "Jugg 23 has " << juggs[23] << " out of " << juggsmax[23] << " units of water." << endl;
        cout << "Jugg 29 has " << juggs[29] << " out of " << juggsmax[29] << " units of water." << endl;
        cout << "Jugg 31 has " << juggs[31] << " out of " << juggsmax[31] << " units of water." << endl;
        cout << "Jugg 37 has " << juggs[37] << " out of " << juggsmax[37] << " units of water." << endl;
        cout << "Jugg 41 has " << juggs[41] << " out of " << juggsmax[41] << " units of water." << endl;
        cout << "\n" << endl;
    }
};

water pour(water current, int from, int to, int unaffected1, int unaffected2, int unaffected3) {
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
        returnwater.juggs[unaffected1] = current.juggs[unaffected1];
        returnwater.juggs[unaffected2] = current.juggs[unaffected2];
        returnwater.juggs[unaffected3] = current.juggs[unaffected3];
        returnwater.juggs[to] = current.juggs[to] + actualtransfer;
        returnwater.juggs[from] = current.juggs[from] - actualtransfer;
    }
    return(returnwater);
}

bool same(water water1, water water2) { // 23, 29, 31, 37, and 41
    bool one = water1.juggs[23] == water2.juggs[23];
    bool two = water1.juggs[29] == water2.juggs[29];
    bool three = water1.juggs[31] == water2.juggs[31];
    bool four = water1.juggs[37] == water2.juggs[37];
    bool five = water1.juggs[41] == water2.juggs[41];
    if (two && one && three && four && five) {
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
    temp = pour(current, 23, 29, 31, 37, 41);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 29, 23, 31, 37, 41);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 23, 31, 29, 37, 41);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 31, 23, 29, 37, 41);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 23, 37, 29, 31, 41);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 37, 23, 29, 31, 41);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 23, 41, 29, 31, 37);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 41, 23, 29, 31, 37);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 29, 31, 23, 37, 41);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 31, 29, 23, 37, 41);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 29, 37, 23, 31, 41);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 37, 29, 23, 31, 41);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 29, 41, 23, 31, 37);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 41, 29, 23, 31, 37);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 31, 37, 23, 29, 41);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 37, 31, 23, 29, 41);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 31, 41, 23, 29, 37);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 41, 31, 23, 29, 37);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 37, 41, 23, 29, 31);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    temp = pour(current, 41, 37, 23, 29, 31);
    if(!same(temp, current)) {
    // cout << "pouring " << temp.juggs[7]-current.juggs[7] << " units from 4 to 7." << endl;
        temp.print();
        returnvector.push_back(temp);
    }
    return(returnvector);
}

int searchForCorrectSolution(vector<water> visited) { //31, 37, and 41 have 4
    int returnint = INT_MAX;
    for(int i = 0, end = visited.size(); i < end; ++i) {
        if (visited[i].juggs[31] == 4 && visited[i].juggs[37] == 4 && visited[i].juggs[41] == 4) {
            cout << "AYY" << endl;
            cout << i << endl;
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
        if (solution != INT_MAX) { //41, 37, 23, 29, 31
            cout << "Correct solution found with " << visited[solution].juggs[23] << " units of water in the jug with capacity 23, " << visited[solution].juggs[29] << " units of water in the jug with capacity 29, " << visited[solution].juggs[31] << " units of water in the jug with capacity 31, " << visited[solution].juggs[37] << " units of water in the jug with capacity 37, and " << visited[solution].juggs[41] << " units of water in the jug with capacity 41." << endl;
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
    cout << "INT MAX" << INT_MAX << endl;
}
