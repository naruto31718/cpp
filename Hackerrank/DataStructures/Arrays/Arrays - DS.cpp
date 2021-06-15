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

vector<int> reverseArray(vector<int> arr)
{
 int n = arr.size();
 for (int i = 0; i < n / 2; i++)
 {
  int temp = arr[i];
  arr[i] = arr[n - 1 - i];
  arr[n - 1 - i] = temp;
 }
 return arr;
}

int main()
{
 vector<int> a = reverseArray({1, 2, 3, 4, 5});
 for (auto i : a)
 {
  cout << i << " ";
 }
}
