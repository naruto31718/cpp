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

int hourglassSum(vector<vector<int>> arr)
{
 int sum = INT_MIN;
 for (int i = 0; i < 4; i++)
 {
  int curr = 0;
  for (int j = 0; j < 4; j++)
  {
   curr += arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
   sum = max(sum, curr);
  }
 }
 return sum;
}

int main()
{
 vector<vector<int>> a;
 for (int i = 0; i < 5; i++)
 {
  for (int j = 0; j < 5; j++)
  {
   cin >> a[i][j];
  }
 }
 cout << hourglassSum(a);
}