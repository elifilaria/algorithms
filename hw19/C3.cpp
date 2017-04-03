#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int capacity[] = {10,7,4};
int moves=-1;

struct Node {
	int state[3];

	Node(int i, int j, int k) {
		state[0] = i;
		state[1] = j;
		state[2] = k; 
	}

	bool operator==(const Node&n) const {
		return (state[0] == n.state[0] &&
		state[1] == n.state[1] &&
		state[2] == n.state[2]);
	}
	vector <Node> neighbors() const;
	void print(ostream &os) const {
		os << state[0] << " " << state[1] << " " << state[2];
	}
};

ostream &operator<<(ostream &os, const Node &n) {
	n.print(os);
	return os;
}

vector <Node> Node::neighbors() const {
	vector <Node> result;
	for (int from = 0; from < 3; ++from) {
		for (int to=0; to < 3; ++to) {
			int howMuch = state[from];
			if (howMuch + state[to] > capacity[to]) {
				howMuch = capacity[to] - state[to];
			}
			if (howMuch > 0) {
				Node n(*this);
				n.state[to] += howMuch;
				n.state[from] -= howMuch;
				result.push_back(n);
			}
		}
	}
	return result;
}

vector <Node> thingsIveSeen;
bool haveIseen(const Node &n) {
	for (int i=0, i_end = thingsIveSeen.size(); i < i_end; ++i) {
		if (n==thingsIveSeen[i]) {
			return true;
		}
	}
	return false;
}

string spaces(int n) {
	string result;
	for (int i=0; i < n; ++i) {
		result += " ";
	}
	return result;
}


int minDistance(vector<int> dist,vector<Node> nodes, vector<Node> Q)
{
   int min = INT_MAX, min_index;

   for (int v = 0; v < dist.size(); v++){
     // Must be in Q 
   	 Node n = nodes[v];
   	 bool inQ = false;
   	 for(int i=0;i<Q.size();i++){
   	 	if(n == Q[i]) inQ = true;
   	 }
     if (inQ && dist[v] <= min)
         min = dist[v], min_index = v;
 	}

   return min_index;
}

int distance(Node a, Node b){
	return abs(a.state[0] - b.state[0]) + abs(a.state[1] - b.state[1]) + abs(a.state[2] - b.state[2]);
}



void dijkstra(const Node &n) {
	// Find the node in your Q with the smallest dist 
	// Add all its nbrs to the Q & update dist values 
	// Repeat 

	vector<Node> Q;
	Q.push_back(n);

	vector<Node> nodes; //A vector of all the nodes discovered 	
	vector<int> dist; // A vector of distances of each node. So dist[i] is the dist value of nodes[i] 
	vector<int> prev;

	nodes.push_back(n); // Set the first node to dist 0 
	dist.push_back(0);
	prev.push_back(-1);

	while(Q.size() != 0){
		// Find the node with the smallest dist 
		int u_index = minDistance(dist,nodes,Q);
		Node current_node = nodes[u_index];
		vector <Node> nbr = current_node.neighbors();
		Q.pop_back(); // Remove from Q!!! 
		for (int i=0, i_end = nbr.size(); i < i_end; ++i) {
			// Update the distances 
			

			// To do this, we need to find the index of nbr[i]
			// To do that, we need to loop through nodes. If we find nbr[i]
			// get its index. If we don't add it to nodes, and its index is now nodes.size() -1
			int v_index = nodes.size();
			for(int j=0;j<nodes.size();j++){
				if(nodes[j] == nbr[i]){
					v_index = j;
					break;
				}
				if(j == nodes.size()-1){
					// If reached the end and could not find
					// Then add it as newly discovered, and its index is correctly set from before 
					nodes.push_back(nbr[i]);
					dist.push_back(INT_MAX);
					prev.push_back(-1);
				}
			}

			int d = distance(nodes[u_index],nodes[v_index]);
            if(dist[u_index]+d < dist[v_index]){
            	//If this is true, then we've just arrived at v, through a newly discovered shorter path 
            	dist[v_index] = dist[u_index] + d;
            	Q.push_back(nbr[i]);
            	prev[v_index] = u_index;
            }
            
		}
	}
	
	// Construct the final path
	for(int i=0;i<nodes.size();i++){
		cout << nodes[i].state[0] << "," << nodes[i].state[1] << "," << nodes[i].state[2] << endl;
	}
	// vector<int> path;
	// int step = prev[4];
	// path.push_back(4);
	// while(step != -1){
	// 	path.push_back(step);
	// 	step = prev[step];
	// }


	// reverse(path.begin(),path.end());
	// for(int i=0;i<path.size();i++){
	// 	cout << path[i];
	// 	if(i != path.size()-1) cout << ", "; else cout << endl;
	// }
	

}

bool isGoal(const Node &n) {
	return (n.state[1] == 2 || n.state[2] == 2);
}

int main(int argc, char const *argv[])
{
	Node start(0,7,4);
	vector <Node> nbr = start.neighbors();

	//cout << start << endl;

	//for (int i=0, i_end = nbr.size(); i < i_end; ++i) {
		//cout << " " << nbr[i] << endl;
	//}

	dijkstra(start);
	cout <<endl<<"Minimum no. of steps: "<<moves<<endl;
}
