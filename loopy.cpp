#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


vector<vector <int> > adj;
vector<int> tracking;

void run(int i, int depth){
	if(depth>7) return;
	tracking.push_back(i);
	for(int j=0, j_end=adj[i].size();j<j_end; j++){
			run(adj[i][j],depth+1);
	}
}


int main(){
	ifstream f("example1.txt");
	int v, e;
	f>>v>>e;
	adj.resize(v);
	int v1, v2;
	while(f >> v1 >> v2){
		adj[v1].push_back(v2);
	}
	run(0, 0);
	
}
