#include <bits/stdc++.h>

using namespace std;

// * Definition for a binary tree node.
struct TreeNode
{
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main()
{
 priority_queue<int> q;
 int n;
 cin >> n;
 for (int i = 0; i < n; i++)
 {
  int data;
  cin >> data;
  q.push(data);
 }
 while (!q.empty())
 {
  cout << q.top() << " ";
  q.pop();
 }
 return 0;
}

TreeNode *pruneTree(TreeNode *root)
{
 if (root == nullptr)
 {
  return nullptr;
 }
 TreeNode *l = pruneTree(root->left);
 root->left = l;
 TreeNode *r = pruneTree(root->right);
 root->right = r;
 if (root->val == 0 && root->left == nullptr && root->right == nullptr)
 {
  root = nullptr;
 }
 return root;
}