#ifndef _VertexCover_
#define _VertexCover_
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
struct Node {
	int data;
	Node* next = NULL;
};
struct Edge {
	int src,dest;
	Edge(int s, int d) {
		src = d; dest = s;
	}
	bool operator==(const Edge& comp) const {
		if (comp.src == src && comp.dest == dest)
			return true;
		return false;
	}
};
class AdjacencyList {
	vector<Node*> Head;
	bool directed;
	vector<Node*> Cover;
	vector<Edge*> edgeList;
	int v;
	int e;
public:
	AdjacencyList(vector<string> data, bool dir = false) {
		//inital nodes
		directed = dir;
		e = toi(data[3]);
		for (int i = 0; i < toi(data[2]); i++) {
			Head.push_back(NULL);
		}
		v = Head.size();
		int first_num = toi(data[5]);
		for (std::vector<string>::const_iterator i = data.end(); i > data.begin() + 4; i -= 3)
		{
			Node *newN1 = new Node;
			Node *newN2 = new Node;
			if (first_num == 1) {
				newN1->data = toi(*(i - 1)) - 1;
				newN2->data = toi(*(i - 2)) - 1;
			}
			else {
				newN1->data = toi(*(i - 1));
				newN2->data = toi(*(i - 2));
			}

			newN1->next = Head[newN2->data];
			Head[newN2->data] = newN1;
			Edge *newEdge = new Edge(newN1->data, newN2->data);
			edgeList.push_back(newEdge);
			//comment this out for directed graphs
			if (!directed) {
				newN2->next = Head[newN1->data];
				Head[newN1->data] = newN2;
			}
		}
		for (int i = 0; i < toi(data[2]); i++) {
			Node *newN = new Node;
			newN->data = i;
			newN->next = Head[i];
			Head[i] = newN;
		}
		//reverse edgeList for legibility
		std::reverse(edgeList.begin(), edgeList.end());

	};
	int toi(string v) {
		return atoi(v.c_str());
	}
private:
	bool complete_solution(vector<int> v1) {
		//boolean vector used to determine if all edges are covered

		vector<bool> bl(e);
		if (v1.size() == 0) {
			return false;
		}
		else {
			//lets look at every vertex to see what it covers
			for (int i = 0; i < v1.size(); i++) {
				Node* start = Head[v1[i]];
				Node* Nextex = start->next;
				//check edges
				while (Nextex != NULL) {
					Edge* e = new Edge(start->data, Nextex->data);
					Edge* o = new Edge(Nextex->data, start->data);
					for (int i = 0; i < edgeList.size(); i++) {
						if ((!directed && (*edgeList[i] == *e || *edgeList[i] == *o)) || (directed && *edgeList[i] == *o)) {
							bl[i] = true;
							break;
						}
					}
					delete(e);
					delete(o);
					Nextex = Nextex->next;
				}
			}
			for (int i = 0; i < bl.size(); i++) {
				//a vertex is not covered by this solution
				if (bl[i] == false) {
					return false;
				}
			}
			//all edges were covered this solution works
			for (int i = 0; i < v1.size(); i++) {
				cout << v1[i] << " ";
			}
			cout << endl;
			return true;
		}
	}
public:
	vector<int> vertexCover() {
		vector<int> best;
		unsigned long long bestsofar =ULLONG_MAX;
		for (unsigned long long i = 0; i < pow(2, v); i++) {
			vector<int> solution;
			for (int j = 0; j < v; j++) {
				if ((i& (1 << j)) > 0) {
					solution.push_back(Head[j]->data);
				}
			}
			if (solution.size() < bestsofar) {
				if (complete_solution(solution)) {
					bestsofar = solution.size();
					cout << "BEST  " << bestsofar << endl;
					best = solution;
				}
			}
			else {
				continue;
			}
		}
		return best;
	}
	void display() {
		Node *output;
		for (int i = 0; i < Head.size(); i++) {
			output = Head[i];
			while (output != NULL) {
				cout << output->data << " -> ";
				output = output->next;
			}
			cout << '#' << endl;
		}
	}
};
#endif  // _VertexCover_
