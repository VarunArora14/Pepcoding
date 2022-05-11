// https://www.youtube.com/watch?v=m__4qg_G_gs&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=292
#include <iostream>
#include "stack"
#include "vector"
#include "climits"
using namespace std;

class node
{
public:
  int val;
  vector<node *> children;
};

void disp(node *roo)
{
  cout << roo->val << " -> ";
  for (auto i : roo->children)
  {
    cout << i->val << ", ";
  }
  cout << "\n";
  for (auto child : roo->children)
  {
    disp(child);
  }
}

node *insert(int a[], int n)
{
  stack<node *> s;
  node *roo = nullptr;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == -1)
    {
      s.pop();
      // simply pop the value
    }
    else
    {
      node *temp = new node;
      temp->val = a[i];
      if (s.empty())
      {
        roo = temp;
      }
      else
      {
        s.top()->children.push_back(temp);
      }
      s.push(temp);
    }
  }
  return roo;
}

int tree_floor, tree_ceil;

void ceil_floor(node *roo, int data)
{
  // ceil condition is ele just greater than data but smallest amongst the larger ones
  // floor is smaller than data but largest amongst the smaller values
  if (roo->val > data)
  {
    tree_ceil = min(tree_ceil, roo->val);
    // if roo->val is smaller than ceil, change the ceil
  }
  if (roo->val < data)
  {
    tree_floor = max(tree_floor, roo->val);
    // if roo->val greater than floor, change the floor
  }
  for (auto i : roo->children)
    ceil_floor(i, data);
}

int main()
{
  int a[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
  int n = sizeof(a) / sizeof(a[0]);

  node *roo = insert(a, n);
  disp(roo);
  tree_floor = INT_MIN;
  tree_ceil = INT_MAX;
  cout << "\n";
  ceil_floor(roo, 50);
  if (tree_ceil == INT_MAX)
    cout << "tree ceil not found";
  else
    cout << tree_ceil << "\n";
  if (tree_floor == INT_MIN)
    cout << "tree floor not found";
  else
    cout << tree_floor;
  return 0;
}

// Given a tree, find the ceil and floor of the tree
// Follow the same way where you go through a preorder traversal with ceil and floor variables
// and then check in preorder the ceil and floor conditions
// if ceil not there as max value, then return +inf, for floor if smallest ele then return -inf(base values)
