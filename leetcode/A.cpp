#include <bits/stdc++.h>
#define ll long long
using namespace std;

int bin[35];
int nodes[10000];
vector<bool> isnode(10000, false);

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
  vector<vector<int>> ans;
  queue<TreeNode *> q;
  if (root == NULL)
  {
    return {{}};
  }
  else
  {
    q.push(root);
  }
  while (!q.empty())
  {
    ans.push_back(vector<int>());
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
      TreeNode *curr = q.front();
      q.pop();
      ans.back().push_back(curr->val);
      if (curr->left)
      {
        q.push(curr->left);
      }
      if (curr->right)
      {
        q.push(curr->right);
      }
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int longestValidParentheses(string s)
{
  int n = s.length();
  if (n == 0)
  {
    return 0;
  }
  int maxans = 0;
  int dp[n];
  for (int i = 0; i < n; i++)
  {
    dp[i] = 0;
  }
  for (int i = 1; i < n; i++)
  {
    if (s[i] == ')')
    {
      if (s[i - 1] == '(')
      {
        dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
      }
      else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
      {
        dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
      }
      maxans = max(maxans, dp[i]);
    }
  }
  return maxans;
}

int dectobi(int num)
{
  int id = 0;
  while (num > 0)
  {
    bin[id++] = num % 2;
    num /= 2;
  }
  return id;
}

int getlsb(int a, int b)
{
  int num = a | b;
  int id = dectobi(num);
  int count = 0;
  for (int i = 0; i <= id; i++)
  {
    if (bin[i] == 1)
    {
      break;
    }
    else if (bin[i] == 0)
    {
      count++;
    }
  }
  return count;
}

// void inorder(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second){
//     if(!root) return;
//     inorder(root->left,prev,first,second);
//     if(prev && prev->val>root->val){
//         if(!first){
//             first=prev;
//         }
//         second=root;
//     }
//     prev=root;
//     inorder(root->right,prev,first,second);
// }
// void recoverTree(TreeNode* root) {
//     TreeNode* prev=NULL, *first=NULL, *second=NULL;
//     inorder(root,prev,first,second);
//     swap(first->val, second->val);
//     return;
// }

ll binpow(ll a, ll b)
{
  ll res = 1;
  while (b > 0)
  {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

ll pow(ll a, ll b)
{
  if (b == 0)
  {
    return 1;
  }
  return a * pow(a, b - 1);
}

void bstarr(TreeNode *root, int i, int &size)
{
  if (root == nullptr)
  {
    return;
  }
  nodes[i] = root->val;
  isnode[i] = true;
  size++;
  bstarr(root->left, 2 * i + 1, size);
  bstarr(root->right, 2 * i + 2, size);
}

int main()
{
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);
  // root->left->left = new TreeNode(2);
  // root->left->right = new TreeNode(4);
  // root->left->left->left = new TreeNode(1);

  int size = 0;
  bstarr(root, 0, size);
  for (auto i : isnode)
  {
    cout << i << " ";
  }
  cout << endl
       << size << endl;
  priority_queue<int, vector<int>, greater<int>> pq;
  int i = 0;
  while (i <= size + 1)
  {
    if (isnode[i])
    {
      pq.push(nodes[i]);
    }
    i++;
  }
  int k = 3;
  while (k > 1)
  {
    pq.pop();
    k--;
  }
  cout << pq.top() << endl;
}
