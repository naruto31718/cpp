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

void countSort(int arr[], int n)
{
 int k = arr[0];
 for (int i = 0; i < n; i++)
 {
  k = max(k, arr[i]);
 }
 int count[100] = {0};
 for (int i = 0; i < n; i++)
 {
  count[arr[i]]++;
 }
 for (int i = 1; i <= k; i++)
 {
  count[i] += count[i - 1];
 }
 int output[n];
 for (int i = n - 1; i >= 0; i--)
 {
  output[--count[arr[i]]] = arr[i];
 }
 for (int i = 0; i < n; i++)
 {
  arr[i] = output[i];
 }
}

int main()
{
 int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
 countSort(arr, 10);
 for (int i = 0; i < 10; i++)
 {
  cout << arr[i] << " ";
 }
}