#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

const int MAX = 100;

int findPeak(vector<int> arr)
{
 int l = 0, r = arr.size() - 1;
 while (l <= r)
 {
  int mid = (l + r) / 2;
  if (mid - 1 >= 0 && arr[mid] < arr[mid - 1])
  {
   r = mid;
  }
  else if (mid + 1 < arr.size() && arr[mid] < arr[mid + 1])
  {
   l = mid + 1;
  }
  else
  {
   return mid;
  }
 }
 return -1;
}

int findMax(int arr[][MAX], int rows, int mid, int &max)
{
 int max_index = 0;
 for (int i = 0; i < rows; i++)
 {
  if (max < arr[i][mid])
  {
   // Saving global maximum and its index
   // to check its neighbours
   max = arr[i][mid];
   max_index = i;
  }
 }
 return max_index;
}

// Function to find a peak element
int findPeakRec(int arr[][MAX], int rows, int columns, int mid)
{
 // Evaluating maximum of mid column. Note max is
 // passed by reference.
 int max = 0;
 int max_index = findMax(arr, rows, mid, max);

 // If we are on the first or last column,
 // max is a peak
 if (mid == 0 || mid == columns - 1)
  return max;

 // If mid column maximum is also peak
 if (max >= arr[max_index][mid - 1] && max >= arr[max_index][mid + 1])
  return max;

 // If max is less than its left
 if (max < arr[max_index][mid - 1])
  return findPeakRec(arr, rows, columns, mid - ceil((double)mid / 2));

 // If max is less than its left
 // if (max < arr[max_index][mid+1])
 return findPeakRec(arr, rows, columns, mid + ceil((double)mid / 2));
}

// A wrapper over findPeakRec()
int findPeak(int arr[][MAX], int rows, int columns)
{
 return findPeakRec(arr, rows, columns, columns / 2);
}

int main()
{
 int n;
 cin >> n;
 vector<int> arr;
 for (int i = 0; i < n; i++)
 {
  int data;
  cin >> data;
  arr.push_back(data);
 }
 cout << findPeak(arr) << endl;
 return 0;
}