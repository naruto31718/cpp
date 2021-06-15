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

bool sortbysecdesc(const pair<int, int> &a,
                   const pair<int, int> &b)
{
 return (double)(a.second / a.first) > (double)(b.second / b.first);
}

double fractional_kansack(int n, int weights[], int profit[], int capacity)
{
 double prof;
 int curr_weight = 0;
 vector<pair<int, double>> prof_with_weights;
 for (int i = 0; i < n; i++)
 {
  prof_with_weights.push_back(make_pair(weights[i], profit[i]));
 }
 sort(prof_with_weights.begin(), prof_with_weights.end(), sortbysecdesc);

 for (int i = 0; i < n; i++)
 {
  if (prof_with_weights[i].first + curr_weight <= capacity)
  {
   curr_weight += prof_with_weights[i].first;
   prof += prof_with_weights[i].second;
  }
  else
  {
   int remain = capacity - curr_weight;
   prof += prof_with_weights[i].second * (double)(remain / prof_with_weights[i].first);
   break;
  }
 }
 return prof;
}

int main()
{
 int weights[] = {2, 3, 5, 7, 1, 4, 1};
 int profits[] = {10, 5, 15, 7, 6, 18, 3};
 int capacity = 15;
 cout << fractional_kansack(7, weights, profits, capacity) << endl;
}
// #include <bits/stdc++.h>

// using namespace std;

// // Structure for an item which stores
// // weight & corresponding value of Item
// struct Item
// {
//  int value, weight;

//  // Constructor
//  Item(int value, int weight)
//      : value(value), weight(weight)
//  {
//  }
// };

// // Comparison function to sort Item
// // according to val/weight ratio
// bool cmp(struct Item a, struct Item b)
// {
//  double r1 = (double)a.value / a.weight;
//  double r2 = (double)b.value / b.weight;
//  return r1 > r2;
// }

// // Main greedy function to solve problem
// double fractionalKnapsack(struct Item arr[],
//                           int N, int size)
// {
//  // Sort Item on basis of ratio
//  sort(arr, arr + size, cmp);

//  // Current weight in knapsack
//  int curWeight = 0;

//  // Result (value in Knapsack)
//  double finalvalue = 0.0;

//  // Looping through all Items
//  for (int i = 0; i < size; i++)
//  {

//   // If adding Item won't overflow,
//   // add it completely
//   if (curWeight + arr[i].weight <= N)
//   {
//    curWeight += arr[i].weight;
//    finalvalue += arr[i].value;
//   }

//   // If we can't add current Item,
//   // add fractional part of it
//   else
//   {
//    int remain = N - curWeight;
//    finalvalue += arr[i].value * ((double)remain / arr[i].weight);

//    break;
//   }
//  }

//  // Returning final value
//  return finalvalue;
// }

// // Driver Code
// int main()
// {
//  // Weight of knapsack
//  int N = 15;

//  // Given weights and values as a pairs
//  Item arr[] = {{10, 2},
//                {5, 3},
//                {15, 5},
//                {7, 7},
//                {6, 1},
//                {18, 4},
//                {3, 1}};

//  int size = sizeof(arr) / sizeof(arr[0]);

//  // Function Call
//  cout << "Maximum profit earned = "
//       << fractionalKnapsack(arr, N, size);
//  return 0;
// }
