// https://www.youtube.com/watch?v=TKqOZ3tp1D8&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=297
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

int max_node = 0;
int max_sum = INT_MIN;
// creating these outside makes it easy to not lose their values
int max_subtree(node *roo)
{
  // pass the root and then traverse all, in the loop, return the sum of the lowest subtree

  // The case for leaf when we find the first ele
  int sum = 0;
  // the sum to be returned
  for (auto i : roo->children)
  {
    int csum = max_subtree(i);
    // note that we have to add the sum of all child nodes of the subtree and don't be selective based on higher valued
    // some nodes, leaving others
    sum += csum;
    // add the sum of children and then compare with prev max_sum
  }
  // add roo->val to sum as it is also part of the subtree
  sum += roo->val;
  // the reason why it is postorder is bcos a subtree needs to be sum of itself and it's children and not just that node
  // considered
  if (max_sum < sum)
  {
    // if sum greater than max_sum, then we have found the max sum node and store it's value and update the max_sum
    max_sum = sum;
    max_node = roo->val;
  }
  return sum;
}
// In this we have to calculate something but we are returning something lese. We return the sum of children of each node
// but have to find the max sum of subtree. We return something else and calculate something else

int main()
{
  int a[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
  int n = sizeof(a) / sizeof(a[0]);

  node *roo = insert(a, n);
  disp(roo);
  max_subtree(roo);
  cout << "max_sum is " << max_sum << " and node is " << max_node;
  return 0;
}
/*
Here we will find the maximum subtree meaning the subtree with max value.

The way to do this is traverse the nodes keeping 2 variables max_node and max_sum where max_sum stores the
value of the max sum and max_node stores the value of the node whose subtree has the max sum.
This will follow travel and change strategy where you have 2 variables as global variables declared them outisde
*/