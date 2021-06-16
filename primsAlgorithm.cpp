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
#define v 6

using namespace std;

int minVertex(vector<int> &weight, vector<bool> &visited)
{
 int minvertex;
 int minWeight = INT_MAX;
 for (int i = 0; i < v; i++)
 {
  if (visited[i] == false && weight[i] < minWeight)
  {
   minvertex = i;
   minWeight = weight[i];
  }
 }
 return minvertex;
}

void primsMST(int graph[v][v])
{
 int parent[v];
 vector<int> weight(v, INT_MAX);
 vector<bool> visited(v, false);
 weight[0] = 0;
 parent[0] = -1;
 for (int i = 0; i < v - 1; i++)
 {
  //finding min vertex which is not included in MST
  int currVertex = minVertex(weight, visited);
  visited[currVertex] = true;
  //relaxation
  for (int j = 0; j < v; j++)
  {
   if (graph[currVertex][j] != 0 && visited[j] == false && graph[currVertex][j] < weight[j])
   {
    weight[j] = graph[currVertex][j];
    parent[j] = currVertex;
   }
  }
 }
 for (int i = 1; i < v; i++)
 {
  cout << parent[i] << "-->" << i << " " << weight[i] << endl;
 }
}

int main()
{
 int graph[v][v] = {{0, 4, 6, 0, 0, 0}, {4, 0, 6, 3, 4, 0}, {6, 6, 0, 1, 8, 0}, {0, 3, 1, 0, 2, 3}, {0, 4, 8, 2, 0, 7}, {0, 0, 0, 3, 7, 0}};
 primsMST(graph);
}