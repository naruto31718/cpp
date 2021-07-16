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
   int V;          // No. of vertices
   list<int> *adj; // adjacency lists
public:
   Graph(int V);               // Constructor
   void addEdge(int v, int w); // to add an edge to graph
   void DFS();                 // prints all vertices in DFS manner

   // prints all not yet visited vertices reachable from s
   void DFSUtil(int s, vector<bool> &visited);
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

// prints all not yet visited vertices reachable from s
void Graph::DFSUtil(int s, vector<bool> &visited)
{
   // Create a stack for DFS
   stack<int> stack;

   // Push the current source node.
   stack.push(s);

   while (!stack.empty())
   {
      // Pop a vertex from stack and print it
      s = stack.top();
      stack.pop();

      // Stack may contain same vertex twice. So
      // we need to print the popped item only
      // if it is not visited.
      if (!visited[s])
      {
         cout << s << " ";
         visited[s] = true;
      }

      // Get all adjacent vertices of the popped vertex s
      // If a adjacent has not been visited, then push it
      // to the stack.
      for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
      {
         if (!visited[*i])
         {
            stack.push(*i);
         }
      }
   }
}

// prints all vertices in DFS manner
void Graph::DFS()
{
   // Mark all the vertices as not visited
   vector<bool> visited(V, false);

   for (int i = 0; i < V; i++)
      if (!visited[i])
         DFSUtil(i, visited);
}

int main()
{

   clock_t begin, end;
   double time_spent;

   begin = clock(); // Time before calculating Fib number

   //anycode goes here between begin and end
   Graph g(5); // Total 5 vertices in graph
   g.addEdge(1, 0);
   g.addEdge(0, 2);
   g.addEdge(2, 1);
   g.addEdge(0, 3);
   g.addEdge(1, 4);

   cout << "Following is Depth First Traversal\n";
   g.DFS();

   end = clock(); // Time before calculating Fib number

   time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTime Taken %lf ", time_spent);

   return 0;
}
