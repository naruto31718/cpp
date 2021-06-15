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

bool check_sorted_array(int arr[], int n)
{
  if (n == 1)
  {
    return true;
    ;
  }
  return (arr[0] < arr[1] && check_sorted_array(arr + 1, n - 1));
}

void print_decreasing_order(int n)
{
  if (n == 0)
  {
    return;
  }
  cout << n << endl;
  print_decreasing_order(n - 1);
}

void print_increasing_order(int n)
{
  if (n == 0)
  {
    return;
  }
  print_increasing_order(n - 1);
  cout << n << endl;
}

int find_first_occurence_in_array(int arr[], int n, int i, int key)
{
  if (i == n)
  {
    return -1;
  }
  if (arr[i] == key)
  {
    return i;
  }
  return find_first_occurence_in_array(arr, n, i + 1, key);
}

int find_last_occurence_in_array(int arr[], int n, int i, int key)
{
  if (i == n)
  {
    return -1;
  }
  if (find_last_occurence_in_array(arr, n, i + 1, key) != -1)
  {
    return find_last_occurence_in_array(arr, n, i + 1, key);
  }
  if (arr[i] == key)
  {
    return i;
  }
  return -1;
}

void reverse_string(string s)
{
  if (s.length() == 0)
  {
    return;
  }
  reverse_string(s.substr(1));
  cout << s[0];
}

void replace_pi_with_value_in_given_string(string s)
{
  if (s.length() == 0)
  {
    return;
  }
  if (s[0] == 'p' && s[1] == 'i')
  {
    cout << "3.14";
    replace_pi_with_value_in_given_string(s.substr(2));
  }
  else
  {
    cout << s[0];
    replace_pi_with_value_in_given_string(s.substr(1));
  }
}

void tower_of_hanoi(int n, char src, char dest, char helper)
{
  if (n == 0)
  {
    return;
  }
  tower_of_hanoi(n - 1, src, helper, dest);
  cout << "moved from " << src << " to " << dest << endl;
  tower_of_hanoi(n - 1, helper, dest, src);
}

string remove_duplicates_from_string(string s)
{
  if (s.length() == 0)
  {
    return "";
  }
  char ch = s[0];
  string ans = remove_duplicates_from_string(s.substr(1));

  if (ch == ans[0])
  {
    return ans;
  }
  return (ch + ans);
}

string move_all_x_to_end(string s)
{
  if (s.length() == 0)
  {
    return "";
  }
  char ch = s[0];
  if (ch == 'x')
  {
    return move_all_x_to_end(s.substr(1)) + ch;
  }
  return ch + move_all_x_to_end(s.substr(1));
}

void print_all_sub_strings(string s, string ans)
{
  if (s.length() == 0)
  {
    cout << ans << endl;
    return;
  }
  char ch = s[0];

  print_all_sub_strings(s.substr(1), ans);
  print_all_sub_strings(s.substr(1), ans + ch);
}

void permutation_of_string(string s, string ans)
{
  if (s.length() == 0)
  {
    cout << ans << endl;
    return;
  }
  for (int i = 0; i < s.length(); i++)
  {
    char ch = s[i];

    string ros = s.substr(0, i) + s.substr(i + 1);

    permutation_of_string(ros, ans + ch);
  }
}

int possible_ways_in_maze(int n, int i, int j)
{
  if (i == n - 1 && j == n - 1)
  {
    return 1;
  }
  if (i >= n || j >= n)
  {
    return 0;
  }
  return possible_ways_in_maze(n, i + 1, j) + possible_ways_in_maze(n, i, j + 1);
}

int tiling_problem(int n)
{
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }
  return tiling_problem(n - 1) + tiling_problem(n - 2);
}

int no_of_ways_for_single_or_paired(int n)
{
  if (n == 0 || n == 1 || n == 2)
  {
    return n;
  }
  return no_of_ways_for_single_or_paired(n - 1) + no_of_ways_for_single_or_paired(n - 2) * (n - 1);
}

int zero_one_knapsack(int c, int n, int val[], int weights[])
{
  if (n == 0 || c == 0)
  {
    return 0;
  }
  if (weights[n - 1] > c)
  {
    return zero_one_knapsack(c, n - 1, val, weights);
  }
  return max(zero_one_knapsack(c - weights[n - 1], n - 1, val, weights) + val[n - 1], zero_one_knapsack(c, n - 1, val, weights));
}

bool rat_in_maze_helper(int **arr, int x, int y, int n)
{
  if (x < n && y < n && arr[x][y] == 1)
  {
    return true;
  }
  return false;
}

bool rat_in_maze(int **arr, int x, int y, int n, int **sol)
{
  if (x == n - 1 && y == n - 1)
  {
    sol[x][y] = 1;
    return true;
  }
  if (rat_in_maze_helper(arr, x, y, n))
  {
    sol[x][y] = 1;
    if (rat_in_maze(arr, x + 1, y, n, sol))
    {
      return true;
    }
    if (rat_in_maze(arr, x, y + 1, n, sol))
    {
      return true;
    }
    sol[x][y] = 0;
    return false;
  }
  return false;
}

void permuteSolve(vector<int> &nums, vector<vector<int>> &ans, int idx)
{
  if (idx == nums.size())
  {
    ans.push_back(nums);
    return;
  }
  for (int i = idx; i < nums.size(); i++)
  {
    swap(nums[i], nums[idx]);
    permuteSolve(nums, ans, idx + 1);
    swap(nums[i], nums[idx]);
  }
}
vector<vector<int>> permute(vector<int> nums)
{
  vector<vector<int>> ans;
  permuteSolve(nums, ans, 0);
  return ans;
}

void solve(vector<int> nums, vector<vector<int>> &ans, int idx)
{
  if (idx == nums.size())
  {
    ans.push_back(nums);
    return;
  }
  for (int i = idx; i < nums.size(); i++)
  {
    if (i != idx and nums[i] == nums[idx])
      continue;
    swap(nums[i], nums[idx]);
    solve(nums, ans, idx + 1);
  }
}
vector<vector<int>> permute_with_repetition(vector<int> nums)
{
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  solve(nums, ans, 0);
  return ans;
}

int main()
{

  // string s = "abcdefghijklmnopqrstuvwxyz";
  // // replace_pi_with_value_in_given_string(s);
  // print_all_sub_strings(s,"");
  // string s = "abc";
  // permutation_of_string(s,"");
  //  int val[] = {100,500,150};
  //  int w[] = {10,60,30};
  // cout<<zero_one_knapsack(50,3,val,w);
  int n;
  cin >> n;
  // int **arr = new int *[n];

  // for (int i = 0; i < n; i++)
  // {
  //   arr[i] = new int[n];
  // }

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < n; j++)
  //   {
  //     cin >> arr[i][j];
  //   }
  // }

  // int **sol = new int *[n];

  // for (int i = 0; i < n; i++)
  // {
  //   sol[i] = new int[n];

  //   for (int j = 0; j < n; j++)
  //   {
  //     sol[i][j] = 0;
  //   }
  // }

  // if (rat_in_maze(arr, 0, 0, n, sol))
  // {
  //   for (int i = 0; i < n; i++)
  //   {
  //     for (int j = 0; j < n; j++)
  //     {
  //       cout << sol[i][j] << " ";
  //     }
  //     cout << endl;
  //   }
  // }
  //
  vector<vector<int>> res = permute_with_repetition({1, 2, 2});
  for (auto i : res)
  {
    for (auto ii : i)
    {
      cout << ii << " ";
    }
    cout << "\n";
  }
}