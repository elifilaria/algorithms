#include <limits.h>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <typeinfo>
using namespace std;

struct coordinates{
	int x;
	int y;
	vector <vector <int> > graph;
	void addMatrix(vector <vector <int > > arg) {
		vector <int> temp;
		for (int i = 0, end1 = arg.size(); i < end1; ++i) {
			temp.erase(temp.begin(), temp.end());
			for (int j = 0, end2 = arg[0].size(); j < end2; ++j) {
				temp.push_back(arg[i][j]);
			}
		graph.push_back(temp);
		}
	}
	void operator= (const coordinates &arg) const{
	    x = arg.x;
	    y = arg.y;
	    int thesize = arg.graph.size();
	    for(int i = 0; i < thesize; ++i) {
	    	
	    }
	}
};

// bool operator< (const coordinates &c1, const coordinates &c2){
//     return (c1.graph[c1.x][c1.y] < c2.graph[c2.x][c2.y]);
// }

bool operator < (const coordinates &arg1, const coordinates &arg2) {
		int left = arg1.graph[arg1.x][arg1.y];
		int right = arg2.graph[arg2.x][arg2.y];
        return (left < right);
}


int findMinDist(int outputarray[], bool inshortestpathtree[], int size) {
    int minimum = INT_MAX;
    int minimumIndex;
    for (int i = 0; i < size; ++i) {
        if (inshortestpathtree[i] == false && outputarray[i] <= minimum) {
            minimum = outputarray[i];
            minimumIndex = i;
        }
    }
    return(minimumIndex);
}

bool invisited(int value, vector<coordinates> visited, int x2, int y2) {
	for (int i = 0, end = visited.size(); i < end; ++i) {
		if (visited[i].graph[x2][y2] == value) {
			return(true);
		}
	}
	return(false);
}

bool dfs(coordinates current, vector<coordinates> stack, vector<coordinates> visited) {
	int row = current.y;
	int value;
	coordinates parent; coordinates parentmirror;
	parent.x = visited[visited.size()-1].x;
	parent.y = visited[visited.size()-1].y; int x2 = row; int y2;
	for (int i = 0, end = current.graph.size(); i < end; ++i) {
		y2 = i;
		value = current.graph[row][i];
		if (value != visited[visited.size()-1].graph[parent.x][parent.y] && !invisited(value, visited, x2, y2)) {
			return(false);
		} else {
			continue;
		}
	}
	return(true);
}

coordinates findNextEdge(coordinates current, coordinates currentmirror, vector <coordinates> stack, vector <coordinates> visited) {
	vector <coordinates> returncoord; coordinates temp;
	int minimum = 0;
	int newmin = 0;
	bool yolo = false;
	for (int i = 0, end1 = current.graph.size(); i < end1; ++i) {
		for (int j = 0, end2 = current.graph[0].size(); j < end2; ++j) {
			if ((i == current.x && j == current.y) || (i == currentmirror.x && j == currentmirror.y)) {
				continue;
			}
			if (current.graph[i][j] > 0 && !yolo) {
				minimum = current.graph[i][j];
				temp.x = i; temp.y = j;
				returncoord.push_back(temp);
				yolo = true;
				continue;
			}
			if (current.graph[i][j] < minimum && current.graph[i][j] > 0 && yolo) {
				temp.x = i;
				temp.y = j;
				returncoord.push_back(temp);
				minimum = current.graph[i][j];
			}
		}
	}
	for (int i = 0, end = returncoord.size(); i < end; ++i) {
		cout << returncoord[i].graph[returncoord[i].x][returncoord[i].y] << endl;
	}
	cout << "FUCK YOU" << endl;
	// sort(returncoord.begin(), returncoord.end());
	 //Now we have all the possible min points, but we haven't checked for cycles
	//check for cycles
	for (int i = 0, end = returncoord.size(); i < end; ++i) {
		cout << "x: " << returncoord[i].x;
		cout << " y: " << returncoord[i].y << endl;;
	}
	for (int i = 0, end = returncoord.size(); i < end; ++i) {
		if (dfs(returncoord[i], stack, visited)) {
			return(returncoord[i]);
		}
	}
	temp.x = -1;
	temp.y = -1;
	return(temp);
}

void kruskal(coordinates arg) {
	coordinates current;
	coordinates currentmirror;
	coordinates next;
	coordinates nextmirror;
	vector<coordinates>visited;
	vector<coordinates>stack;
	current.x = arg.x;
	current.y = arg.y;
	current.graph = arg.graph;
	currentmirror.y = arg.x;
	currentmirror.x = arg.y;
	stack.push_back(current);
	while (visited.size() != arg.graph.size()) {
		next = findNextEdge(current, currentmirror, stack, visited);
		if (next.x == -1 && next.y == -1) {
			continue;
		}
		else {
			stack.push_back(next);
			current.x = next.x;
			current.y = next.y;
		}
	}
}


int main() {
    vector<string> temp;
    ifstream f("input.txt");
    if ( ! f.good() ) {
        cerr << "Error:  unable to open " << "input.txt" << endl;
        exit(-1);
    }
    string s;
    int counter = 0;
    while ( f >> s ) {
        temp.push_back(s); //Throw in the values in a temp vector of type string for now
        ++counter;
    }
    int matrixsize = stoi(temp[2]);
    vector <vector <int > > matrix;    
    vector <int> tmp;
    for(int i = 0; i < matrixsize; ++i) {
        tmp.push_back(0);
    }
    for(int i = 0; i < matrixsize; ++i) {
        matrix.push_back(tmp);
    }
    int totalweight = 0;
    for(int i = 5, numedges = temp.size(); i <= numedges; i+=4) {
        totalweight += stoi(temp[i+2]);
        matrix[stoi(temp[i])][stoi(temp[i+1])] = stoi(temp[i+2]);
        matrix[stoi(temp[i+1])][stoi(temp[i])] = stoi(temp[i+2]);
    }
    cout << "Choose an arbitrary positioning (x, y) coordinates zero indexed to use Kruskal's Algorithm on" << endl;
    for(int i = 0; i < matrixsize; ++i) {
        cout << "[";
        for(int j = 0; j < matrixsize; ++j) {
            if (j == matrixsize-1) {
                cout << matrix[i][j];
            } else {
                cout << matrix[i][j] << ", ";
            }
        }
        cout << "]" << endl;
    }
	coordinates xy;
	xy.addMatrix(matrix);
	int minimum = 0;
	bool yolo = false;
	for (int i = 0, end1 = matrix.size(); i < end1; ++i) {
		for (int j = 0, end2 = matrix[0].size(); j < end2; ++j) {
			if (matrix[i][j] > 0 && !yolo) {
				minimum = matrix[i][j];				
				yolo = true;
			}
			if (matrix[i][j] < minimum && matrix[i][j] > 0 && yolo) {
				xy.x = i;
				xy.y = j;
				minimum = matrix[i][j];
			}
		}
	}
	cout << "MINIMUM " << minimum;
	kruskal(xy);
