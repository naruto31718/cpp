#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>
#include <climits>
#include <string>
#include <stdio.h>
#include <time.h>
#include <list>

#define ll long long

using namespace std;

class Graph
{
     int V; // No. of vertices

     // Pointer to an array containing adjacency
     // lists
     list<int> *adj;

public:
     Graph(int V); // Constructor

     // function to add an edge to graph
     void addEdge(int v, int w);

     // prints BFS traversal from a given source s
     void BFS(int s);
};

Graph::Graph(int V)
{
     this->V = V;
     adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
     adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
     // Mark all the vertices as not visited
     bool *visited = new bool[V];
     for (int i = 0; i < V; i++)
          visited[i] = false;

     // Create a queue for BFS
     list<int> queue;

     // Mark the current node as visited and enqueue it
     visited[s] = true;
     queue.push_back(s);

     // 'i' will be used to get all adjacent
     // vertices of a vertex
     list<int>::iterator i;

     while (!queue.empty())
     {
          // Dequeue a vertex from queue and print it
          s = queue.front();
          cout << s << " ";
          queue.pop_front();

          // Get all adjacent vertices of the dequeued
          // vertex s. If a adjacent has not been visited,
          // then mark it visited and enqueue it
          for (i = adj[s].begin(); i != adj[s].end(); ++i)
          {
               if (!visited[*i])
               {
                    visited[*i] = true;
                    queue.push_back(*i);
               }
          }
     }
}

int main()
{

     clock_t begin, end;
     double time_spent;

     begin = clock(); // Time before calculating Fib number

     //anycode goes here between begin and end

     Graph g(4);
     g.addEdge(0, 1);
     g.addEdge(0, 2);
     g.addEdge(1, 2);
     g.addEdge(2, 0);
     g.addEdge(2, 3);
     g.addEdge(3, 3);

     cout << "Following is Breadth First Traversal "
          << "(starting from vertex 2) \n";
     g.BFS(2);

     end = clock(); // Time before calculating Fib number

     time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

     printf("\nTime Taken %lf ", time_spent);

     return 0;
}
