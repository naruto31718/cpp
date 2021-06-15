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

// #define fo(a, j, n) for (long long int a = j; a < n; a++)

// #define foe(a, j, n) for (long long int a = j; a <= n; a++)

#define ll long long

// #define pb push_back

// #define max(a, b) (a < b ? b : a)

// #define min(a, b) ((a > b) ? b : a)

void binarySerach(vector<int> arr, int key)
{
 int low = 0;
 int high = arr.size();
 bool flag = false;
 while (low <= high)
 {
  int mid = (low + high) / 2;

  if (arr[mid] == key)
  {
   cout << "key Found" << endl;
   flag = true;
   break;
  }
  else if (key > arr[mid])
  {
   low = mid + 1;
  }
  else
  {
   high = mid - 1;
  }
 }
 if (!flag)
 {
  cout << "key Not Found" << endl;
 }
}

int main()

{

 ios_base::sync_with_stdio(false);

 cin.tie(NULL);

 cout.tie(NULL);

 vector<int> arr;

 int n;
 cin >> n;

 for (int i = 0; i < n; i++)
 {
  int data;
  cin >> data;
  arr.push_back(data);
 }

 int key;

 cin >> key;

 binarySerach(arr, key);
}