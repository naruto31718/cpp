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

void heapify(vector<int> &arr, int i) //for max heap
{
 int curr = i;
 int left = 2 * i + 1;
 int right = 2 * i + 2;
 if (left < arr.size() && arr[left] > arr[curr])
 {
  curr = left;
 }
 if (right < arr.size() && arr[right] > arr[curr])
 {
  curr = right;
 }
 if (curr != i)
 {
  swap(arr[i], arr[curr]);
  heapify(arr, curr);
 }
}

int main()
{
 vector<int> heap;
 int data;
 cin >> data;
 while (data != 0)
 {
  heap.push_back(data);
  cin >> data;
 }
 int above_leaf_node = (heap.size() / 2) - 1;
 for (int i = above_leaf_node; i >= 0; i--)
 {
  heapify(heap, i);
 }
 for (auto i : heap)
 {
  cout << i << endl;
 }
}