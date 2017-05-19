#include "VertexCover.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int main() {
	vector <string> data;
	string a;
	ifstream input("input.txt");
	while (input >> a) {
		data.push_back(a);
	}
	input.close();
	bool isdirected = false;
	AdjacencyList test(data, isdirected);
	vector<int> solution = test.vertexCover();
	cout << "{ ";
	for (int i = 0; i < solution.size(); i++) {
		cout << solution[i] << " ";
	}
	cout << "}" << endl;
	
}
