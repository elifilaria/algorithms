
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;
 
vector<string> split(const string &line, const char *delim = " \t")
{
  vector<string> word;
  size_t loc0, loc1;
  loc0 = line.find_first_not_of(delim);
  if ( loc0 == string::npos ) return word;
  loc1 = line.find_first_of(delim, loc0);
  while ( loc1 != string::npos ) {
    word.push_back( line.substr(loc0, loc1-loc0) );
    loc0 = line.find_first_not_of(delim, loc1);
    if ( loc0 == string::npos ) break;
    loc1 = line.find_first_of(delim, loc0);
  }
  if ( loc0 != string::npos && loc1 == string::npos )
    word.push_back( line.substr(loc0, line.size()-loc0) );
  return word;
}

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};
 
  
struct AdjList
{
    struct AdjListNode *head;
};
 
class Graph
{
    int V;    // No. of vertices
    struct AdjList* array;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
    void printGraph();
};
 
Graph::Graph(int V)
{
    this->V = V;
    array = new AdjList [V];
    for(int i = 0; i<V; i++){
    	array[i].head = NULL;
    }
}

 AdjListNode* newAdjListNode(int dest)
        {
            AdjListNode* newNode = new AdjListNode;
            newNode->dest = dest;
            newNode->next = NULL;
            return newNode;
        }
 
void Graph::addEdge(int src, int dest)
{
     AdjListNode* newNode = newAdjListNode(dest);
     newNode->next = array[src].head;
     array[src].head = newNode;
     newNode = newAdjListNode(src);
     newNode->next = array[dest].head;
     array[dest].head = newNode;
}
 
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(int i =0; i<V; i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}

 void Graph::printGraph()
        {
            int v;
            for (v = 0; v < V ; ++v)
            {
                AdjListNode* pCrawl = array[v].head;
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (pCrawl)
                {
                    cout<<"-> "<<pCrawl->dest;
                    pCrawl = pCrawl->next;
                }
                cout<<endl;
            }
        }
 
// Driver program to test methods of graph class
int main()
{
  ifstream f("file.txt");
  string line;
  Graph a(5);
  while ( getline(f, line) ) {
    // split the line into words
    vector<string> word = split(line);
  if (word[0] == "e" ) {
       a.addEdge(stoi(word[1]), stoi(word[2]));
     }
   }
  f.close();
  a.printGraph();
  a.BFS(2);
 
    return 0;
}
