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
#include <stdio.h>
#include <time.h>

#define ll long long

using namespace std;

int main()
{
 stack<int> e;
 stack<int> m;
 int Max = INT_MIN;
 int n;
 cin >> n;
 while (n--)
 {
  int choice;
  cin >> choice;
  if (choice == 1)
  {
   int x;
   cin >> x;
   Max = max(Max, x);
   e.push(x);
   if (m.empty())
   {
    m.push(Max);
   }
   if (Max != m.top())
   {
    m.push(Max);
   }
  }
  else if (choice == 2)
  {
   if (m.top() == e.top())
   {
    m.pop();
    if (!m.empty())
    {
     Max = m.top();
    }
    else
    {
     Max = INT_MIN;
    }
   }
   e.pop();
   // if (e.empty())
   // {
   //  while (!m.empty())
   //  {
   //   m.pop();
   //  }
   // }
  }
  else if (choice == 3)
  {
   cout << m.top() << endl;
  }
 }
}