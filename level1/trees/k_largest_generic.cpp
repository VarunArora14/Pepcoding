// https://www.youtube.com/watch?v=DmAGEAeYhJs&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=296
#include <iostream>
#include "vector"
#include "stack"
#include "climits"
using namespace std;
// Here we will use the ceil floor method, which takes O(n*k) where in each traversal
// find the floor of max value k times
// Look at the bottom for optimized one using priority queue for k*logn time and n space

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

void kth_largest(node *roo, int k)
{
  tree_floor = INT_MIN;
  int factor = INT_MAX;
  for (int i = 0; i < k; i++)
  {
    ceil_floor(roo, factor);
    // start by passing inf as data and then it returns the largest ele as the floor
    // then the tree_floor becomes the largest ele so make factor as tree_floor for 2nd largest
    // ele so on till k
    factor = tree_floor;
    // reset floor
    tree_floor = INT_MIN;
    ;
  }
}

int main()
{

  return 0;
}
/*
Above we use
The approach to solving would be to build a max heap of size O(n) with priority queue
which stores the largest ele on the top and Use the extract Max k times to get k max elements
from the max heap
Time is O(klogn) where logn is time to find the max and k the time to do it for kth largest
Reference: https://www.techiedelight.com/find-kth-largest-element-array/

https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
Priority queues have largest ele on the top so you can simply create one, push all the ele in it
let's say in preorder way and then pop k times where pop() pops the top most ele which is also
the largest ele which is pq.top()
*/