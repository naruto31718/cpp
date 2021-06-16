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

bool sortbyknapsack(const pair<int, int> &a,
                    const pair<int, int> &b)
{
 return (double)(a.second / a.first) > (double)(b.second / b.first);
}

bool sortbyjob(const pair<int, int> &a,
               const pair<int, int> &b)
{
 return a.first > b.first;
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
 sort(prof_with_weights.begin(), prof_with_weights.end(), sortbyknapsack);

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

int job_sequence(vector<int> profits, vector<int> deadlines, int n)
{
 vector<int> res;
 int profit = 0;
 int max = INT_MAX;
 vector<bool> isFilled(max, false);
 vector<pair<int, int>> profit_sorted;
 for (int i = 0; i < n; i++)
 {
  profit_sorted.push_back(make_pair(profits[i], deadlines[i]));
 }
 sort(profit_sorted.begin(), profit_sorted.end(), sortbyjob);
 for (int i = 0; i < n; i++)
 {
  if (!isFilled[profit_sorted[i].second - 1])
  {
   isFilled[profit_sorted[i].second - 1] = true;
   profit += profit_sorted[i].first;
   res.push_back(i);
  }
  else
  {
   int j = profit_sorted[i].second - 2;
   while (j >= 0)
   {
    if (!isFilled[j])
    {
     isFilled[j] = true;
     profit += profit_sorted[i].first;
     res.push_back(i);
     break;
    }
    j--;
   }
  }
 }
 for (auto i : res)
 {
  cout << i << " ";
 }
 return profit;
}

int main()
{
 vector<int> d = {3, 4, 4, 2, 3, 1, 2};
 vector<int> p = {35, 30, 25, 20, 15, 12, 5};
 cout << job_sequence(p, d, 7) << endl;
}
