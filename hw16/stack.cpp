/*Rewrite the explore procedure (Figure 3.3) so that it is non-recursive
(that is, explicitly use a stack). The calls to previsit and postvisit should be
positioned so that they have the same effect as in the recursive procedure.*/

/*
Figure 3.3 Finding all nodes reachable from a particular node.

procedure explore(G , v)
Input: G = (V, E ) is a graph; v ∈ V
Output: visited(u) is set to true for all nodes u reachable
from v
visited(v) = true previsit(v)
for each edge (v,u) ∈ E:
if not visited(u): explore(u) postvisit(v)
*/

#include <iostream>
#include <string>
#include <stack>
#include <list>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	stack<int> *Moh;
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS(int v);
};

Graph::Graph(int V)
{
	Moh = new stack<int>();
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[])
{
	Moh->push(v);
	visited[v] = true;
	// While stack is not empty
	while(!Moh->empty()){
		// Take the top node
		int node = Moh->top();
		
		cout << node << " ";
		// Remove it off stack
		Moh->pop();
		// Push all neighbours
		list<int>::iterator i;
		//cout << "neighbours of " << node << endl;
		for (i = adj[node].begin(); i != adj[node].end(); ++i){
			if (!visited[*i]){
				Moh->push(*i);
				visited[*i] = true;
				//cout << *i << " ";
			}
		}
		//cout << endl;
	}
}

void Graph::DFS(int v)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	DFSUtil(v, visited);
}

int main(){
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
    g.addEdge(1, 0);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
    g.addEdge(3, 2);
	g.addEdge(2, 1);
    g.addEdge(4, 4);
	g.DFS(2);
    cout << endl;
}
