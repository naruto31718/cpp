#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'twoStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER maxSum
 *  2. INTEGER_ARRAY a
 *  3. INTEGER_ARRAY b
 */
bool checkValidity(int a, int b, int c)
{
  // check condition
  if (a + b <= c || a + c <= b || b + c <= a)
    return false;
  else
    return true;
}

int main()
{
  cout << checkValidity(4, 2, 4);
}