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

using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries)
{
 int lastanswer = 0;
 vector<int> res;
 vector<vector<int>> arr(n, vector<int>());
 for (int i = 0; i < queries.size(); i++)
 {
  int des = queries[i][0];
  int x = queries[i][1];
  int y = queries[i][2];
  if (des == 1)
  {
   int idx = ((x ^ lastanswer)) % n;
   arr[idx].push_back(y);
  }
  else
  {
   int idx = ((x ^ lastanswer)) % n;
   lastanswer += arr[idx][(y % (arr[idx].size()))];
   res.push_back(lastanswer);
  }
 }
 return res;
}

int main()
{
 int n, q;
 cin >> n >> q;
 vector<vector<int>> queries;
 for (int i = 0; i < q; i++)
 {
  for (int j = 0; j < 3; j++)
  {
   cin >> queries[i][j];
  }
 }
 vector<int> ans = dynamicArray(n, queries);
 for (auto i : ans)
 {
  cout << i << endl;
 }
}