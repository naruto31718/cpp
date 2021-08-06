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

void heapify(vector<int> &arr, int i, int n) //for max heap
{
 int curr = i;
 int left = 2 * i + 1;
 int right = 2 * i + 2;
 if (left < n && arr[left] > arr[curr])
 {
  curr = left;
 }
 if (right < n && arr[right] > arr[curr])
 {
  curr = right;
 }
 if (curr != i)
 {
  int tmp = arr[curr];
  arr[curr] = arr[i];
  arr[i] = tmp;
  heapify(arr, curr, n);
 }
}

void heapSort(vector<int> &arr)
{
 int n = arr.size();
 int above_leaf_node = (arr.size() / 2) - 1;
 for (int i = above_leaf_node; i >= 0; i--)
 {
  heapify(arr, i, n);
 }
 for (int i = n - 1; i > 0; i--)
 {
  int temp = arr[0];
  arr[0] = arr[i];
  arr[i] = temp;
  heapify(arr, 0, i);
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
 // int above_leaf_node = (heap.size() / 2) - 1;
 // for (int i = above_leaf_node; i >= 0; i--)
 // {
 //  heapify(heap, i,heap.size());
 // }
 heapSort(heap);
 for (auto i : heap)
 {
  cout << i << " ";
 }
}