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
#define v 9

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

vector<int> dijkstrasMinDist(int graph[v][v])
{
 vector<bool> visited(v, false);
 vector<int> dist(v, INT_MAX);
 dist[0] = 0;
 for (int i = 0; i < v - 1; i++)
 {
  int currVertex = minVertex(dist, visited);
  visited[currVertex] = true;

  for (int j = 0; j < v; j++)
  {
   if (graph[currVertex][j] != 0 && visited[j] == false && dist[currVertex] != INT_MAX && dist[currVertex] + graph[currVertex][j] < dist[j])
   {
    dist[j] = dist[currVertex] + graph[currVertex][j];
   }
  }
 }
 return dist;
}

int main()
{
 int graph[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                    {4, 0, 8, 0, 0, 0, 0, 11, 0},
                    {0, 8, 0, 7, 0, 4, 0, 0, 2},
                    {0, 0, 7, 0, 9, 14, 0, 0, 0},
                    {0, 0, 0, 9, 0, 10, 0, 0, 0},
                    {0, 0, 4, 14, 10, 0, 2, 0, 0},
                    {0, 0, 0, 0, 0, 2, 0, 1, 6},
                    {8, 11, 0, 0, 0, 0, 1, 0, 7},
                    {0, 0, 2, 0, 0, 0, 6, 7, 0}};
 vector<int> distance_from_0 = dijkstrasMinDist(graph);
 for (auto i : distance_from_0)
 {
  cout << i << " ";
 }
}