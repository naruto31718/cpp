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

int Substr(string s2, string s1)
{
 int counter = 0; // pointing s2
 int i = 0;
 for (; i < s1.length(); i++)
 {
  if (counter == s2.length())
   break;
  if (s2[counter] == s1[i])
  {
   counter++;
  }
  else
  {
   // Special case where character preceding the i'th character is duplicate
   if (counter > 0)
   {
    i -= counter;
   }
   counter = 0;
  }
 }
 return counter < s2.length() ? -1 : i - counter;
}

vector<int> matchingStrings(vector<string> strings, vector<string> queries)
{
 vector<int> res;
 for (int i = 0; i < queries.size(); i++)
 {
  string curr = queries[i];
  int freq = 0;
  for (int i = 0; i < strings.size(); i++)
  {
   if (strings[i] == curr)
   {
    freq++;
   }
  }
  res.push_back(freq);
 }
}