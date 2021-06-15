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

void merge(int arr[], int l, int mid, int r)
{

 int n1 = mid - l + 1;
 int n2 = r - mid;

 int a[n1];
 int b[n2];

 for (int i = 0; i < n1; i++)
 {
  a[i] = arr[l + i];
 }
 for (int i = 0; i < n2; i++)
 {
  b[i] = arr[mid + 1 + i];
 }

 int i = 0, j = 0, k = l;

 while (i < n1 && j < n2)
 {
  if (a[i] < b[j])
  {
   arr[k] = a[i];
   k++;
   i++;
  }
  else
  {
   arr[k] = b[j];
   k++;
   j++;
  }
 }

 while (i < n1)
 {
  arr[k] = a[i];
  k++;
  i++;
 }
 while (j < n2)
 {
  arr[k] = b[j];
  k++;
  j++;
 }
}

void mergesort(int arr[], int l, int r)
{
 if (l < r)
 {
  int mid = (l + r) / 2;
  mergesort(arr, l, mid);
  mergesort(arr, mid + 1, r);

  merge(arr, l, mid, r);
 }
}

int main()
{
 int n;
 cin >> n;
 int arr[n];
 for (int i = 0; i < n; i++)
 {
  arr[i] = n - 1 - i;
 }
 mergesort(arr, 0, n - 1);
 for (auto i : arr)
 {
  cout << i << " ";
 }
}