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

vector<int> rotateLeft(int d, vector<int> arr)
{
 vector<int> res;
 int n = arr.size();
 if (d > n)
 {
  d = d % n;
 }
 for (int i = d; i < arr.size(); i++)
 {
  res.push_back(arr[i]);
 }
 for (int i = 0; i < d; i++)
 {
  res.push_back(arr[i]);
 }
 return res;
}

int main()
{
 vector<int> ans = rotateLeft(10, {41, 73, 89, 7, 10, 1, 59, 58, 84, 77, 77, 97, 58, 1, 86, 58, 26, 10, 86, 51});
 for (auto i : ans)
 {
  cout << i << " ";
 }
}