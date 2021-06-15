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

int main()

{

 ios_base::sync_with_stdio(false);

 cin.tie(NULL);

 cout.tie(NULL);

 int t;
 cin >> t;

 while (t-- > 0)
 {
  // int n, k;
  // cin >> n >> k;
  // multiset<ll> s;
  // int i;
  // vector<int> vec(n);
  // for (i = 0; i < n; i++)
  //  cin >> vec[i];
  // sort(vec.begin(), vec.end());
  // for (i = 0; i < n; i++)
  // {
  //  int j = i;
  //  while (j < n && vec[j] == vec[i])
  //   j++;
  //  s.insert((j - i) * 1ll * vec[i]);
  //  i = j - 1;
  // }
  // ll sum = 0;
  // int cnt = 0;
  // while (s.size() && cnt < k)
  // {
  //  ll ele = *s.rbegin();
  //  if (ele <= 0)
  //   break;
  //  sum += ele;
  //  cnt++;
  //  s.erase(s.find(ele));
  // }
  // cout << sum << '\n';
  // ll n, q;
  // cin >> n >> q;
  // vector<ll> v;
  // map<ll, ll> map;
  // set<ll> s;
  // for (ll i = 0; i < n; i++)
  // {
  //  cin >> v[i];
  //  s.insert(v[i]);
  //  map[v[i]]++;
  // }
  // while (q-- > 0)
  // {
  //  ll l, r;
  //  cin >> l >> r;
  //  l--;
  //  map[a[l]]--;
  //  if (map[a[l]] == 0)
  //  {
  //   s.erase(s.find(a[l]));
  //  }
  //  map[r]++;
  //  s.insert(r);
  //  a[l] = r;
  //  cout << (ll)s.size() + 1ll << endl;
  // }
 }
}